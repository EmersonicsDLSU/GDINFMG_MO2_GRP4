// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HttpService.h"
#include "MainUIWidget.generated.h"

/**
 * 
 */
UCLASS()
class MO2PROJ_API UMainUIWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	AHttpService* htppServiceSc = nullptr;  
	UFUNCTION(BlueprintImplementableEvent)
	void executePlayerSearch();
};
