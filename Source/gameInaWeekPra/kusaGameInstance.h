// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "kusaGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAMEINAWEEKPRA_API UkusaGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "kusaVar")
	int playerXpos = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "kusaVar")
	int chickMat = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "kusaVar")
	float PowerTimer = 0;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "kusaVar")
	bool pooMterAnim = 0;


	
};
