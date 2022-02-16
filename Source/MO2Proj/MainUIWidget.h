// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HttpService.h"
#include "MainUIWidget.generated.h"

/**
 * 
 */

class UTextBlock;
UCLASS()
class MO2PROJ_API UMainUIWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	AHttpService* htppServiceSc = nullptr;

	//use for playersearch
	UFUNCTION(BlueprintImplementableEvent)
	void executePlayerSearch();
	UFUNCTION(BlueprintCallable)
	void executePlayerSearchStats();
	UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerName_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerName_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerName_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerName_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerName_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* FormatText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* FormatText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* FormatText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* FormatText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* FormatText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* PokemonNameText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* PokemonNameText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* PokemonNameText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* PokemonNameText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* PokemonNameText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* RoleText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* RoleText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* RoleText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* RoleText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* RoleText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* GoalsText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* GoalsText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* GoalsText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* GoalsText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* GoalsText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerGoalsText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerGoalsText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerGoalsText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerGoalsText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerGoalsText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerKnockoutsText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerKnockoutsText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerKnockoutsText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerKnockoutsText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerKnockoutsText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* AssistsText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* AssistsText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* AssistsText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* AssistsText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* AssistsText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerPointsText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerPointsText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerPointsText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerPointsText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* PlayerPointsText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* MVPText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* MVPText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* MVPText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* MVPText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* MVPText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* ResultText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* ResultText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* ResultText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* ResultText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* ResultText_4;

	///////////////////////////////////////////////////
protected:
	void NativeOnInitialized() override;

};
