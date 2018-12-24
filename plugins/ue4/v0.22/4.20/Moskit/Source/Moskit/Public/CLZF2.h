// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <string>
#include <vector>
/**
 * 
 */
class MOSKIT_API CLZF2
{
private:
	const static unsigned int HLOG = 14;
	const static unsigned int HSIZE = 16384;
	const static unsigned int MAX_LIT = 32;
	const static unsigned int MAX_OFF = 8192;
	const static unsigned int MAX_REF = 264;
	std::vector<long> HashTable;
public:
	std::vector<char>	outputBytes;
	std::vector<char>	Compress(std::vector<char> inputBytes);
	std::vector<char>	Decompress(std::vector<char> inputBytes);
	int		lzf_compress(std::vector<char> input, std::vector<char> &output);
	int		lzf_Decompress(std::vector<char> input, std::vector<char> &output);
	CLZF2();
	~CLZF2();
};
