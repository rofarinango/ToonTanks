// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class USpringArmComponent;
class UStaticMeshComponent;
class UCameraComponent;
class USceneComponent;
class APlayerController;
class AProjectileBase;
class UHealthComponent;
UCLASS()
class TOONTANKS_API ACharacterBase :  public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();
	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	USceneComponent* ProjectileSpawnPoint;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UHealthComponent* HealthComponent;
	// Variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile Type")
	TSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* DeathParticle;
	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* DeathSound;
	UPROPERTY(EditAnywhere, Category="Effects")
	TSubclassOf<UCameraShake> DeathShake;

protected:

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Rotate(float Value);
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	float BaseTurnRate;

	APlayerController* PlayerControllerRef;
	bool bIsPlayerAlive = true;

	virtual void BeginPlay() override;

	void RotateTurret(FVector LookAtTarget);

	void Fire();

	

public:

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void HandleDestruction();

	bool GetIsPlayerAlive();


};