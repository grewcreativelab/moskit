// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "IXRTrackingSystem.h"
//#include "MoskitGoogleAnalytics.h"
#include "MoskitReceiver.h"
#include "MoskitVideoController.h"
#include "MSThreadManager.h"
#include "StereoLayerManager.h"
#include "Runtime/HeadMountedDisplay/Public/HeadMountedDisplayFunctionLibrary.h"
#include "IHeadMountedDisplay.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/HeadMountedDisplay/Public/MotionControllerComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Camera/CameraActor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "UObjectIterator.h"


#include "PlatformFilemanager.h"
#include "PlatformFile.h"
#include "Engine/World.h"
#include "Engine.h"
#include "Paths.h"
#include "CLZF2.h"
#include "AllowWindowsPlatformTypes.h" 
#include <fstream>
#include <list>
#include "CollisionQueryParams.h"
#include "moskit.pb.h"
#include "HideWindowsPlatformTypes.h"
#include "GameFramework/Character.h"

#include "CoreMinimal.h"

/**
 * 
 */
class MOSKIT_API MoskitManager
{
	//=======================================================================================
	// singleton instance
	//=======================================================================================
private:
	MoskitManager();

	~MoskitManager();
public:
	static MoskitManager* Get();

	//AMoskitGoogleAnalytics* m_pMoskitGoogleAnalytics;

	MoskitReceiver*		m_MoskitReceiver;

	MSThreadManager*		SceneThreadMgr;

	MoskitVideoController*	m_pVideoController;

	FString m_lpParamOutputFileName;

	FString m_lpParamOutputFilePath;

	FString m_strFileName;

	bool m_bisReceiver;

	//=======================================================================================
	// scene
	//=======================================================================================
	float m_fScaleRatio;

	int32	FrameCount;

	int		iaccumCount;

	UWorld* m_pWorld;

	AActor*	m_pPlayerActor;

	APlayerController* m_pPlayerController;
	//=======================================================================================
	// camera
	//=======================================================================================
	float	fDistance;

	float	magnitude;

	FQuat	lastRotation;

	FVector	vAxis;

	FTransform m_CameraTransfmrom;

	FVector vPos;

	FQuat qQuat;

	float fFloorToCameraHeight;

	//=======================================================================================
	// compress
	//=======================================================================================
	const int MAX_GAMEOBJ_CNT = 500;

	MSAnalyzer::MOSKIT_UNITY_LIB::Scene m_Scene;

	MSAnalyzer::MOSKIT_UNITY_LIB::ArrayScene	array_scene;

	MSAnalyzer::MOSKIT_UNITY_LIB::Vector3	vHitPoint;


	//=======================================================================================
	// func.. ( beginPlay, Tick, EndPlay )
	//=======================================================================================
	void LogMessage(int errorCode, FString Msg);

	bool Initalized();

	void Setup(FString strOutputFilePath, AActor* _pPlayer, float fHeight, bool bisConnectedToHardware);

	void Start();

	void Run(float DeltaTime, bool bisActive);

	void End();
	//=======================================================================================
	// 
	//=======================================================================================
	MSAnalyzer::MOSKIT_UNITY_LIB::Scene AddNode(float DeltaTime);

	MSAnalyzer::MOSKIT_UNITY_LIB::Time	MakeTimeStructure(float DeltaTime);

	MSAnalyzer::MOSKIT_UNITY_LIB::MainCamera MakeCamera(float DeltaTime);

	void MakeGameObject(MSAnalyzer::MOSKIT_UNITY_LIB::Scene& insert_scene, float DeltaTime);

	MSAnalyzer::MOSKIT_UNITY_LIB::Transform	MakeTransform(FTransform transf_, float DeltaTime);

	void	MakeController(MSAnalyzer::MOSKIT_UNITY_LIB::Scene& insert_scene, float DeltaTime);

	void	MakeComponent(AActor* obj, MSAnalyzer::MOSKIT_UNITY_LIB::MainCamera& output);

	void	MakeComponent(AActor* obj, MSAnalyzer::MOSKIT_UNITY_LIB::Controller& output);

	void	MakeComponent(AActor* obj, MSAnalyzer::MOSKIT_UNITY_LIB::GameObject& output);

	MSAnalyzer::MOSKIT_UNITY_LIB::Vector3	hitPoint(FTransform _transform);

	FVector		AngularVelocity(float DeltaTime);

	bool GetActiveComponent(AActor* pPlayerContorller);
};