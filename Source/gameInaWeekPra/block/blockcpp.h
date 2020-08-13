// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "blockcpp.generated.h"

UCLASS()
class GAMEINAWEEKPRA_API Ablockcpp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Ablockcpp();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "mesh")
	class UStaticMeshComponent* block;

	UPROPERTY(EditAnywhere, Category = "material")
		class UMaterial* mat1;
	UPROPERTY(EditAnywhere, Category = "material")
		class UMaterial* mat2;
	UPROPERTY(EditAnywhere, Category = "material")
		class UMaterial* mat3;
	UPROPERTY(EditAnywhere, Category = "material")
		class UMaterial* mat4;
	UPROPERTY(EditAnywhere, Category = "material")
		class UMaterial* mat5;
	UPROPERTY(EditAnywhere, Category = "material")
		class UMaterial* mat6;
	UPROPERTY(EditAnywhere, Category = "material")
		class UMaterial* mat7;
	UPROPERTY(EditAnywhere, Category = "material")
		class UMaterial* mat8;
	UPROPERTY(EditAnywhere, Category = "material")
		class UMaterial* mat9;
	UPROPERTY(EditAnywhere, Category = "material")
		class UMaterial* mat10;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
