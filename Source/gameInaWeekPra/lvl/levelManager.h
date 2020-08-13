// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "levelManager.generated.h"

UCLASS()
class GAMEINAWEEKPRA_API AlevelManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AlevelManager();


	UPROPERTY(EditDefaultsOnly, category = "WalkPAth")
	TSubclassOf<class AActor> walkPath;

	UPROPERTY(EditDefaultsOnly, category = "WalkPAth")
	TSubclassOf<class AActor> noGravity;

	UPROPERTY(EditDefaultsOnly, category = "WalkPAth")
	TSubclassOf<class AActor> goDown;

	UPROPERTY(EditDefaultsOnly, category = "WalkPAth")
	TSubclassOf<class AActor> goUp;


	///block End

	UPROPERTY(EditDefaultsOnly, category = "obstacle")
	TSubclassOf<class AActor> ball;

	UPROPERTY(EditDefaultsOnly, category = "obstacle")
	TSubclassOf<class AActor> spinWheel;

	UPROPERTY(EditDefaultsOnly, category = "pooPowerUp")
	TSubclassOf<class AActor> pooPower;

	UPROPERTY(EditDefaultsOnly, category = "pooPowerUp")
	TSubclassOf<class AActor> pooDanger;

	TQueue<TArray<AActor*>> LB_array;

	UPROPERTY(BlueprintReadOnly, Category = "kusavar")
	int next_Milestone;

	int xpos = -500000;

	bool start = true;

	bool haspref = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void UpdateLevel();

	void initBlocks();

	void CreateLevelBlock();

	void popBlock();


};
