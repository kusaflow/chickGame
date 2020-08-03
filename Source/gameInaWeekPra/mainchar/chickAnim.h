// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "chickAnim.generated.h"

/**
 * 
 */
UCLASS()
class GAMEINAWEEKPRA_API UchickAnim : public UAnimInstance
{
	GENERATED_BODY()

	UchickAnim();


public :
	int animState = 0;
	

	UFUNCTION(BlueprintCallable, Category = "AnimProperty")
	void update();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	class Achick* player;

};
