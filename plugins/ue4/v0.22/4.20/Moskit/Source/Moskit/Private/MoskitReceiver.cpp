#include "MoskitReceiver.h"
//#define _NO_CRT_STDIO_INLINE
bool MoskitReceiver::Init()
{
	return true;
}
void MoskitReceiver::InitMOSKITHWReceiver()
{
	TSharedPtr<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	uint32 Addr;
	addr->GetIp(Addr);
	FIPv4Address address(Addr);
	//FSocket* pSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_DGram, TEXT("default"), false);
	Socket = FUdpSocketBuilder("moskitsocket")
		.AsNonBlocking()
		.AsReusable()
		.BoundToAddress(address)
		.BoundToPort(PORT)
		.Build();



	//	bool bisVaild;
	//	FIPv4Address ip();
	addr->SetAnyAddress();
	addr->SetPort(PORT);
	Socket->Bind(*addr);
	Socket->Connect(*addr);
	if (Socket != NULL) {
		Socket->Listen(1);
	}
	//	Socket = pSocket;


}
void MoskitReceiver::GetMOSKITHWReceiverData(bool* _check, char* strMACID, int* nTimeStamp, float* fAccelX, float*fAccelY, float*fAccelZ,
	float* fGyroX, float* fGyroY, float* fGyroZ)
{
	m_mutex.Lock();
	*_check = m_bisConnected;
	strMACID = m_strMACID;
	*nTimeStamp = m_nTimeStamp;
	*fAccelX = m_fAccelX;
	*fAccelY = m_fAccelY;
	*fAccelZ = m_fAccelZ;
	*fGyroX = m_fGyroX;
	*fGyroY = m_fGyroY;
	*fGyroZ = m_fGyroZ;

	ContinueThread();

	m_mutex.Unlock();
}
void MoskitReceiver::DestroyMOSKITHWReceiver()
{
	Socket->Close();
}
void MoskitReceiver::EnsureCompletion()
{
	Stop();

	if (Thread)
	{
		Thread->WaitForCompletion();
	}
}

void MoskitReceiver::ContinueThread()
{
	m_Pause = false;

	if (m_semaphore)
	{
		//Here is a FEvent signal "Trigger()" -> it will wake up the thread.
		m_semaphore->Trigger();
	}
}
void MoskitReceiver::Stop()
{
	m_Kill = true; //Thread kill condition "while (!m_Kill){...}"
	m_Pause = false;

	if (m_semaphore)
	{
		//We shall signal "Trigger" the FEvent (in case the Thread is sleeping it shall wake up!!)
		m_semaphore->Trigger();
	}

}

uint32 MoskitReceiver::Run()
{
	FPlatformProcess::Sleep(0.03);


	while (!m_Kill)
	{
		if (m_Pause)
		{
			//FEvent->Wait(); will "sleep" the thread until it will get a signal "Trigger()"
			m_semaphore->Wait();

			if (m_Kill)
			{
				return 0;
			}
		}
		else
		{

			m_mutex.Lock();
			//if (Socket)
			//{
			int32 bytes_read = 0;

			//TSharedPtr<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

			FString buf;

			memset(data, '\0', BUFLEN);

			if (Socket->Recv(data, BUFLEN, bytes_read))
			{
				UE_LOG(LogTemp, Warning, TEXT("PEND"));

				data[bytes_read] = 0;

				FString s((const char*)data);

				buf = s;
				//bool check = false;
				/*int nTimeStamp = 0;
				float fAccelX, fAccelY, fAccelZ = 0;
				float fGyroX, fGyroY, fGyroZ = 0;*/


				if (!buf.IsEmpty())
				{


					TArray<FString> arr;

					FString left;

					FString right;

					FString split = " ";

					while (buf.Split(split, &left, &right, ESearchCase::CaseSensitive, ESearchDir::FromStart))
					{
						arr.Add(left);

						buf = right;
					}
					// ¸¶Áö¸·²¨
					arr.Add(buf);

					m_strMACID = (char*)&arr[0].GetCharArray();

					m_nTimeStamp = FCString::Atoi(*arr[1]);

					m_fAccelX = FCString::Atof(*arr[2]);

					m_fAccelY = FCString::Atof(*arr[3]);

					m_fAccelZ = FCString::Atof(*arr[4]);

					m_fGyroX = FCString::Atof(*arr[5]);

					m_fGyroY = FCString::Atof(*arr[6]);

					m_fGyroZ = FCString::Atof(*arr[7]);

					m_bisConnected = true;


				}
				else
				{
					m_bisConnected = false;
				}
			}
			else
			{
				InitMOSKITHWReceiver();
			}
			//}


			m_mutex.Unlock();

			m_Pause = true;
		}

	}
	return 0;
}
MoskitReceiver::MoskitReceiver()
{
	m_Kill = false;
	m_Pause = true;

	m_semaphore = FGenericPlatformProcess::GetSynchEventFromPool(false);

	Thread = FRunnableThread::Create(this, TEXT("MoskitReceiver"), 0, TPri_Lowest);
}
MoskitReceiver::~MoskitReceiver()
{
	if (m_semaphore)
	{
		//Cleanup the FEvent
		FGenericPlatformProcess::ReturnSynchEventToPool(m_semaphore);
		m_semaphore = nullptr;
	}

	if (Thread)
	{
		//Cleanup the worker thread
		delete Thread;

		Thread = nullptr;
	}
}