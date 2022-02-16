// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUIWidget.h"

#include <string>

#include "Components/TextBlock.h"

void UMainUIWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	//5 is the constant size
	const int size1 = 5;
	const int size2 = 8;
	
	//For Player Search Data Rows
	FSearchPlayer_RU sample0;
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
	FSearchPlayer_RU sample1;
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
	FSearchPlayer_RU sample2;
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
	FSearchPlayer_RU sample3;
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
	FSearchPlayer_RU sample4;
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
	
}

void UMainUIWidget::executePlayerSearchRowData(TArray<FSearchPlayer_RowD> data)
{
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
