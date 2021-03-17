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

void APawnTurret::HandleDestruction() 
{
    // Call base pawn class HandleDestruction to play effects.
    Super::HandleDestruction();
    Destroy();
}
//Called every frame
void APawnTurret::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);

    if(!PlayerCharacter || ReturnDistanceToPlayer() > FireRange)
    {
        return;
    }

    RotateTurret(PlayerCharacter->GetActorLocation());

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
        Fire();
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
