// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUIWidget.h"

#include <string>

#include "DataList.h"
#include "Components/TextBlock.h"
#include "Components/EditableText.h"

void UMainUIWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	//5 is the constant size
	const int size1 = 5;
	const int size2 = 8;
	
	//For Player Search Data Rows
	FTextBlockArr_RU sample0;
	sample0.rowData.Add(this->AssistsText_0);
	sample0.rowData.Add(this->FormatText_0);
	sample0.rowData.Add(this->MVPText_0);
	sample0.rowData.Add(this->PlayerGoalsText_0);
	sample0.rowData.Add(this->PlayerKnockoutsText_0);
	sample0.rowData.Add(this->PlayerName_0);
	sample0.rowData.Add(this->PlayerPointsText_0);
	sample0.rowData.Add(this->PokemonNameText_0);
	sample0.rowData.Add(this->ResultText_0);
	sample0.rowData.Add(this->RoleText_0);
	sample0.rowData.Add(this->GoalsText_0);
	this->rowData_PS.Add(sample0);
	FTextBlockArr_RU sample1;
	sample1.rowData.Add(this->AssistsText_1);
	sample1.rowData.Add(this->FormatText_1);
	sample1.rowData.Add(this->MVPText_1);
	sample1.rowData.Add(this->PlayerGoalsText_1);
	sample1.rowData.Add(this->PlayerKnockoutsText_1);
	sample1.rowData.Add(this->PlayerName_1);
	sample1.rowData.Add(this->PlayerPointsText_1);
	sample1.rowData.Add(this->PokemonNameText_1);
	sample1.rowData.Add(this->ResultText_1);
	sample1.rowData.Add(this->RoleText_1);
	sample1.rowData.Add(this->GoalsText_1);
	this->rowData_PS.Add(sample1);
	FTextBlockArr_RU sample2;
	sample2.rowData.Add(this->AssistsText_2);
	sample2.rowData.Add(this->FormatText_2);
	sample2.rowData.Add(this->MVPText_2);
	sample2.rowData.Add(this->PlayerGoalsText_2);
	sample2.rowData.Add(this->PlayerKnockoutsText_2);
	sample2.rowData.Add(this->PlayerName_2);
	sample2.rowData.Add(this->PlayerPointsText_2);
	sample2.rowData.Add(this->PokemonNameText_2);
	sample2.rowData.Add(this->ResultText_2);
	sample2.rowData.Add(this->RoleText_2);
	sample2.rowData.Add(this->GoalsText_2);
	this->rowData_PS.Add(sample2);
	FTextBlockArr_RU sample3;
	sample3.rowData.Add(this->AssistsText_3);
	sample3.rowData.Add(this->FormatText_3);
	sample3.rowData.Add(this->MVPText_3);
	sample3.rowData.Add(this->PlayerGoalsText_3);
	sample3.rowData.Add(this->PlayerKnockoutsText_3);
	sample3.rowData.Add(this->PlayerName_3);
	sample3.rowData.Add(this->PlayerPointsText_3);
	sample3.rowData.Add(this->PokemonNameText_3);
	sample3.rowData.Add(this->ResultText_3);
	sample3.rowData.Add(this->RoleText_3);
	sample3.rowData.Add(this->GoalsText_3);
	this->rowData_PS.Add(sample3);
	FTextBlockArr_RU sample4;
	sample4.rowData.Add(this->AssistsText_4);
	sample4.rowData.Add(this->FormatText_4);
	sample4.rowData.Add(this->MVPText_4);
	sample4.rowData.Add(this->PlayerGoalsText_4);
	sample4.rowData.Add(this->PlayerKnockoutsText_4);
	sample4.rowData.Add(this->PlayerName_4);
	sample4.rowData.Add(this->PlayerPointsText_4);
	sample4.rowData.Add(this->PokemonNameText_4);
	sample4.rowData.Add(this->ResultText_4);
	sample4.rowData.Add(this->RoleText_4);
	sample4.rowData.Add(this->GoalsText_4);
	this->rowData_PS.Add(sample4);
	//////////////////////
	//For Community stats data row
	FTextBlockArr_RU sample5;
	sample5.rowData.Add(this->CS_AssistsText_0);
	sample5.rowData.Add(this->CS_FormatText_0);
	sample5.rowData.Add(this->CS_MVPText_0);
	sample5.rowData.Add(this->CS_PlayerGoalsText_0);
	sample5.rowData.Add(this->CS_PlayerKnockoutsText_0);
	sample5.rowData.Add(this->CS_PlayerName_0);
	sample5.rowData.Add(this->CS_PlayerPointsText_0);
	sample5.rowData.Add(this->CS_PokemonNameText_0);
	sample5.rowData.Add(this->CS_ResultText_0);
	sample5.rowData.Add(this->CS_RoleText_0);
	sample5.rowData.Add(this->CS_GoalsText_0);
	this->rowData_CS.Add(sample5);
	FTextBlockArr_RU sample6;
	sample6.rowData.Add(this->CS_AssistsText_1);
	sample6.rowData.Add(this->CS_FormatText_1);
	sample6.rowData.Add(this->CS_MVPText_1);
	sample6.rowData.Add(this->CS_PlayerGoalsText_1);
	sample6.rowData.Add(this->CS_PlayerKnockoutsText_1);
	sample6.rowData.Add(this->CS_PlayerName_1);
	sample6.rowData.Add(this->CS_PlayerPointsText_1);
	sample6.rowData.Add(this->CS_PokemonNameText_1);
	sample6.rowData.Add(this->CS_ResultText_1);
	sample6.rowData.Add(this->CS_RoleText_1);
	sample6.rowData.Add(this->CS_GoalsText_1);
	this->rowData_CS.Add(sample6);
	FTextBlockArr_RU sample7;
	sample7.rowData.Add(this->CS_AssistsText_2);
	sample7.rowData.Add(this->CS_FormatText_2);
	sample7.rowData.Add(this->CS_MVPText_2);
	sample7.rowData.Add(this->CS_PlayerGoalsText_2);
	sample7.rowData.Add(this->CS_PlayerKnockoutsText_2);
	sample7.rowData.Add(this->CS_PlayerName_2);
	sample7.rowData.Add(this->CS_PlayerPointsText_2);
	sample7.rowData.Add(this->CS_PokemonNameText_2);
	sample7.rowData.Add(this->CS_ResultText_2);
	sample7.rowData.Add(this->CS_RoleText_2);
	sample7.rowData.Add(this->CS_GoalsText_2);
	this->rowData_CS.Add(sample7);
	FTextBlockArr_RU sample8;
	sample8.rowData.Add(this->CS_AssistsText_3);
	sample8.rowData.Add(this->CS_FormatText_3);
	sample8.rowData.Add(this->CS_MVPText_3);
	sample8.rowData.Add(this->CS_PlayerGoalsText_3);
	sample8.rowData.Add(this->CS_PlayerKnockoutsText_3);
	sample8.rowData.Add(this->CS_PlayerName_3);
	sample8.rowData.Add(this->CS_PlayerPointsText_3);
	sample8.rowData.Add(this->CS_PokemonNameText_3);
	sample8.rowData.Add(this->CS_ResultText_3);
	sample8.rowData.Add(this->CS_RoleText_3);
	sample8.rowData.Add(this->CS_GoalsText_3);
	this->rowData_CS.Add(sample8);
	FTextBlockArr_RU sample9;
	sample9.rowData.Add(this->CS_AssistsText_4);
	sample9.rowData.Add(this->CS_FormatText_4);
	sample9.rowData.Add(this->CS_MVPText_4);
	sample9.rowData.Add(this->CS_PlayerGoalsText_4);
	sample9.rowData.Add(this->CS_PlayerKnockoutsText_4);
	sample9.rowData.Add(this->CS_PlayerName_4);
	sample9.rowData.Add(this->CS_PlayerPointsText_4);
	sample9.rowData.Add(this->CS_PokemonNameText_4);
	sample9.rowData.Add(this->CS_ResultText_4);
	sample9.rowData.Add(this->CS_RoleText_4);
	sample9.rowData.Add(this->CS_GoalsText_4);
	this->rowData_CS.Add(sample9);
	//////////////////////
	//For Community stats data row
	FTextBlockArr_RU sample10;
	sample10.rowData.Add(this->PR_AssistsPG_0);
	sample10.rowData.Add(this->PR_MvpRate_0);
	sample10.rowData.Add(this->PR_GoalsPG_0);
	sample10.rowData.Add(this->PR_KnockoutsPG_0);
	sample10.rowData.Add(this->PR_PokemonName_0);
	sample10.rowData.Add(this->PR_PointsPG_0);
	sample10.rowData.Add(this->PR_TotalGames_0);
	sample10.rowData.Add(this->PR_WinRate_0);
	this->rowData_MR.Add(sample10);
	FTextBlockArr_RU sample11;
	sample11.rowData.Add(this->PR_AssistsPG_1);
	sample11.rowData.Add(this->PR_MvpRate_1);
	sample11.rowData.Add(this->PR_GoalsPG_1);
	sample11.rowData.Add(this->PR_KnockoutsPG_1);
	sample11.rowData.Add(this->PR_PokemonName_1);
	sample11.rowData.Add(this->PR_PointsPG_1);
	sample11.rowData.Add(this->PR_TotalGames_1);
	sample11.rowData.Add(this->PR_WinRate_1);
	this->rowData_MR.Add(sample11);
	FTextBlockArr_RU sample12;
	sample12.rowData.Add(this->PR_AssistsPG_2);
	sample12.rowData.Add(this->PR_MvpRate_2);
	sample12.rowData.Add(this->PR_GoalsPG_2);
	sample12.rowData.Add(this->PR_KnockoutsPG_2);
	sample12.rowData.Add(this->PR_PokemonName_2);
	sample12.rowData.Add(this->PR_PointsPG_2);
	sample12.rowData.Add(this->PR_TotalGames_2);
	sample12.rowData.Add(this->PR_WinRate_2);
	this->rowData_MR.Add(sample12);
	FTextBlockArr_RU sample13;
	sample13.rowData.Add(this->PR_AssistsPG_3);
	sample13.rowData.Add(this->PR_MvpRate_3);
	sample13.rowData.Add(this->PR_GoalsPG_3);
	sample13.rowData.Add(this->PR_KnockoutsPG_3);
	sample13.rowData.Add(this->PR_PokemonName_3);
	sample13.rowData.Add(this->PR_PointsPG_3);
	sample13.rowData.Add(this->PR_TotalGames_3);
	sample13.rowData.Add(this->PR_WinRate_3);
	this->rowData_MR.Add(sample13);
	FTextBlockArr_RU sample14;
	sample14.rowData.Add(this->PR_AssistsPG_4);
	sample14.rowData.Add(this->PR_MvpRate_4);
	sample14.rowData.Add(this->PR_GoalsPG_4);
	sample14.rowData.Add(this->PR_KnockoutsPG_4);
	sample14.rowData.Add(this->PR_PokemonName_4);
	sample14.rowData.Add(this->PR_PointsPG_4);
	sample14.rowData.Add(this->PR_TotalGames_4);
	sample14.rowData.Add(this->PR_WinRate_4);
	this->rowData_MR.Add(sample14);
}

void UMainUIWidget::cleanUpYourStatsWindow()
{
	//cleanup
	UDataList* dataList = this->htppServiceSc->FindComponentByClass<UDataList>();
    dataList->playerName = "Player Stats";
    dataList->goalsPerMatch = 0;
    dataList->knockoutsPerMatch = 0;
    dataList->mvpPercentage = 0;
    dataList->totalMatch = 0;
    dataList->winPercentage = 0;

	//cleanup the previous data first
	for (size_t i = 0; i < 5; i++)
	{
		this->rowData_PS[i].rowData[0]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[1]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[2]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[3]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[4]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[5]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[6]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[7]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[8]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[9]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[10]->SetText(FText::FromString("Default"));
	}
	this->executePlayerSearch();
}


void UMainUIWidget::executePlayerSearchRowData(TArray<FSearchPlayer_RowD> data)
{
	//cleanup the previous data first
	for (size_t i = 0; i < 5; i++)
	{
		this->rowData_PS[i].rowData[0]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[1]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[2]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[3]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[4]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[5]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[6]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[7]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[8]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[9]->SetText(FText::FromString("Default"));
		this->rowData_PS[i].rowData[10]->SetText(FText::FromString("Default"));
	}
	//upload the new batch of data
	for (size_t i = 0; i < data.Num(); i++)
	{
		this->rowData_PS[i].rowData[0]->SetText(FText::FromString(FString::FromInt(data[i].assists)));
		this->rowData_PS[i].rowData[1]->SetText(FText::FromString(data[i].format));
		this->rowData_PS[i].rowData[2]->SetText(FText::FromString(data[i].mvp));
		this->rowData_PS[i].rowData[3]->SetText(FText::FromString(FString::FromInt(data[i].playerGoals)));
		this->rowData_PS[i].rowData[4]->SetText(FText::FromString(FString::FromInt(data[i].playerKnockouts)));
		this->rowData_PS[i].rowData[5]->SetText(FText::FromString(data[i].playerName));
		this->rowData_PS[i].rowData[6]->SetText(FText::FromString(FString::FromInt(data[i].playerPoints)));
		this->rowData_PS[i].rowData[7]->SetText(FText::FromString(data[i].pokemonName));
		this->rowData_PS[i].rowData[8]->SetText(FText::FromString(data[i].result));
		this->rowData_PS[i].rowData[9]->SetText(FText::FromString(data[i].role));
		this->rowData_PS[i].rowData[10]->SetText(FText::FromString(FString::FromInt(data[i].teamGoals)));
	}
}


void UMainUIWidget::executeCommunitySearchRowData(FGetCommunity_U comData)
{
	this->CS_RP->SetText(FText::FromString(FString::FromInt(comData.data.TotalRegisteredUsers)));
	this->CS_TMR->SetText(FText::FromString(FString::FromInt(comData.data.TotalMatches)));
	this->CS_CWR->SetText(FText::FromString(FString::FromInt(comData.data.community_win_rate) + "%"));
	this->CS_CAK->SetText(FText::FromString(FString::FromInt(comData.data.Community_Avg_Knockouts)));
	this->CS_CAP->SetText(FText::FromString(FString::FromInt(comData.data.Community_Avg_Points)));
	this->CS_CAG->SetText(FText::FromString(FString::FromInt(comData.data.Community_Avg_Goals)));
	//upload the new batch of data
	for (size_t i = 0; i < comData.rowData.Num() && i < 5; i++)
	{
		this->rowData_CS[i].rowData[0]->SetText(FText::FromString(FString::FromInt(comData.rowData[i].assists)));
		this->rowData_CS[i].rowData[1]->SetText(FText::FromString(comData.rowData[i].format));
		this->rowData_CS[i].rowData[2]->SetText(FText::FromString(comData.rowData[i].mvp));
		this->rowData_CS[i].rowData[3]->SetText(FText::FromString(FString::FromInt(comData.rowData[i].playerGoals)));
		this->rowData_CS[i].rowData[4]->SetText(FText::FromString(FString::FromInt(comData.rowData[i].playerKnockouts)));
		this->rowData_CS[i].rowData[5]->SetText(FText::FromString(comData.rowData[i].playerName));
		this->rowData_CS[i].rowData[6]->SetText(FText::FromString(FString::FromInt(comData.rowData[i].playerPoints)));
		this->rowData_CS[i].rowData[7]->SetText(FText::FromString(comData.rowData[i].pokemonName));
		this->rowData_CS[i].rowData[8]->SetText(FText::FromString(comData.rowData[i].result));
		this->rowData_CS[i].rowData[9]->SetText(FText::FromString(comData.rowData[i].role));
		this->rowData_CS[i].rowData[10]->SetText(FText::FromString(FString::FromInt(comData.rowData[i].teamGoals)));
	}
}

void UMainUIWidget::executeMetaRankingRowData(FGetMetaRanking_U comData)
{
	//upload the new batch of data
	for (size_t i = 0; i < comData.rowData.Num() && i < 5; i++)
	{
		this->rowData_MR[i].rowData[0]->SetText(FText::FromString(FString::FromInt(comData.rowData[i].assists)));
		this->rowData_MR[i].rowData[1]->SetText(FText::FromString(comData.rowData[i].mvp));
		this->rowData_MR[i].rowData[2]->SetText(FText::FromString(FString::FromInt(comData.rowData[i].pokemonGoals)));
		this->rowData_MR[i].rowData[3]->SetText(FText::FromString(FString::FromInt(comData.rowData[i].pokemonKnockouts)));
		this->rowData_MR[i].rowData[4]->SetText(FText::FromString(comData.rowData[i].pokemonName));
		this->rowData_MR[i].rowData[5]->SetText(FText::FromString(FString::FromInt(comData.rowData[i].pokemonPoints)));
		this->rowData_MR[i].rowData[6]->SetText(FText::FromString(FString::FromInt(comData.rowData[i].totalGames)));
		this->rowData_MR[i].rowData[7]->SetText(FText::FromString(comData.rowData[i].winRate));
	}
}

FString UMainUIWidget::getPokemonNameFromButton(int index)
{
	switch (index)
	{
	case 0:
		{
			return this->PR_PokemonName_0->GetText().ToString();
			break;
		}
	case 1:
		{
			return this->PR_PokemonName_1->GetText().ToString();
			break;
		}
	case 2:
		{
			return this->PR_PokemonName_2->GetText().ToString();
			break;
		}
	case 3:
		{
			return this->PR_PokemonName_3->GetText().ToString();
			break;
		}
	case 4:
		{
			return this->PR_PokemonName_4->GetText().ToString();
			break;
		}
	}

	return "none";
}

void UMainUIWidget::executePokemonProfileRowData(FPokemonProfile_U comData)
{
	this->PP_PokemonName->SetText(FText::FromString(comData.rowData.pokemonName));
	this->PP_KAAPM->SetText(FText::FromString(FString::FromInt(comData.rowData.KAAPM)));
	this->PP_MVPRate->SetText(FText::FromString(FString::FromInt(comData.rowData.mvp) + "%"));
	this->PP_GoalsPerMatch->SetText(FText::FromString(FString::FromInt(comData.rowData.pokemonGoals)));
	this->PP_PPM->SetText(FText::FromString(FString::FromInt(comData.rowData.pokemonPoints)));
	this->PP_TotalMatches->SetText(FText::FromString(FString::FromInt(comData.rowData.totalGames)));
	this->PP_WinRate->SetText(FText::FromString(FString::FromInt(comData.rowData.winRate) + "%"));
}

void UMainUIWidget::checkSignUpFields()
{
    //check if username is less than a const size or the email is not valid
	if(this->SU_Username->GetText().ToString().Len() < 5 || 
		!this->SU_Email->GetText().ToString().Contains("@yahoo.com") &&
		!this->SU_Email->GetText().ToString().Contains("@gmail.com"))
	{
		UE_LOG(LogTemp, Warning, TEXT("Username Size: %d"), this->SU_Username->GetText().ToString().Len());
		UE_LOG(LogTemp, Warning, TEXT("Email is: %s"), *this->SU_Email->GetText().ToString());
		UE_LOG(LogTemp, Warning, TEXT("Invalid username or email!"));
		return;
	}
	
	//pass the Fdata to the current signup data
	this->htppServiceSc->signUpAccountData = new FResponse_Login();
	this->htppServiceSc->signUpAccountData->data.username = this->SU_Username->GetText().ToString();
	this->htppServiceSc->signUpAccountData->data.email = this->SU_Email->GetText().ToString();
	this->htppServiceSc->signUpAccountData->data.password = this->SU_Password->GetText().ToString();

    UE_LOG(LogTemp, Warning, TEXT("Username is: %s"), *this->htppServiceSc->signUpAccountData->data.username);
    UE_LOG(LogTemp, Warning, TEXT("Email is: %s"), *this->htppServiceSc->signUpAccountData->data.email);
    UE_LOG(LogTemp, Warning, TEXT("Password is: %s"), *this->htppServiceSc->signUpAccountData->data.password);

	this->htppServiceSc->CheckSignUpFields();

}