// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Actor.h"
#include "../Characters/CharacterBase.h"

//Called when the game starts or when spawned
void APawnTurret::BeginPlay() 
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

    PlayerCharacter = Cast<ACharacterBase>(UGameplayStatics::GetPlayerCharacter(this, 0));
}
//Called every frame
void APawnTurret::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);
}



void APawnTurret::CheckFireCondition() 
{
    // If Player == null || is Dead THEN BAIL!!
    if(!PlayerCharacter)
    {
        return;
    }

    // If Player Is in range THEN FIRE!!
    if(ReturnDistanceToPlayer() <= FireRange)
    {
        // Fire
        UE_LOG(LogTemp, Warning, TEXT("Fire condition Success"));
    }

    
}

float APawnTurret::ReturnDistanceToPlayer() 
{
    if(!PlayerCharacter)
    {
        return 0.0f;
    }
    return FVector::Dist(PlayerCharacter->GetActorLocation(), GetActorLocation());
}
