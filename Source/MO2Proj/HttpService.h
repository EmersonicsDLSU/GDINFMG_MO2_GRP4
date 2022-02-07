// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "JsonSerialization.h"
#include "HttpService.generated.h"

UCLASS(Blueprintable, hideCategories = (Rendering, Replication, Input, Actor, "Actor Tick"))
class _API AHttpService : public AActor
{
    GENERATED_BODY()
private:
    FHttpModule* Http;
    FString ApiBaseUrl = "http://localhost:5000/api/";

    FString AuthorizationHeader = TEXT("Authorization");
    void SetAuthorizationHash(FString Hash, TSharedRef& Request);

    TSharedRef RequestWithRoute(FString Subroute);
    void SetRequestHeaders(TSharedRef& Request);

    TSharedRef GetRequest(FString Subroute);
    TSharedRef PostRequest(FString Subroute, FString ContentJsonString);
    void Send(TSharedRef& Request);

    bool ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful);

    template 
    void GetJsonStringFromStruct(StructType FilledStruct, FString& StringOutput);
    template 
    void GetStructFromJsonString(FHttpResponsePtr Response, StructType& StructOutput);

protected:
    virtual void BeginPlay() override;

public:
    AHttpService();

    void Login(FRequest_Login LoginCredentials);
    void LoginResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
