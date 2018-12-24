// Fill out your copyright notice in the Description page of Project Settings.

#include "MSThreadManager.h"

MSThreadManager::MSThreadManager(int buffer1Cnt, int buffer2Cnt, FString _lpParamOutputFilePath, FString _strFileName)
{
	m_iBuffer1Cnt = buffer1Cnt;

	m_iBuffer2Cnt = buffer2Cnt;

	m_lpParamOutputFilePath = _lpParamOutputFilePath;

	m_strFileName = _strFileName;

	m_pCurr = &m_Buffer1;
	m_pPrev = NULL;

	m_Kill = false;
	m_Pause = true;
	bisStart = false;
	m_semaphore = FGenericPlatformProcess::GetSynchEventFromPool(false);

	Thread = FRunnableThread::Create(this, TEXT("MSThreadManager"), 0, TPri_Lowest);
}

MSThreadManager::~MSThreadManager()
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
bool MSThreadManager::Init()
{

	//Init the Data
	/*
	m_Buffer1 = new MSAnalyzer::MOSKIT_UNITY_LIB::ArrayScene();
	m_Buffer2 = new MSAnalyzer::MOSKIT_UNITY_LIB::ArrayScene();*/

	//m_pCurr = m_Buffer1;//NULL;
	//m_pPrev = NULL;
	return true;
}
bool MSThreadManager::Init(FString lpParamOutputFilePath, FString strFileName)
{
	m_lpParamOutputFilePath = lpParamOutputFilePath;
	m_strFileName = strFileName;

	//Init the Data 
	//m_iBuffer1Cnt = 0;
	//m_iBuffer2Cnt = 0;
	m_pCurr = &m_Buffer1;//NULL;
	m_pPrev = NULL;
	return true;
}

uint32 MSThreadManager::Run()
{
	//FPlatformProcess::Sleep(0.03);


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

			WriteFile(m_pPrev);

			m_mutex.Unlock();

			m_Pause = true;



		}

	}
	return 0;
}

void MSThreadManager::WriteFile(MSAnalyzer::MOSKIT_UNITY_LIB::ArrayScene* pBuffer)
{
	CLZF2 comp_ob;

	int bufSize = pBuffer->ByteSize();

	if (bufSize == 0)
	{
		return;
	}
	char* outputBuf = new char[bufSize];

	std::vector<char> databuff;

	pBuffer->SerializeToArray(outputBuf, bufSize);

	for (int i = 0; i < bufSize; i++)
	{
		databuff.push_back(outputBuf[i]);
	}

	std::vector<char> comp_Buff = comp_ob.Compress(databuff);

	std::ofstream ost2;

	ost2.open(*(m_lpParamOutputFilePath + m_strFileName), std::ios::out | std::ios::app | std::ios::binary);

	ost2.write(reinterpret_cast<char*>(comp_Buff.data()), comp_Buff.size());

	ost2.write("#@a#@", 5);

	ost2.close();

	databuff.clear();

	delete[]outputBuf;

	pBuffer->Clear();

	if (pBuffer == &m_Buffer1)
		m_iBuffer1Cnt = 0;
	if (pBuffer == &m_Buffer2)
		m_iBuffer2Cnt = 0;
}

void MSThreadManager::Stop()
{
	m_Kill = true; //Thread kill condition "while (!m_Kill){...}"
	m_Pause = false;

	if (m_semaphore)
	{
		//We shall signal "Trigger" the FEvent (in case the Thread is sleeping it shall wake up!!)
		m_semaphore->Trigger();
	}

}
void MSThreadManager::EnsureCompletion()
{
	Stop();

	if (Thread)
	{
		Thread->WaitForCompletion();
	}
}
void MSThreadManager::ContinueThread()
{
	m_Pause = false;

	if (m_semaphore)
	{
		//Here is a FEvent signal "Trigger()" -> it will wake up the thread.
		m_semaphore->Trigger();
	}
}
void MSThreadManager::AddGameObjectDataMng(MSAnalyzer::MOSKIT_UNITY_LIB::Scene* scene, int& gameobjNodeCount)
{
	m_mutex.Lock();

	if (m_iBuffer1Cnt > MAX_GAMEOBJ_CNT)
	{
		m_pPrev = &m_Buffer1;

		m_pCurr = &m_Buffer2;

		ContinueThread();
	}
	if (m_iBuffer2Cnt > MAX_GAMEOBJ_CNT)
	{
		m_pCurr = &m_Buffer1;

		m_pPrev = &m_Buffer2;

		ContinueThread();
	}
	*m_pCurr->mutable_list_scene()->Add() = *scene;

	if (m_pCurr == &m_Buffer1)
		m_iBuffer1Cnt += gameobjNodeCount;
	if (m_pCurr == &m_Buffer2)
		m_iBuffer2Cnt += gameobjNodeCount;

	m_mutex.Unlock();
}

//void MSThreadManager::AddGameObjectDataMng(MSAnalyzer::MOSKIT_UNITY_LIB::ArrayScene& _array_scene, int& gameobjNodeCount)
//{	
//	m_mutex.Lock();
//	for (auto iter = _array_scene.list_scene().begin(); iter != _array_scene.list_scene().end())
//	{
//		*iter = m_pCurr->add_list_scene();
//	}
//	
//	if(m_pCurr == &m_TBuffer1.Buffer)
//		m_TBuffer1.m_iBufferCount += gameobjNodeCount;
//	if(m_pCurr == &m_TBuffer2.Buffer)
//		m_TBuffer2.m_iBufferCount += gameobjNodeCount;
//
//	if (m_TBuffer1.m_iBufferCount > MAX_GAMEOBJ_CNT)
//	{
//		m_pCurr = &m_TBuffer1.Buffer;
//
//		m_pPrev = &m_TBuffer2.Buffer;
//
//		m_TBuffer1.m_iBufferCount = 0;
//
//		ContinueThread();
//	}
//	if (m_TBuffer2.m_iBufferCount > MAX_GAMEOBJ_CNT)
//	{
//		m_pPrev = &m_TBuffer1.Buffer;
//
//		m_pCurr = &m_TBuffer2.Buffer;
//
//		m_TBuffer2.m_iBufferCount = 0;
//
//		ContinueThread();
//	}		
//	m_mutex.Unlock();
//}

void MSThreadManager::LastbuffProc()
{
	if (!bisStart)
	{
		bisStart = true;

		if (m_pPrev != NULL)
			WriteFile(m_pPrev);
		else
			WriteFile(m_pCurr);

		m_Pause = true;

		Release();
	}
}
void MSThreadManager::Release()
{

}