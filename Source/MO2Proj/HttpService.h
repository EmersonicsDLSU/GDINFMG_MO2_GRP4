// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "JsonSerialization.h"
#include "Templates/SharedPointer.h"
#include "HttpService.generated.h"


class UMainUIWidget;
UCLASS(Blueprintable, hideCategories = (Rendering, Replication, Input, Actor, "Actor Tick"))
class MO2PROJ_API AHttpService : public AActor
{
    GENERATED_BODY()
private:
    FHttpModule* Http;
    FString ApiBaseUrl = "http://localhost:8800/api/";

    FString AuthorizationHeader = TEXT("Authorization");
    void SetAuthorizationHash(FString Hash, TSharedRef<IHttpRequest>& Request);

    TSharedRef<IHttpRequest> RequestWithRoute(FString Subroute);
    void SetRequestHeaders(TSharedRef<IHttpRequest>& Request);

    TSharedRef<IHttpRequest> GetRequest(FString Subroute);
    TSharedRef<IHttpRequest> PostRequest(FString Subroute, FString ContentJsonString);
    void Send(TSharedRef<IHttpRequest>& Request);

    bool ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful);

    template <typename K>
    void GetJsonStringFromStruct(K FilledStruct, FString& StringOutput);
    template <typename T>
    void GetStructFromJsonString(FHttpResponsePtr Response, T& StructOutput);

protected:
    virtual void BeginPlay() override;

private:
    ~AHttpService();
    

public:
    UPROPERTY(BlueprintReadWrite)
    UMainUIWidget* myWidget = nullptr;
    Fdata* currentUser = nullptr;
    Fdata* tempUser = nullptr;
    bool correct = false;
    AHttpService();

    void GetPlayer(int ind);
    void Login(FRequest_Login LoginCredentials);
    void LoginResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    //for the Login endpoint
    UFUNCTION(BlueprintCallable)
    void callCheckLogin(FString email, FString password);
    void CheckLogin(Fdata* LoginCredentials);
    void CheckLoginResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
    
    //for the playerSearch endpoint
    UFUNCTION(BlueprintCallable)
    void callSearchPlayer(FString username);
    void SearchPlayer(FString username);
    void GetPlayerResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
    

};
