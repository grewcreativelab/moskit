//// Fill out your copyright notice in the Description page of Project Settings.
//
//#include "MoskitGoogleAnalytics.h"
//
//// Sets default values
//AMoskitGoogleAnalytics::AMoskitGoogleAnalytics()
//{
//	//instance = GetInstance();
//	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//
//	PrimaryActorTick.bCanEverTick = true;
//
//}
//
//AMoskitGoogleAnalytics::~AMoskitGoogleAnalytics()
//{
//
//}
//// Called when the game starts or when spawned
//void AMoskitGoogleAnalytics::BeginPlay()
//{
//	Super::BeginPlay();
//
//}
//
//// Called every frame
//void AMoskitGoogleAnalytics::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//
//void AMoskitGoogleAnalytics::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
//{
//	FString MessageBody = "";
//
//	// If HTTP fails client-side, this will still be called but with a NULL shared pointer!
//	if (!Response.IsValid())
//	{
//		MessageBody = "{\"success\":\"Error: Unable to process HTTP Request!\"}";
//	}
//	else if (EHttpResponseCodes::IsOk(Response->GetResponseCode()))
//	{
//		MessageBody = Response->GetContentAsString();
//	}
//	else
//	{
//		MessageBody = FString::Printf(TEXT("{\"success\":\"HTTP Error: %d\"}"), Response->GetResponseCode());
//	}
//
//	this->Destroy();
//}
//
//void AMoskitGoogleAnalytics::Post()
//{
//	//FString strURL = ApiBaseURL;
//	FString dataParams;
//
//	FString strSize = GetScreenSize();
//
//	FString TrackingID = "UA-120207396-4";
//
//	FString Name = "MOSKIT_PLUGIN_UE4";
//
//	FString Version = "v0.22";
//
//	FString Info = "UE4DLL";
//
//	FString host = "www.google-analytics.com";
//
//	FString ApiBaseURL = "https://www.google-analytics.com/collect?v=1";
//
//	//Language
//	dataParams.Append(AddRequiredMPParameter("&ul", GetCurrentLanguage()));
//	//screen
//	dataParams.Append(AddRequiredMPParameter("&sr", GetScreenSize()));
//	//AppName
//	dataParams.Append(AddRequiredMPParameter("&an", Name));
//	//Tracking ID
//	dataParams.Append(AddRequiredMPParameter("&tid", TrackingID));
//	//Client ID
//	dataParams.Append(AddRequiredMPParameter("&cid", GetUniqueDevideID()));
//	//App Version
//	dataParams.Append(AddRequiredMPParameter("&av", Version));
//	//IP
//	dataParams.Append(AddRequiredMPParameter("&aip", "1"));
//	//hitType
//	dataParams.Append(AddRequiredMPParameter("&t", "appview"));
//	//screenName
//	dataParams.Append(AddRequiredMPParameter("&cd", Info));
//
//	//strURL += dataParams;
//	FHttpModule& HttpModule = FHttpModule::Get();
//	TSharedRef<IHttpRequest> Request = HttpModule.CreateRequest();
//	Request->SetContentAsString(dataParams);
//	Request->SetURL(ApiBaseURL);
//
//	Request->SetVerb("POST");
//
//	Request->SetHeader(TEXT("Host"), host);
//
//	Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
//
//	Request->SetHeader("Content-Type", TEXT("application/x-www-form-urlencoded"));
//
//	Request->SetHeader("Content-Length", FString::FromInt(dataParams.Len()));
//
//	Request->OnProcessRequestComplete().BindUObject(this, &AMoskitGoogleAnalytics::OnResponseReceived);
//
//	Request->ProcessRequest();
//
//
//}
//FString AMoskitGoogleAnalytics::GetCurrentLanguage()
//{
//	return	FInternationalization::Get().GetCurrentCulture()->GetName();
//}
//FString AMoskitGoogleAnalytics::GetUniqueDevideID()
//{
//	return FPlatformMisc::GetHashedMacAddressString();
//}
//FString AMoskitGoogleAnalytics::GetScreenSize()
//{
//	FVector2D size = GEngine->GameViewport->Viewport->GetSizeXY();
//	return FString::FromInt(size.X) + "x" + FString::FromInt(size.Y);
//}
//FString AMoskitGoogleAnalytics::AddRequiredMPParameter(FString parameter, FString value)
//{
//	return parameter + "=" + value;
//}