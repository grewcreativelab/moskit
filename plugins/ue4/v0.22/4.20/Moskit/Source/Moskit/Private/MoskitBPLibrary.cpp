// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MoskitBPLibrary.h"
#include "Moskit.h"

class MoskitManager* Instance = MoskitManager::Get();

UMoskitBPLibrary::UMoskitBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}
void UMoskitBPLibrary::SettingMoskit(FString strOutputFilePath, AActor* _pPlayer, float fHeight, bool bisConnectedToHardware)
{
	MoskitManager* instance = MoskitManager::Get();

	if (Instance != NULL)
	{
		Instance->Setup(strOutputFilePath, _pPlayer, fHeight, bisConnectedToHardware);

	}
}
void UMoskitBPLibrary::StartMoskit()
{

	/*if (iScaleRatio < 1)
	iScaleRatio = 1;*/
	MoskitManager* instance = MoskitManager::Get();

	if (Instance != NULL)
	{

		Instance->Start();
		//Instance->Start(strOutputFilePath, iScaleRatio);
	}
}


void UMoskitBPLibrary::EndMoskit()
{

	MoskitManager* instance = MoskitManager::Get();
	if (Instance != NULL)
	{
		Instance->End();
	}

}
void  UMoskitBPLibrary::RunMoskit(bool bisActive, float DeltaTime)
{
	MoskitManager* instance = MoskitManager::Get();

	if (Instance != NULL)
	{
		Instance->Run(DeltaTime, bisActive);
	}

}