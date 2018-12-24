// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#define BUFLEN 512
#define PORT 12345

//#include "AllowWindowsPlatformTypes.h"
//#include <stdarg.h>
//#include "HideWindowsPlatformTypes.h"

#include "SharedPointer.h"
#include "SocketSubsystem.h"
#include "Sockets.h"
#include "Networking.h"
#include "CoreMinimal.h"
#include "Engine.h"
#include "PlatformProcess.h"
#include "Event.h"
#include "Runnable.h"
#include "RunnableThread.h"
#include "ThreadSafeBool.h"
//**
// * 
// */
class MOSKIT_API MoskitReceiver : public FRunnable
{
private:
	//Thread to run the worker FRunnable on
	FRunnableThread * Thread;

	FCriticalSection m_mutex;

	FEvent * m_semaphore;

	FSocket* Socket;

	uint8 data[BUFLEN];

	const int port = 12345;

public:
	//Use this method to kill the thread!!


	void EnsureCompletion();

	void ContinueThread();

	virtual bool Init();

	virtual uint32 Run();

	virtual void Stop();

	FThreadSafeBool m_Kill;

	FThreadSafeBool m_Pause;

	void InitMOSKITHWReceiver();

	void GetMOSKITHWReceiverData(bool* _check, char* strMACID, int* nTimeStamp, float* fAccelX, float*fAccelY, float*fAccelZ, float* fGyroX, float* fGyroY, float* fGyroZ);

	void DestroyMOSKITHWReceiver();
	bool	m_bisConnected;
	char*	m_strMACID;
	int	  m_nTimeStamp;
	float m_fAccelX;
	float m_fAccelY;
	float m_fAccelZ;
	float m_fGyroX;
	float m_fGyroY;
	float m_fGyroZ;
	MoskitReceiver();

	~MoskitReceiver();

};
