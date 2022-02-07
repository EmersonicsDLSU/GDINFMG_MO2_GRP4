// Fill out your copyright notice in the Description page of Project Settings.


#include "sampleActor.h"

// Sets default values
AsampleActor::AsampleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AsampleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AsampleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

