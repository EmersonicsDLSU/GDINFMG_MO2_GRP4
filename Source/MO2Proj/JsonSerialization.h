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
struct FTextBlockArr_RU {
    GENERATED_BODY()
 
    UPROPERTY() TArray<UTextBlock*> rowData;
 
    FTextBlockArr_RU() {}
};
 
//Use In Community Search Backend
USTRUCT()
struct FGetCommunity_RowD {
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
 
    FGetCommunity_RowD() {}
};

//Use In Community Search Backend
USTRUCT()
struct FGetCommunity_D {
    GENERATED_BODY()

    UPROPERTY() int Community_Avg_Goals;
    UPROPERTY() int Community_Avg_Knockouts;
    UPROPERTY() int Community_Avg_Points;
    UPROPERTY() int TotalMatches;
    UPROPERTY() int TotalRegisteredUsers;
    UPROPERTY() int community_win_rate;

    FGetCommunity_D() {}
};

//Use In Community Search Backend
USTRUCT()
struct FGetCommunity_U {
    GENERATED_BODY()
 
    UPROPERTY() FGetCommunity_D data;
    UPROPERTY() TArray<FGetCommunity_RowD> rowData;
 
    FGetCommunity_U() {}
};
 
//Use In MetaRanking Backend
USTRUCT()
struct FGetMetaRanking_RowD {
    GENERATED_BODY()
UPROPERTY() int assists;
UPROPERTY() FString mvp;
UPROPERTY() int pokemonGoals;
UPROPERTY() int pokemonKnockouts;
UPROPERTY() FString pokemonName;
UPROPERTY() int pokemonPoints;
UPROPERTY() int totalGames;
UPROPERTY() FString winRate;
 
    FGetMetaRanking_RowD() {}
};

//Use In MetaRanking Backend
USTRUCT()
struct FGetMetaRanking_U {
    GENERATED_BODY()
 
    UPROPERTY() TArray<FGetMetaRanking_RowD> rowData;
 
    FGetMetaRanking_U() {}
};

//Use In PokemonProfile Backend
USTRUCT()
struct FPokemonProfile_RowD {
    GENERATED_BODY()
UPROPERTY() int KAAPM;
UPROPERTY() int mvp;
UPROPERTY() int pokemonGoals;
UPROPERTY() FString pokemonName;
UPROPERTY() int pokemonPoints;
UPROPERTY() int totalGames;
UPROPERTY() int winRate;
 
    FPokemonProfile_RowD() {}
};

//Use In PokemonProfile Backend
USTRUCT()
struct FPokemonProfile_U {
    GENERATED_BODY()
 
    UPROPERTY() FPokemonProfile_RowD rowData;
 
    FPokemonProfile_U() {}
};

//Use In AddMatch Backend
USTRUCT()
struct FAddMatch_RowD {
    GENERATED_BODY()
UPROPERTY() int assists; //update in C++
UPROPERTY() int battleItem; //update in BP
UPROPERTY() FString format; //update in BP
UPROPERTY() int knockouts; //update in C++
UPROPERTY() FString lane; //update in BP
UPROPERTY() int opponentGoals; //update in C++
UPROPERTY() int pokemonName; //update in BP
UPROPERTY() FString result; //update in BP
UPROPERTY() FString role; //update in BP
UPROPERTY() int teamGoals; //update in C++
UPROPERTY() int yourGoals; //update in C++
UPROPERTY() int yourPoints; //update in C++
 
    FAddMatch_RowD() {}
};

//Use In AddMatch Backend
USTRUCT()
struct FAddMatch_U {
    GENERATED_BODY()
 
    UPROPERTY() FAddMatch_RowD rowData;
 
    FAddMatch_U () {}
};