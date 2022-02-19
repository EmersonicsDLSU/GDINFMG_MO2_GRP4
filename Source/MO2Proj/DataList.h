// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DataList.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MO2PROJ_API UDataList : public UActorComponent
{
	GENERATED_BODY()

public:	
    UPROPERTY(BlueprintReadWrite) FString playerName;
    UPROPERTY(BlueprintReadWrite) int goalsPerMatch;
    UPROPERTY(BlueprintReadWrite) int knockoutsPerMatch;
    UPROPERTY(BlueprintReadWrite) int mvpPercentage;
    UPROPERTY(BlueprintReadWrite) int totalMatch;
    UPROPERTY(BlueprintReadWrite) int winPercentage;
    UPROPERTY(BlueprintReadWrite) bool isFinish = false;
	// Sets default values for this component's properties
	UDataList();
	//For PokemonProfile
	
    UPROPERTY(BlueprintReadWrite) int pickedPokemonName;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
