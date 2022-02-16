// Fill out your copyright notice in the Description page of Project Settings.


#pragma once
#include "JsonSerialization.generated.h"

class UTextBlock;
//Use for Login Backend
USTRUCT()
struct Fdata {
    GENERATED_BODY()
    
    UPROPERTY() FString email;
    UPROPERTY() FString password;
    UPROPERTY() int userID;
    UPROPERTY() FString username;
    Fdata() {}
};
//Use for Login Backend
USTRUCT()
struct FResponse_Login {
    GENERATED_BODY()

    UPROPERTY() Fdata data;

    FResponse_Login() {}
};
//Use for Login Backend
USTRUCT()
struct FResponse_Login_Arr {
    GENERATED_BODY()

    UPROPERTY() TArray<Fdata> data;

    FResponse_Login_Arr() {}
};
 
//Use In Player Search Backend
USTRUCT()
struct FSearchPlayer_RowD {
    GENERATED_BODY()
    UPROPERTY() int assists;
UPROPERTY() FString format;
UPROPERTY() FString mvp;
UPROPERTY() int playerGoals;
UPROPERTY() int playerKnockouts;
UPROPERTY() FString playerName;
UPROPERTY() int playerPoints;
UPROPERTY() FString pokemonName;
UPROPERTY() FString result;
UPROPERTY() FString role;
UPROPERTY() int teamGoals;
 
    FSearchPlayer_RowD() {}
};

//Use In Player Search Backend
USTRUCT()
struct FSearchPlayer_D {
    GENERATED_BODY()

    UPROPERTY() int goalsPerMatch;
    UPROPERTY() int knockoutsPerMatch;
    UPROPERTY() int mvpPercentage;
    UPROPERTY() int totalMatch;
    UPROPERTY() int winPercentage;

    FSearchPlayer_D() {}
};

//Use In Player Search Backend
USTRUCT()
struct FSearchPlayer_U {
    GENERATED_BODY()
 
    UPROPERTY() FSearchPlayer_D data;
    UPROPERTY() TArray<FSearchPlayer_RowD> rowData;
 
    FSearchPlayer_U() {}
};

//Use In Player Search Backend
USTRUCT()
struct FSearchPlayer_RU {
    GENERATED_BODY()
 
    UPROPERTY() TArray<UTextBlock*> rowData;
 
    FSearchPlayer_RU() {}
};