// Fill out your copyright notice in the Description page of Project Settings.

#include "MoskitManager.h"

class MoskitManager* instance;

MoskitManager::~MoskitManager()
{

}
void MoskitManager::Setup(FString strOutputFilePath, AActor* _pPlayer, float fHeight, bool bisConnectedToHardware)
{
	FDateTime now = FDateTime::Now();
	int day = now.GetDay();
	int month = now.GetMonth();
	int year = now.GetYear();
	int hour = now.GetHour();
	int min = now.GetMinute();
	int sec = now.GetSecond();
	m_strFileName =
		"moskit_src_"
		+ FString::FromInt(month)
		+ "-"
		+ FString::FromInt(day)
		+ "-"
		+ FString::FromInt(year)
		+ " "
		+ FString::FromInt(hour)
		+ ";"
		+ FString::FromInt(min)
		+ ";"
		+ FString::FromInt(sec)
		+ ".bin";
	m_lpParamOutputFileName =
		"moskit_video_"
		+ FString::FromInt(month)
		+ "-"
		+ FString::FromInt(day)
		+ "-"
		+ FString::FromInt(year)
		+ " "
		+ FString::FromInt(hour)
		+ ";"
		+ FString::FromInt(min)
		+ ";"
		+ FString::FromInt(sec)
		+ ".avi";
	if (strOutputFilePath.IsEmpty())
		strOutputFilePath = FPaths::ProjectDir();

	bool blastChar = true;
	blastChar = strOutputFilePath.EndsWith("/");
	if (!blastChar)
	{
		blastChar = strOutputFilePath.EndsWith("\\");
		if (!blastChar)
		{
			LogMessage(2, "warning, filepath check off");
			strOutputFilePath += TEXT("/");
		}
	}
	m_lpParamOutputFilePath = (strOutputFilePath).Replace(L"/", L"\\");

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString dir = m_lpParamOutputFilePath;

	dir.RemoveAt(dir.Len() - 1, 1);
	if (!PlatformFile.DirectoryExists(*m_lpParamOutputFilePath))
	{
		PlatformFile.CreateDirectory(*m_lpParamOutputFilePath);
		if (!PlatformFile.DirectoryExists(*m_lpParamOutputFilePath))
		{

			LogMessage(0, "error, filePath : " + dir + " , exit plugin");
		}
	}

	GetActiveComponent(_pPlayer);

	fFloorToCameraHeight = fHeight;

	m_bisReceiver = bisConnectedToHardware;
	if (m_bisReceiver)
	{
		LogMessage(2, "warning, is used hardware ?");
	}
	fDistance = WORLD_MAX;

	FrameCount = 1;

	iaccumCount = 0;

	magnitude = 0;

}
MoskitManager* MoskitManager::Get() {
	if (instance == NULL) {
		instance = new MoskitManager();
	}
	return instance;
}
MoskitManager::MoskitManager()
{
	//m_pMoskitGoogleAnalytics = NewObject<AMoskitGoogleAnalytics>();

	array_scene = MSAnalyzer::MOSKIT_UNITY_LIB::ArrayScene();

	vHitPoint = MSAnalyzer::MOSKIT_UNITY_LIB::Vector3();

	m_pVideoController = nullptr;

	m_MoskitReceiver = nullptr;

	SceneThreadMgr = nullptr;

}
bool MoskitManager::Initalized()
{
	m_pVideoController = new MoskitVideoController();

	m_pVideoController->Initalized(m_lpParamOutputFilePath, m_lpParamOutputFileName);

	if (m_bisReceiver)
	{
		m_MoskitReceiver = new MoskitReceiver();
	}
	SceneThreadMgr = new MSThreadManager(0, 0, m_lpParamOutputFilePath, m_strFileName);
	return true;
}
void MoskitManager::Start()
{
	if (Initalized())
	{
		m_pVideoController->Start();

		//m_pMoskitGoogleAnalytics->Post();

		if (m_bisReceiver)
		{
			m_MoskitReceiver->InitMOSKITHWReceiver();
		}

		if (GEngine->XRSystem.Get()->GetHMDDevice()->IsHMDConnected()
			&& GEngine->XRSystem.Get()->GetHMDDevice()->IsHMDEnabled())
		{
			int32 inctanceID = GEngine->XRSystem.Get()->HMDDeviceId;
			GEngine->XRSystem.Get()->GetCurrentPose(inctanceID,qQuat, vPos);

			lastRotation = qQuat;
		}
	}

	LogMessage(1, "moskitPlugin start completed");
}

void MoskitManager::End()
{
	//Video

	if (m_pVideoController->bisStart == true)
	{
		m_pVideoController->Stop();
		delete m_pVideoController;

		m_pVideoController = nullptr;
	}

	//thread

	if (SceneThreadMgr != nullptr)
	{
		SceneThreadMgr->LastbuffProc();

		SceneThreadMgr->EnsureCompletion();

		delete SceneThreadMgr;

		SceneThreadMgr = nullptr;
	}
	//hardware
	if (m_bisReceiver)
	{
		if (m_MoskitReceiver != nullptr)
		{
			m_MoskitReceiver->DestroyMOSKITHWReceiver();

			m_MoskitReceiver->EnsureCompletion();

			delete m_MoskitReceiver;

			m_MoskitReceiver = nullptr;
		}
	}
	LogMessage(1, "moskitPlugin end completed");
}
void MoskitManager::Run(float DeltaTime, bool bisActive)
{

	if (bisActive)
	{
		int32 inctanceID = GEngine->XRSystem.Get()->HMDDeviceId;
		GEngine->XRSystem.Get()->GetCurrentPose(inctanceID, qQuat, vPos);

		FQuat deltaRotation = (m_CameraTransfmrom.GetRotation() * (lastRotation.Inverse()));

		deltaRotation.ToAxisAndAngle(vAxis, magnitude);

		lastRotation = qQuat;

		MSAnalyzer::MOSKIT_UNITY_LIB::Scene  scene = AddNode(DeltaTime);

		int godcnt = scene.list_gameobject_size();

		SceneThreadMgr->AddGameObjectDataMng(&scene, godcnt);
	}
	FrameCount++;
}

MSAnalyzer::MOSKIT_UNITY_LIB::Scene  MoskitManager::AddNode(float DeltaTime)
{
	UGameUserSettings* userSetting = UGameUserSettings::GetGameUserSettings();

	MSAnalyzer::MOSKIT_UNITY_LIB::Scene  ret;

	MSAnalyzer::MOSKIT_UNITY_LIB::AnalysisBuffer buff;
	if (m_bisReceiver)
	{
		bool check;
		char* strMACID = "";
		int nTimeStamp;
		float fAccelX, fAccelY, fAccelZ;
		float  fGyroX, fGyroY, fGyroZ;

		m_MoskitReceiver->GetMOSKITHWReceiverData(&check, strMACID, &nTimeStamp, &fAccelX, &fAccelY, &fAccelZ, &fGyroX, &fGyroY, &fGyroZ);

		if (check)
		{
			MSAnalyzer::MOSKIT_UNITY_LIB::Vector3 vAccel(fAccelX, fAccelY, fAccelZ);

			MSAnalyzer::MOSKIT_UNITY_LIB::Vector3 vGyro(fGyroX, fGyroY, fGyroZ);

			buff.add_list_string(strMACID);

			buff.add_list_int(nTimeStamp);

			*buff.add_list_vector3() = vAccel;

			*buff.add_list_vector3() = vGyro;
		}
		else
		{
			LogMessage(2, "hardware is not connected");
		}
	}
	buff.add_list_float(fFloorToCameraHeight);
	std::string strIndicate = "UE4";

	ret.set_strindicate(strIndicate);
	ret.set_fscaleratio(m_fScaleRatio);
	*ret.mutable_time() = MakeTimeStructure(DeltaTime);
	*ret.mutable_camera() = MakeCamera(DeltaTime);
	ret.set_bvsync(userSetting->bUseVSync);
	*ret.mutable_analysis_buffer() = buff;

	MakeController(ret, DeltaTime);
	MakeGameObject(ret, DeltaTime);

	//list_scene.push_back(*insert_scene);
	return ret;
}

MSAnalyzer::MOSKIT_UNITY_LIB::Time  MoskitManager::MakeTimeStructure(float DeltaTime)
{
	MSAnalyzer::MOSKIT_UNITY_LIB::Time time;
	time = MSAnalyzer::MOSKIT_UNITY_LIB::Time();
	time.set_deltatime(DeltaTime);
	time.set_framecount(FrameCount);
	time.set_time(m_pWorld->GetRealTimeSeconds());
	return time;
}

MSAnalyzer::MOSKIT_UNITY_LIB::MainCamera  MoskitManager::MakeCamera(float DeltaTime)
{
	MSAnalyzer::MOSKIT_UNITY_LIB::MainCamera insert_cam;
	insert_cam = MSAnalyzer::MOSKIT_UNITY_LIB::MainCamera();

	float fIPD = 0;
	float fFOV = 0;

	float vfov = 0;
	float hfov = 0;
	FVector vPos;

	FQuat qQuat;
	std::string strName;

	std::string strTag;

	if (GEngine && GEngine->XRSystem.IsValid() && m_pWorld && m_pWorld->WorldType != EWorldType::Editor)
	{
		IXRTrackingSystem* XRSystem = GEngine->XRSystem.Get();

		//switch (HMDType)
		//{
		//case EHMDDeviceType::DT_OculusRift:
		//	strName = "DT_OculusRift";
		//	break;
		//case EHMDDeviceType::DT_Morpheus:
		//	strName = "DT_Morpheus";
		//	break;
		//case EHMDDeviceType::DT_ES2GenericStereoMesh:
		//	strName = "DT_ES2GenericStereoMesh";
		//	break;
		//case EHMDDeviceType::DT_SteamVR:
		//	strName = "DT_SteamVR";
		//	break;
		//case EHMDDeviceType::DT_GearVR:
		//	strName = "DT_GearVR";
		//	break;
		//case EHMDDeviceType::DT_GoogleVR:
		//	strName = "DT_GoogleVR";
		//	break;
		//default:
		//	strName = "HMDevice";
		//	break;
		//}
		strName = "HMDevice";
		//GEngine->XRSystem.Get()->GetHMDDevice()->GetCurrentOrientationAndPosition(qQuat, vPos);
		int32 hmdeviceid = GEngine->XRSystem.Get()->HMDDeviceId;
		GEngine->XRSystem.Get()->GetCurrentPose(hmdeviceid, qQuat, vPos);
		fIPD = GEngine->XRSystem.Get()->GetHMDDevice()->GetInterpupillaryDistance() * 1000.0f;
		GEngine->XRSystem.Get()->GetHMDDevice()->GetFieldOfView(hfov, vfov);
		fFOV = vfov;
	}
	else
	{
		strName = "HMDevice";
		strTag = "strTag";
		fIPD = 64;
		fFOV = 110;
	}

	insert_cam.set_name(strName);
	insert_cam.set_active(true);
	insert_cam.set_layer(0);
	insert_cam.set_instanceid(m_pPlayerController->PlayerCameraManager->GetUniqueID());
	insert_cam.set_fieldofview(fFOV);
	insert_cam.set_fipd(fIPD);
	insert_cam.set_tag(strTag);

	MakeComponent(m_pPlayerController->PlayerCameraManager, insert_cam);

	*insert_cam.mutable_transform() = MakeTransform(m_CameraTransfmrom, DeltaTime);
	*insert_cam.mutable_hitpoint() = hitPoint(m_CameraTransfmrom);

	return insert_cam;
}

void						MoskitManager::MakeController(MSAnalyzer::MOSKIT_UNITY_LIB::Scene& insert_scene, float DeltaTime)
{
	for (TObjectIterator<AActor> ActorItr; ActorItr; ++ActorItr)
	{
		UMotionControllerComponent* MotionController = ActorItr->FindComponentByClass<UMotionControllerComponent>();
		if (MotionController != NULL)
		{
			MSAnalyzer::MOSKIT_UNITY_LIB::Controller* insert_controller = insert_scene.add_list_controller();
			std::string strName = TCHAR_TO_UTF8(*(MotionController->GetName()));
			std::string strTag = "strTag";
			std::string strType = "strType";

			insert_controller->set_name(strName);
			insert_controller->set_active(true);

			insert_controller->set_layer(0);
			insert_controller->set_instanceid(MotionController->GetUniqueID());
			insert_controller->set_tag(strTag);
			*insert_controller->mutable_transform() = MakeTransform(MotionController->GetRelativeTransform(), DeltaTime);
			MakeComponent(MotionController->GetAttachmentRootActor(), *insert_controller);
			if (MotionController->GetAttachmentRootActor()->GetParentActor() == nullptr)
				insert_controller->mutable_transform()->set_parent(0);
			else
				insert_controller->mutable_transform()->set_parent(MotionController->GetUniqueID());
		}
	}
}
void MoskitManager::MakeGameObject(MSAnalyzer::MOSKIT_UNITY_LIB::Scene & insert_scene, float DeltaTime)
{
	for (TObjectIterator<AActor> ActorItr; ActorItr; ++ActorItr)
	{
		UStaticMeshComponent* mesh = ActorItr->FindComponentByClass<UStaticMeshComponent>();
		if (mesh != NULL)
		{
			if (!(ActorItr->WasRecentlyRendered()))
			{
				continue;
			}
			else
			{
				MSAnalyzer::MOSKIT_UNITY_LIB::GameObject* insert_obj = insert_scene.add_list_gameobject();
				std::string strName = TCHAR_TO_UTF8(*ActorItr->GetName());
				std::string strTag = "strTag";
				std::string strType = "strType";

				insert_obj->set_name(strName);
				insert_obj->set_active(true);
				insert_obj->set_isstatic(ActorItr->IsRootComponentStatic());
				insert_obj->set_layer(0);
				insert_obj->set_instanceid(ActorItr->GetUniqueID());
				insert_obj->set_tag(strTag);
				*insert_obj->mutable_transform() = (MakeTransform(ActorItr->GetActorTransform(), DeltaTime));
				MakeComponent(*ActorItr, *insert_obj);
				insert_obj->set_strtype(strType);
				if (ActorItr->GetParentActor() == nullptr)
					insert_obj->mutable_transform()->set_parent(0);
				else
					insert_obj->mutable_transform()->set_parent(ActorItr->GetParentActor()->GetUniqueID());
			}
		}
	}
}
void		MoskitManager::MakeComponent(AActor* obj, MSAnalyzer::MOSKIT_UNITY_LIB::MainCamera& output)
{
	TArray<UActorComponent*> list_Comp;
	obj->GetComponents(list_Comp);
	for (int i = 0; i < list_Comp.Num(); i++)
	{
		MSAnalyzer::MOSKIT_UNITY_LIB::Component* insertComp = output.add_list_component();
		std::string strName = TCHAR_TO_UTF8(*(list_Comp[i]->GetClass()->GetName()));
		insertComp->set_name(strName);
	}

}
void		MoskitManager::MakeComponent(AActor* obj, MSAnalyzer::MOSKIT_UNITY_LIB::GameObject& output)
{
	TArray<UActorComponent*> list_Comp;
	obj->GetComponents(list_Comp);
	for (int i = 0; i < list_Comp.Num(); i++)
	{
		MSAnalyzer::MOSKIT_UNITY_LIB::Component* insertComp = output.add_list_component();
		std::string strName = TCHAR_TO_UTF8(*(list_Comp[i]->GetClass()->GetName()));
		insertComp->set_name(strName);
	}

}
void		MoskitManager::MakeComponent(AActor* obj, MSAnalyzer::MOSKIT_UNITY_LIB::Controller& output)
{
	TArray<UActorComponent*> list_Comp;
	obj->GetComponents(list_Comp);
	for (int i = 0; i < list_Comp.Num(); i++)
	{
		MSAnalyzer::MOSKIT_UNITY_LIB::Component* insertComp = output.add_list_component();
		std::string strName = TCHAR_TO_UTF8(*(list_Comp[i]->GetClass()->GetName()));
		insertComp->set_name(strName);
	}

}
MSAnalyzer::MOSKIT_UNITY_LIB::Transform  MoskitManager::MakeTransform(FTransform  transf_, float DeltaTime)
{
	MSAnalyzer::MOSKIT_UNITY_LIB::Transform transf;
	MSAnalyzer::MOSKIT_UNITY_LIB::Vector3 vPosition(
		transf_.GetLocation().X,
		transf_.GetLocation().Y,
		transf_.GetLocation().Z);
	MSAnalyzer::MOSKIT_UNITY_LIB::Vector3 vRotation(
		transf_.GetRotation().Euler().X,
		transf_.GetRotation().Euler().Y,
		transf_.GetRotation().Euler().Z);
	MSAnalyzer::MOSKIT_UNITY_LIB::Vector3 vScale(
		transf_.GetScale3D().X,
		transf_.GetScale3D().Y,
		transf_.GetScale3D().Z);
	MSAnalyzer::MOSKIT_UNITY_LIB::Vector3 vAngularVelocity(
		AngularVelocity(DeltaTime));
	MSAnalyzer::MOSKIT_UNITY_LIB::Vector3 vForward(
		transf_.GetRotation().GetForwardVector());

	*transf.mutable_position() = vPosition;
	*transf.mutable_eulerangles() = vRotation;
	*transf.mutable_scale() = vScale;
	*transf.mutable_angularvelocity() = vAngularVelocity;
	*transf.mutable_forward() = vForward;
	transf.set_parent(0);

	return transf;
}

MSAnalyzer::MOSKIT_UNITY_LIB::Vector3  MoskitManager::hitPoint(FTransform _transform)
{
	MSAnalyzer::MOSKIT_UNITY_LIB::Vector3 vhitPos(
		0.0f,
		0.0f,
		0.0f);
	FHitResult* HitResult = new FHitResult();
	FVector StartTrace = _transform.GetLocation();
	FVector fwd = _transform.GetRotation().GetForwardVector();
	FVector EndTrace = ((fwd * fDistance) + StartTrace);
	FCollisionQueryParams* TraceParams = new FCollisionQueryParams();

	if (m_pWorld->LineTraceSingleByChannel(*HitResult, StartTrace, EndTrace, ECC_Visibility, *TraceParams))
	{
		if (HitResult->Actor != NULL)
		{
			vhitPos.set_x(HitResult->Actor->GetTargetLocation().X);
			vhitPos.set_y(HitResult->Actor->GetTargetLocation().Y);
			vhitPos.set_z(HitResult->Actor->GetTargetLocation().Z);
			//DrawDebugLine(m_pWorld, StartTrace, EndTrace, FColor(255, 0, 0), true)
			return vhitPos;
		}
	}
	return vhitPos;
}
bool MoskitManager::GetActiveComponent(AActor* _pPlayer)
{
	m_pPlayerActor = _pPlayer;
	if (m_pPlayerActor)
	{
		m_pWorld = m_pPlayerActor->GetWorld();
		if (m_pWorld)
		{
			m_pPlayerController = GEngine->GetFirstLocalPlayerController(m_pWorld);
			m_CameraTransfmrom = m_pPlayerController->PlayerCameraManager->GetTransformComponent()->GetRelativeTransform();


			m_fScaleRatio = m_pWorld->GetWorldSettings()->WorldToMeters;

			if (m_pPlayerController != NULL)
				return true;
		}
	}
	return false;

}
FVector MoskitManager::AngularVelocity(float DeltaTime)
{
	return (vAxis * magnitude) / DeltaTime;

}
//-1:clear message 0 red(exit) 1 green 2 blue
void MoskitManager::LogMessage(int errorCode, FString Msg)
{
	switch (errorCode)
	{
	case -1:
	{
		GEngine->ClearOnScreenDebugMessages();
	}
	case 0:
	{
		UE_LOG(LogClass, Log, TEXT("moskit plugin exit"), *Msg);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Msg);
		End();
	}break;
	case 1:
	{
		UE_LOG(LogClass, Log, TEXT("moskit plugin completed"), *Msg);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Msg);
	}break;
	case 2:
	{
		UE_LOG(LogClass, Log, TEXT("moskit plugin warning"), *Msg);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, Msg);
	}break;
	}
}