// Fill out your copyright notice in the Description page of Project Settings.


#pragma once
#include "JsonSerialization.generated.h"


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
struct FResponse_Login_Arr {
    GENERATED_BODY()

    UPROPERTY() TArray<Fdata> data;

    FResponse_Login_Arr() {}
};



//Use In Player Search Backend
USTRUCT()
struct FSearchPlayer_RowD {
    GENERATED_BODY()

    UPROPERTY() FString playerName;
	UPROPERTY() FString format;
	UPROPERTY() FString pokemon;
UPROPERTY() FString role;
UPROPERTY() int goals;
UPROPERTY() int playerGoals;
UPROPERTY() int playerKnocokouts;
UPROPERTY() int assists;
UPROPERTY() int playerPoints;
UPROPERTY() FString mvp;
UPROPERTY() FString result;

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

    FSearchPlayer_U() {}
};
