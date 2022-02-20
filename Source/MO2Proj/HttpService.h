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
    
    void GetJsonStringFromStruct(Fdata FilledStruct, FString& StringOutput);
    template <typename T>
    void GetStructFromJsonString(FHttpResponsePtr Response, T& StructOutput);

protected:
    virtual void BeginPlay() override;

private:
    ~AHttpService();
    

public:
    FResponse_Login* signUpAccountData = nullptr;
    Fdata* currentUser = nullptr;
    FString currentUsername;
    Fdata* tempUser = nullptr;
    UPROPERTY(BlueprintReadWrite)
    UMainUIWidget* myWidget = nullptr;
    bool correct = false;
    AHttpService();

    //for the Login endpoint
    UFUNCTION(BlueprintCallable)
    void callCheckLogin(FString email, FString password);
    void CheckLogin();
    void CheckLoginResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
    UFUNCTION(BlueprintCallable)
    void onLogout();
    
    //for the playerSearch endpoint
    UFUNCTION(BlueprintCallable)
    void callSearchPlayer(FString username);
    void SearchPlayer(FString username);
    UFUNCTION(BlueprintCallable)
    bool checkLoginSearchPlayer();
    void GetPlayerResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
    
    //for the communityResult endpoint
    UFUNCTION(BlueprintCallable)
    void CallCommunityResult();
    void GetCommunityResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    //for the metaRankingResult endpoint
    UFUNCTION(BlueprintCallable)
    void CallMetaRankingResult();
    void GetMetaRankingResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    //for the pokemonProfile endpoint
    UFUNCTION(BlueprintCallable)
    void CallPokemonProfile(FString pokemonName);
    void GetPokemonProfileResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    //for the signUp endpoint
    UFUNCTION(BlueprintCallable)
    void CallSignUpAccount();
    void SignUpResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
    void CheckSignUpFields();
    void CheckSignUpFieldsResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

};
