// Fill out your copyright notice in the Description page of Project Settings.

#include "MoskitVideoController.h"


HANDLE MoskitVideoController::ExcuteProgram(FString FileName, FString lpParameters)
{
	//try
	//{
	SHELLEXECUTEINFOW execinfo;

	// 실행을 위해 구조체 세트
	ZeroMemory(&execinfo, sizeof(SHELLEXECUTEINFO));
	execinfo.cbSize = sizeof(SHELLEXECUTEINFO);
	execinfo.lpVerb = L"open";
	execinfo.lpFile = *FileName;
	execinfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	execinfo.nShow = SW_SHOWMINIMIZED;
	execinfo.lpParameters = *lpParameters;
	// 프로그램을 실행한다.
	if (!ShellExecuteExW(&execinfo)) return NULL;

	return execinfo.hProcess;  // Process handle 리턴, 향후 TerminateProcess 에서 사용하기 위함
							   /*}
							   catch (const std::exception&)
							   {
							   ;
							   }*/
}
void MoskitVideoController::Initalized(FString _lpParamOutputFilePath, FString _lpParamOutputFileName)
{
	m_strGamePluginDir = FPaths::GamePluginsDir();
	m_lpParamOutputFilePath = _lpParamOutputFilePath;
	m_lpParamOutputFileName = _lpParamOutputFileName;
}
void MoskitVideoController::Start()
{
	bisStart = true;
	HWND hWndThis = GetActiveWindow();
	hMyHandle = hWndThis;
	WCHAR sbWinText[255];
	GetWindowTextW(hWndThis, sbWinText, 0xFF);
	FString window = FString(sbWinText);
	//shellExecute FilePath
	FString file = m_strGamePluginDir + "Moskit\\VideoTool\\MOSKIT_ScreenTool.exe";
	//lpParameters
	FString parameter = window + "#" + m_lpParamOutputFilePath + "#" + m_lpParamOutputFileName;

	HANDLE result = ExcuteProgram(file, parameter);
	if (result == NULL)
		printf("error!");
	while (hWNdExecutor == 0)
		hWNdExecutor = FindWindowW(NULL, L"MOSKIT_ScreenTool");
}
void MoskitVideoController::Stop()
{
	bisStart = false;
	SendMessageW(hWNdExecutor, WM_ENDREC, 0, (LPARAM)hMyHandle);
	hWNdExecutor = 0;
	hMyHandle = 0;
}
MoskitVideoController::MoskitVideoController()
{
	bisStart = false;
	hWNdExecutor = 0;
	hMyHandle = 0;
}

MoskitVideoController::~MoskitVideoController()
{
}
