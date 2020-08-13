// Fill out your copyright notice in the Description page of Project Settings.


#include "blockcpp.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
Ablockcpp::Ablockcpp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	block = CreateDefaultSubobject<UStaticMeshComponent>("block");
	RootComponent = block;

}

// Called when the game starts or when spawned
void Ablockcpp::BeginPlay()
{
	Super::BeginPlay();

	if (mat1 && mat2 && mat3 && mat4 && mat5 &&
		mat6 && mat7 && mat8 && mat9 && mat10) {

		int m = (int)FMath::FRandRange(1, 11);
		switch (m)
		{
		case 1:
			block->SetMaterial(0, mat1);
			break;
		case 2:
			block->SetMaterial(0, mat2);
			break;
		case 3:
			block->SetMaterial(0, mat3);
			break;
		case 4:
			block->SetMaterial(0, mat4);
			break;
		case 5:
			block->SetMaterial(0, mat5);
			break;
		case 6:
			block->SetMaterial(0, mat6);
			break;
		case 7:
			block->SetMaterial(0, mat7);
			break;
		case 8:
			block->SetMaterial(0, mat8);
			break;
		case 9:
			block->SetMaterial(0, mat9);
			break;
		case 10:
			block->SetMaterial(0, mat10);
			break;
		default:
			block->SetMaterial(0, mat1);
			break;

		}
	}
	else {
		if (mat1)
			block->SetMaterial(0, mat1);
	}


	
}

// Called every frame
void Ablockcpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

