// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Paths.h"
#include "AllowWindowsPlatformTypes.h"
#include "Windows.h"
#include "shellapi.h"
#include "HideWindowsPlatformTypes.h"

#include "CoreMinimal.h"

/**
*
*/
class MOSKIT_API MoskitVideoController
{
public:

	MoskitVideoController();

	~MoskitVideoController();

	FString m_strGamePluginDir;

	FString m_lpParamOutputFileName;

	FString m_lpParamOutputFilePath;

	HWND hWNdExecutor;

	HWND hMyHandle;

	bool bisStart;

	void Initalized(FString _lpParamOutputFilePath, FString _lpParamOutputFileName);

	void Start();

	void Stop();

private:
	const int WM_ENDREC = 0x0401;

	HANDLE ExcuteProgram(FString FileName, FString lpParameters);

};
