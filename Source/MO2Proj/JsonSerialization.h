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

    UPROPERTY() int id;
    UPROPERTY() FString name;
    UPROPERTY() int score;
    Fdata() {}
};

USTRUCT()
struct FResponse_Login {
    GENERATED_BODY()
        /*
    UPROPERTY() int id;
    UPROPERTY() FString name;
    UPROPERTY() FString hash;
    */
    Fdata responseData;

    FResponse_Login() {}
};