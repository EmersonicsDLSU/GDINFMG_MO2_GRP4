// Fill out your copyright notice in the Description page of Project Settings.


#pragma once
#include "JsonSerialization.generated.h"

USTRUCT()
struct FRequest_Login {
    GENERATED_BODY()
    UPROPERTY() FString email;
    UPROPERTY() FString password;

    FRequest_Login() {}
};

USTRUCT()
struct Fdata {
    GENERATED_BODY()
    
    UPROPERTY() FString email;
    UPROPERTY() FString password;
    UPROPERTY() int userID;
    UPROPERTY() FString username;
    Fdata() {}
};

USTRUCT()
struct FResponse_Login {
    GENERATED_BODY()

    UPROPERTY() Fdata data;

    FResponse_Login() {}
};

USTRUCT()
struct FResponse_Login_Arr {
    GENERATED_BODY()

    UPROPERTY() TArray<Fdata> data;

    FResponse_Login_Arr() {}
};