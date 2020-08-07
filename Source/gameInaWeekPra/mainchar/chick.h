// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "chick.generated.h"

UCLASS()
class GAMEINAWEEKPRA_API Achick : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	Achick();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* cameraBoom;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY()
	int animState;

	UPROPERTY(BlueprintReadWrite, Category = "kusavar")
	float doubleJumpPower = 500;
	
	UPROPERTY(BlueprintReadOnly, Category = "kusavar")
	float doubleJumpPowerItr = 500;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "par", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* partBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "pooo", meta = (AllowPrivateAccess = "true"))
	UParticleSystem* poo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForword();

	void jump();

};
