// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpService.h"

AHttpService::AHttpService()
{ 
    PrimaryActorTick.bCanEverTick = false; 
}

void AHttpService::BeginPlay() { 
    Super::BeginPlay(); 
    Http = &FHttpModule::Get(); 
    
        // You can uncomment this out for testing.
    //FRequest_Login LoginCredentials;
    //LoginCredentials.email = TEXT("asdf@asdf.com");
    //LoginCredentials.password = TEXT("asdfasdf");
    //Login(LoginCredentials);
}

TSharedRef AHttpService::RequestWithRoute(FString Subroute) {
    TSharedRef Request = Http->CreateRequest();
    Request->SetURL(ApiBaseUrl + Subroute);
    SetRequestHeaders(Request);
    return Request;
}

void AHttpService::SetRequestHeaders(TSharedRef& Request) {
    Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    Request->SetHeader(TEXT("Accepts"), TEXT("application/json"));
}

TSharedRef AHttpService::GetRequest(FString Subroute) {
    TSharedRef Request = RequestWithRoute(Subroute);
    Request->SetVerb("GET");
    return Request;
}

TSharedRef AHttpService::PostRequest(FString Subroute, FString ContentJsonString) {
    TSharedRef Request = RequestWithRoute(Subroute);
    Request->SetVerb("POST");
    Request->SetContentAsString(ContentJsonString);
    return Request;
}

void AHttpService::Send(TSharedRef& Request) {
    Request->ProcessRequest();
}

bool AHttpService::ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful) {
    if (!bWasSuccessful || !Response.IsValid()) 
        return false; 
    if (EHttpResponseCodes::IsOk(Response->GetResponseCode())) 
        return true; 
    else 
    { UE_LOG(LogTemp, Warning, TEXT("Http Response returned error code: %d"), Response->GetResponseCode()); return false; } }

void AHttpService::SetAuthorizationHash(FString Hash, TSharedRef& Request) {
    Request->SetHeader(AuthorizationHeader, Hash);
}



/**************************************************************************************************************************/



template 
void AHttpService::GetJsonStringFromStruct(FRequest_Login FilledStruct, FString& StringOutput) {
    FJsonObjectConverter::UStructToJsonObjectString(FRequest_Login::StaticStruct(), &FilledStruct, StringOutput, 0, 0);
}

template 
void AHttpService::GetStructFromJsonString(FHttpResponsePtr Response, FResponse_Login& StructOutput) {
    FResponse_Login StructData;
    FString JsonString = Response->GetContentAsString();
    FJsonObjectConverter::JsonObjectStringToUStruct(JsonString, &StructOutput, 0, 0);
}


/**************************************************************************************************************************/


void AHttpService::Login(FRequest_Login LoginCredentials) {
    FString ContentJsonString;
    GetJsonStringFromStruct(LoginCredentials, ContentJsonString);

    TSharedRef Request = PostRequest("user/login", ContentJsonString);
    Request->OnProcessRequestComplete().BindUObject(this, &AHttpService::LoginResponse);
    Send(Request);
}

void AHttpService::LoginResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    if (!ResponseIsValid(Response, bWasSuccessful)) return;

    FResponse_Login LoginResponse;
    GetStructFromJsonString(Response, LoginResponse);

    UE_LOG(LogTemp, Warning, TEXT("Id is: %d"), LoginResponse.id);
    UE_LOG(LogTemp, Warning, TEXT("Name is: %s"), *LoginResponse.name);
}