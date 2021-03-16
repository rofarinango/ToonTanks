// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Engine/EngineTypes.h"

//Called when the game starts or when spawned
void APawnTurret::BeginPlay() 
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
}
//Called every frame
void APawnTurret::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);
}



void APawnTurret::CheckFireCondition() 
{
    // If Player == null || is Dead THEN BAIL!!

    // If Player Is in range THEN FIRE!!

    UE_LOG(LogTemp, Warning, TEXT("Fire condition check"));
}
