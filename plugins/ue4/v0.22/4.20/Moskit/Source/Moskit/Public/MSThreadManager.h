// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CLZF2.h"
#include "moskit.pb.h"

#include "PlatformProcess.h"
#include "Event.h"
#include "Runnable.h"
#include "RunnableThread.h"
#include "ThreadSafeBool.h"
#include <fstream>
#include <list>

#include "CoreMinimal.h"

/**
 * 
 */
class MOSKIT_API MSThreadManager : public FRunnable
{
public:
	MSThreadManager(int buffer1Cnt, int buffer2Cnt, FString _lpParamOutputFilePath, FString _strFileName);
	~MSThreadManager();
private:
	
	//Thread to run the worker FRunnable on
	FRunnableThread * Thread;

	FCriticalSection m_mutex;

	
	FEvent * m_semaphore;
public:
	const int MAX_GAMEOBJ_CNT = 500;

	FThreadSafeBool m_Kill;

	FThreadSafeBool m_Pause;

	FString m_lpParamOutputFilePath;

	FString m_strFileName;

	bool bisStart;

	MSAnalyzer::MOSKIT_UNITY_LIB::ArrayScene* m_pCurr;

	MSAnalyzer::MOSKIT_UNITY_LIB::ArrayScene* m_pPrev;

	MSAnalyzer::MOSKIT_UNITY_LIB::ArrayScene m_Buffer1;

	MSAnalyzer::MOSKIT_UNITY_LIB::ArrayScene m_Buffer2;

	int m_iBuffer1Cnt;

	int m_iBuffer2Cnt;

	void Release();
	//Use this method to kill the thread!!
	void EnsureCompletion();

	void ContinueThread();
	
	//FRunnable interface.
	
	virtual bool Init();
	
	virtual bool Init(FString lpParamOutputFilePath, FString strFileName);

	virtual uint32 Run();
	
	virtual void Stop();
	void WriteFile(MSAnalyzer::MOSKIT_UNITY_LIB::ArrayScene* pBuffer);

	void AddGameObjectDataMng(MSAnalyzer::MOSKIT_UNITY_LIB::Scene* _array_scene, int& gameobjNodeCount);
	/*void WriteFile(MSAnalyzer::MOSKIT_UNITY_LIB::ArrayScene* pBuffer);

	void AddGameObjectDataMng(MSAnalyzer::MOSKIT_UNITY_LIB::ArrayScene& _array_scene, int& gameobjNodeCount);*/

	void LastbuffProc();

	int iaccumCount;

};
