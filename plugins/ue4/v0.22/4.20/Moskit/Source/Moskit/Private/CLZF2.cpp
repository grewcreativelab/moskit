// Fill out your copyright notice in the Description page of Project Settings.

#include "CLZF2.h"

std::vector<char>	CLZF2::Compress(std::vector<char> inputBytes)
{
	outputBytes.clear();
	int outputByteCountGuess = inputBytes.size() * 2;
	std::vector<char> tempBuffer;
	tempBuffer.clear();
	tempBuffer.resize(outputByteCountGuess);
	//tempBuffer.resize(outputByteCountGuess);
	int byteCount = lzf_compress(inputBytes, tempBuffer);
	while (byteCount == 0)
	{
		tempBuffer.clear();
		outputByteCountGuess *= 2;
		tempBuffer.resize(outputByteCountGuess);
		byteCount = lzf_compress(inputBytes, tempBuffer);
	}

	outputBytes.assign(tempBuffer.begin(), tempBuffer.begin() + byteCount);

	//copy src to dest
	return outputBytes;
}
std::vector<char>	CLZF2::Decompress(std::vector<char> inputBytes)
{
	outputBytes.clear();
	int outputByteCountGuess = inputBytes.size() * 2;
	std::vector<char> tempBuffer;
	tempBuffer.clear();
	tempBuffer.resize(outputByteCountGuess);
	//tempBuffer.resize(outputByteCountGuess);
	int byteCount = lzf_Decompress(inputBytes, tempBuffer);
	while (byteCount == 0)
	{
		tempBuffer.clear();
		outputByteCountGuess *= 2;
		tempBuffer.resize(outputByteCountGuess);
		byteCount = lzf_Decompress(inputBytes, tempBuffer);
	}
	outputBytes.assign(tempBuffer.begin(), tempBuffer.begin() + byteCount);

	return outputBytes;
}
int					CLZF2::lzf_compress(std::vector<char> input, std::vector<char>& output)
{

	unsigned int inputLength = input.size();
	unsigned int outputLength = output.size();

	//Array.Clear(HashTable, 0, (int)HSIZE);
	HashTable.clear();
	HashTable.resize(HSIZE, 0);
	/*for (int i = 0; i < HashTable.size(); i++)
	{
	HashTable[i] = 0;
	}*/

	long hslot;
	unsigned int iidx = 0;
	unsigned int oidx = 0;
	long reference;

	unsigned int hval = (unsigned int)(((input[iidx]) << 8) | input[iidx + 1]); // FRST(in_data, iidx);
	long off;
	int lit = 0;
	for (; ;)
	{
		if (iidx < inputLength - 2)
		{
			hval = (hval << 8) | input[iidx + 2];
			hslot = ((hval ^ (hval << 5)) >> (int)(((3 * 8 - HLOG)) - hval * 5) & (HSIZE - 1));
			reference = HashTable[hslot];
			HashTable[hslot] = (long)iidx;


			if ((off = iidx - reference - 1) < MAX_OFF
				&& iidx + 4 < inputLength
				&& reference > 0
				&& input[reference + 0] == input[iidx + 0]
				&& input[reference + 1] == input[iidx + 1]
				&& input[reference + 2] == input[iidx + 2]
				)
			{
				/* match found at *reference++ */
				unsigned int len = 2;
				unsigned int maxlen = (unsigned int)inputLength - iidx - len;
				maxlen = maxlen > MAX_REF ? MAX_REF : maxlen;

				if (oidx + lit + 1 + 3 >= outputLength)
					return 0;

				do
					len++;
				while (len < maxlen && input[reference + len] == input[iidx + len]);

				if (lit != 0)
				{
					output[oidx++] = (char)(lit - 1);
					lit = -lit;
					do
						output[oidx++] = input[iidx + lit];
					while ((++lit) != 0);
				}

				len -= 2;
				iidx++;

				if (len < 7)
				{
					output[oidx++] = (char)((off >> 8) + (len << 5));
				}
				else
				{
					output[oidx++] = (char)((off >> 8) + (7 << 5));
					output[oidx++] = (char)(len - 7);
				}

				output[oidx++] = (char)off;

				iidx += len - 1;
				hval = (unsigned int)(((input[iidx]) << 8) | input[iidx + 1]);

				hval = (hval << 8) | input[iidx + 2];
				HashTable[((hval ^ (hval << 5)) >> (int)(((3 * 8 - HLOG)) - hval * 5) & (HSIZE - 1))] = iidx;
				iidx++;

				hval = (hval << 8) | input[iidx + 2];
				HashTable[((hval ^ (hval << 5)) >> (int)(((3 * 8 - HLOG)) - hval * 5) & (HSIZE - 1))] = iidx;
				iidx++;
				continue;
			}
		}
		else if (iidx == inputLength)
			break;

		/* one more literal byte we must copy */
		lit++;
		iidx++;

		if (lit == MAX_LIT)
		{
			if (oidx + 1 + MAX_LIT >= outputLength)
				return 0;

			output[oidx++] = (char)(MAX_LIT - 1);
			lit = -lit;
			do
				output[oidx++] = input[iidx + lit];
			while ((++lit) != 0);
		}
	}

	if (lit != 0)
	{
		if (oidx + lit + 1 >= outputLength)
			return 0;

		output[oidx++] = (char)(lit - 1);
		lit = -lit;
		do
			output[oidx++] = input[iidx + lit];
		while ((++lit) != 0);
	}
	return (int)oidx;

}
int					CLZF2::lzf_Decompress(std::vector<char> input, std::vector<char> &output)
{
	unsigned int inputLength = input.size() + 1;
	unsigned int outputLength = output.size() + 1;
	unsigned int iidx = 0;
	unsigned int oidx = 0;

	do
	{
		unsigned int ctrl = input[iidx++];

		if (ctrl < (1 << 5)) /* literal run */
		{
			ctrl++;

			if (oidx + ctrl > outputLength)
			{
				//SET_ERRNO (E2BIG);
				return 0;
			}

			do
				output[oidx++] = input[iidx++];
			while ((--ctrl) != 0);
		}
		else /* back reference */
		{
			unsigned int len = ctrl >> 5;

			int reference = (int)(oidx - ((ctrl & 0x1f) << 8) - 1);

			if (len == 7)
				len += input[iidx++];

			reference -= input[iidx++];

			if (oidx + len + 2 > outputLength)
			{
				//SET_ERRNO (E2BIG);
				return 0;
			}

			if (reference < 0)
			{
				//SET_ERRNO (EINVAL);
				return 0;
			}

			output[oidx++] = output[reference++];
			output[oidx++] = output[reference++];

			do
				output[oidx++] = output[reference++];
			while ((--len) != 0);
		}
	} while (iidx < inputLength);

	return (int)oidx;
}
CLZF2::CLZF2()
{
}

CLZF2::~CLZF2()
{
}
