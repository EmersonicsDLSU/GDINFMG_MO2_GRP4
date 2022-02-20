// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HttpService.h"
#include "MainUIWidget.generated.h"

class UEditableText;
class UTextBlock;
class JsonSerialization;
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
	//This code is for playersearch
	UFUNCTION(BlueprintImplementableEvent)
	void executePlayerSearch();
	//clean up the yourStats Window
	void cleanUpYourStatsWindow();

	UPROPERTY()
	TArray<FTextBlockArr_RU> rowData_PS;

	UFUNCTION()
	void executePlayerSearchRowData(TArray<FSearchPlayer_RowD> data);

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
	/////////////////////////////////
//CommunityStats
	UFUNCTION()
	void executeCommunitySearchRowData(FGetCommunity_U comData);
	UFUNCTION(BlueprintImplementableEvent)
	void showCommunityData();
	UPROPERTY()
	TArray<FTextBlockArr_RU> rowData_CS;
	UPROPERTY(meta = (BindWidget))
UTextBlock* CS_RP;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_TMR;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_CWR;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_CAK;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_CAP;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_CAG;
UPROPERTY(meta = (BindWidget))
	UTextBlock* CS_PlayerName_0;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CS_PlayerName_1;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CS_PlayerName_2;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CS_PlayerName_3;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CS_PlayerName_4;
	UPROPERTY(meta = (BindWidget))
UTextBlock* CS_FormatText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_FormatText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_FormatText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_FormatText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_FormatText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PokemonNameText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PokemonNameText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PokemonNameText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PokemonNameText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PokemonNameText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_RoleText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_RoleText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_RoleText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_RoleText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_RoleText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_GoalsText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_GoalsText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_GoalsText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_GoalsText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_GoalsText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerGoalsText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerGoalsText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerGoalsText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerGoalsText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerGoalsText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerKnockoutsText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerKnockoutsText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerKnockoutsText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerKnockoutsText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerKnockoutsText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_AssistsText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_AssistsText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_AssistsText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_AssistsText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_AssistsText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerPointsText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerPointsText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerPointsText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerPointsText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_PlayerPointsText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_MVPText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_MVPText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_MVPText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_MVPText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_MVPText_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_ResultText_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_ResultText_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_ResultText_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_ResultText_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* CS_ResultText_4;
	/// ///////////////////////////////////
//MetaRankingStats
	UFUNCTION()
	void executeMetaRankingRowData(FGetMetaRanking_U comData);
	UFUNCTION(BlueprintImplementableEvent)
	void showMetaRankingData();
	UFUNCTION(BlueprintCallable)
	FString getPokemonNameFromButton(int index);
	UPROPERTY()
	TArray<FTextBlockArr_RU> rowData_MR;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_PokemonName_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_PokemonName_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_PokemonName_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_PokemonName_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_PokemonName_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_TotalGames_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_TotalGames_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_TotalGames_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_TotalGames_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_TotalGames_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_WinRate_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_WinRate_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_WinRate_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_WinRate_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_WinRate_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_GoalsPG_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_GoalsPG_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_GoalsPG_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_GoalsPG_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_GoalsPG_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_KnockoutsPG_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_KnockoutsPG_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_KnockoutsPG_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_KnockoutsPG_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_KnockoutsPG_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_AssistsPG_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_AssistsPG_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_AssistsPG_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_AssistsPG_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_AssistsPG_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_PointsPG_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_PointsPG_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_PointsPG_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_PointsPG_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_PointsPG_4;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_MvpRate_0;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_MvpRate_1;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_MvpRate_2;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_MvpRate_3;
UPROPERTY(meta = (BindWidget))
UTextBlock* PR_MvpRate_4;
	/// ///////////////////////////////////
//PokemonProfile
	UFUNCTION()
	void executePokemonProfileRowData(FPokemonProfile_U comData);
	UFUNCTION(BlueprintImplementableEvent)
	void showPokemonProfileData();
UPROPERTY(meta = (BindWidget))
UTextBlock* PP_PokemonName;
UPROPERTY(meta = (BindWidget))
UTextBlock* PP_TotalMatches;
UPROPERTY(meta = (BindWidget))
UTextBlock* PP_WinRate;
UPROPERTY(meta = (BindWidget))
UTextBlock* PP_GoalsPerMatch;
UPROPERTY(meta = (BindWidget))
UTextBlock* PP_KAAPM;
UPROPERTY(meta = (BindWidget))
UTextBlock* PP_PPM;
UPROPERTY(meta = (BindWidget))
UTextBlock* PP_MVPRate;
	/// ///////////////////////////////////
//PokemonProfile
	UFUNCTION(BlueprintCallable)
	void checkSignUpFields();
	UFUNCTION(BlueprintImplementableEvent)
	void showSignUpResponse();
UPROPERTY(meta = (BindWidget))
UEditableText* SU_Username;
UPROPERTY(meta = (BindWidget))
UEditableText* SU_Password;
UPROPERTY(meta = (BindWidget))
UEditableText* SU_Email;
	/// ///////////////////////////////////
	UFUNCTION(BlueprintImplementableEvent)
	void disableLoginButton();
	UFUNCTION(BlueprintImplementableEvent)
	void enableLoginButton();

	protected: void NativeOnInitialized() override; //.h

};
