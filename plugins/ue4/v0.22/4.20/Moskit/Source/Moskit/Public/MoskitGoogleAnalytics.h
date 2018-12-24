//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "Runtime/Online/HTTP/Public/Http.h"
//#include "Engine.h"
//#include "CoreMinimal.h"
//#include "GameFramework/Actor.h"
//#include "MoskitGoogleAnalytics.generated.h"
//
//UCLASS()
//class MOSKIT_API AMoskitGoogleAnalytics : public AActor
//{
//	GENERATED_BODY()
//
//public:
//	bool isPost = false;
//
//	FString dataParams;
//	// Sets default values for this actor's properties
//	AMoskitGoogleAnalytics();
//	~AMoskitGoogleAnalytics();
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//
//
//	void Post();
//
//	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
//
//	FString AddRequiredMPParameter(FString parameter, FString value);
//
//	FString GetScreenSize();
//
//	FString GetUniqueDevideID();
//
//	FString GetCurrentLanguage();
//
//};
