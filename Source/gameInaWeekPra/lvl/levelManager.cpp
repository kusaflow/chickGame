// Fill out your copyright notice in the Description page of Project Settings.


#include "levelManager.h"
#include "../kusaGameInstance.h"

// Sets default values
AlevelManager::AlevelManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AlevelManager::BeginPlay()
{
	Super::BeginPlay();
	initBlocks();
	
}

// Called every frame
void AlevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	int playerPosX = gameInst->playerXpos;

	if (playerPosX >= next_Milestone) {
		UpdateLevel();
	}

}

void AlevelManager::initBlocks() {

	for (int i = 0; i < 10; i++) {
		CreateLevelBlock();
		if (i == 2) {
			next_Milestone = xpos;

		}if (i == 5) {
			start = false;
		}

	}

}

void AlevelManager::CreateLevelBlock() {

	FActorSpawnParameters spawnPara;
	spawnPara.Owner = this;

	TArray<AActor*> blocks;
	
	UWorld* world = GetWorld();

	int wToSelect =11;

	if (!haspref) {
		//wToSelect = FMath::FRandRange(1,12);
	}
	else {
		haspref = false;
	}

	if (start)
		wToSelect = 1;

	float ysize = 1;

	int obsToDraw = 1;
	
	if (start)
		obsToDraw = 0;

	


	if (world && walkPath && ball){


		AActor* floor= world->SpawnActor<AActor>(walkPath, FVector(xpos + 1000, 0, -1000), FRotator(0), spawnPara);
		floor->SetActorScale3D(FVector(10, ysize, 1));
		blocks.Push(floor);

		//poo pwer ups
		if (((int)(FMath::FRandRange(1, 100))) % 2 == 0 && pooPower) {
			AActor* poo = world->SpawnActor<AActor>(pooPower, FVector(xpos + FMath::FRandRange(20, 1950), 0, 500), FRotator(0), spawnPara);
			blocks.Push(poo);
		}

		if (((int)(FMath::FRandRange(1, 100))) % 7 == 0 && pooDanger) {
			AActor* poo = world->SpawnActor<AActor>(pooDanger, FVector(xpos + FMath::FRandRange(20, 1950), 0, 500), FRotator(0), spawnPara);
			blocks.Push(poo);
		}

		if (wToSelect == 1) {
			for (int i = 0; i < 10; i++) {
				AActor* sp = world->SpawnActor<AActor>(walkPath, FVector(xpos + 100, 0, 0), FRotator(0), spawnPara);
				sp->SetActorScale3D(FVector(1, ysize,1));
				blocks.Push(sp);
				
				if (((int)(FMath::FRandRange(1, 100))) % 25 == 0 && obsToDraw == 1) {
					AActor* ob = world->SpawnActor<AActor>(ball, FVector(xpos + 100, 0, 60), FRotator(0), spawnPara);
					blocks.Push(ob);
					obsToDraw = 0;
				}

				xpos += 200;
			}	
		}
		else if (wToSelect == 2) {
			int zsz = 1;
			for (int i = 0; i < 10; i++) {
				AActor* sp = world->SpawnActor<AActor>(walkPath, FVector(xpos + 100, 0, 0), FRotator(0), spawnPara);
				if (i % 3 == 0)
					zsz = 2;
				else
					zsz = 1;

					sp->SetActorScale3D(FVector(1, ysize, zsz));
				blocks.Push(sp);
				
				if (((int)(FMath::FRandRange(1, 100))) % 25 == 0 && obsToDraw == 1 && zsz == 1) {
					AActor* ob = world->SpawnActor<AActor>(ball, FVector(xpos+100, 0, 60), FRotator(0), spawnPara);
					blocks.Push(ob);
					obsToDraw = 0;
				}
				xpos += 200;
			}
		}
		else if (wToSelect == 3) {
			for (int i = 0; i < 10; i++) {
				if (i % 3 == 0) {
					AActor* sp = world->SpawnActor<AActor>(walkPath, FVector(xpos + 100, 0, 0), FRotator(0), spawnPara);
					sp->SetActorScale3D(FVector(1, ysize, 2));
					blocks.Push(sp);
				}
				xpos += 200;
			}
		}
		else if (wToSelect == 4) {
			for (int i = 0; i < 10; i++) {
				if (i % 3 == 0) {
					AActor* sp = world->SpawnActor<AActor>(walkPath, FVector(xpos + 100, 0, 0), FRotator(0), spawnPara);
					sp->SetActorScale3D(FVector(1.0f, ysize, FMath::FRandRange(1.7f,2.3f)));
					blocks.Push(sp);
				}
				xpos += 200;
			}
			
		}
		else if (wToSelect == 5) {
			int zpos = -10;
			for (int i = 0; i < 20; i++) {
				if (i < 10) {
					zpos -= 10;
				}
				else {
					zpos += 10;
				}
				AActor* sp = world->SpawnActor<AActor>(walkPath, FVector(xpos + 50, 0, zpos), FRotator(0), spawnPara);
				sp->SetActorScale3D(FVector(0.5f, ysize, 1));
				blocks.Push(sp);

				if (((int)(FMath::FRandRange(1, 100))) % 25 == 0 && obsToDraw == 1 && i < 15) {
					AActor* ob = world->SpawnActor<AActor>(ball, FVector(xpos + 50, 0, zpos+60), FRotator(0), spawnPara);
					blocks.Push(ob);
					obsToDraw = 0;
				}

				xpos += 100;
			}

		}
		else if (wToSelect == 6) {
			int zpos = -10;
			for (int i = 0; i < 20; i++) {
				if (i < 10) {
					zpos -= 20;
				}
				else {
					zpos += 20;
				}
				AActor* sp = world->SpawnActor<AActor>(walkPath, FVector(xpos + 50, 0, zpos), FRotator(0), spawnPara);
				sp->SetActorScale3D(FVector(0.5f, ysize, 1));
				blocks.Push(sp);
				if (((int)(FMath::FRandRange(1, 100))) % 25 == 0 && obsToDraw == 1 && i<15) {
					AActor* ob = world->SpawnActor<AActor>(ball, FVector(xpos + 50, 0, zpos + 40), FRotator(0), spawnPara);
					blocks.Push(ob);
					obsToDraw = 0;
				}
				xpos += 100;
			}

		}
		else if (wToSelect == 7) {
			float zpos = 0;
			for (int i = 1; i <= 10; i++) {
				zpos += 40;
				if (i % 3 == 0) {
					AActor* sp = world->SpawnActor<AActor>(walkPath, FVector(xpos + 100, 0, zpos), FRotator(0), spawnPara);
					sp->SetActorScale3D(FVector(1 + 0.5f, ysize, 0.5f));
					blocks.Push(sp);
				}
				xpos += 200;
			}
			haspref = true;
			wToSelect = 1;
		}

		else if (wToSelect == 8) {
			int zpos = -10;
			for (int i = 0; i < 20; i++) {
				if (i < 10) {
					zpos -= 20;
				}
				else {
					zpos += 20;
				}
				if (((int)(FMath::FRandRange(1, 100))) % 4 == 0) {

					xpos += 100;
					continue;
				}
			
				AActor* sp = world->SpawnActor<AActor>(walkPath, FVector(xpos + 50, 0, zpos), FRotator(0), spawnPara);
				sp->SetActorScale3D(FVector(0.5f, ysize, 1));
				blocks.Push(sp);
				if (((int)(FMath::FRandRange(1, 100))) % 25 == 0 && obsToDraw == 1 && i < 15) {
					AActor* ob = world->SpawnActor<AActor>(ball, FVector(xpos + 50, 0, zpos + 40), FRotator(0), spawnPara);
					blocks.Push(ob);
					obsToDraw = 0;
				}

				xpos += 100;
			}

		}

		else if (wToSelect == 9) {
			for (int i = 0; i < 10; i++) {
				AActor* sp = world->SpawnActor<AActor>(walkPath, FVector(xpos + 100, 0, 0), FRotator(0), spawnPara);
				sp->SetActorScale3D(FVector(0.8f, ysize, 1));
				blocks.Push(sp);

				if (((int)(FMath::FRandRange(1, 100))) % 25 == 0 && obsToDraw == 1) {
					AActor* ob = world->SpawnActor<AActor>(ball, FVector(xpos + 100, 0, 60), FRotator(0), spawnPara);
					blocks.Push(ob);
					obsToDraw = 0;
				}

				xpos += 200;
			}
		}
		else if (wToSelect == 10) {
			for (int i = 0; i < 10; i++) {
				AActor* sp = world->SpawnActor<AActor>(noGravity, FVector(xpos + 100, 0, 0), FRotator(0), spawnPara);
				sp->SetActorScale3D(FVector(0.8f, ysize, 1));
				blocks.Push(sp);

				if (((int)(FMath::FRandRange(1, 100))) % 25 == 0 && obsToDraw == 1) {
					AActor* ob = world->SpawnActor<AActor>(ball, FVector(xpos + 100, 0, 60), FRotator(0), spawnPara);
					blocks.Push(ob);
					obsToDraw = 0;
				}

				xpos += 200;
			}
		}
		else if (wToSelect == 11) {
			for (int i = 0; i < 10; i++) {
				AActor* sp = world->SpawnActor<AActor>(goDown, FVector(xpos + 100, 0, 0), FRotator(0), spawnPara);
				sp->SetActorScale3D(FVector(0.8f, ysize, 1));
				blocks.Push(sp);

				if (((int)(FMath::FRandRange(1, 100))) % 25 == 0 && obsToDraw == 1) {
					AActor* ob = world->SpawnActor<AActor>(ball, FVector(xpos + 100, 0, 60), FRotator(0), spawnPara);
					blocks.Push(ob);
					obsToDraw = 0;
				}

				xpos += 200;
			}
		}

	}

	LB_array.Enqueue(blocks);
}

void AlevelManager::popBlock() {
	
	if (LB_array.IsEmpty()) {
		return;
	}
	TArray<AActor*> rem;
	LB_array.Peek(rem);
	LB_array.Pop();
	//UE_LOG(LogTemp, Warning, TEXT("%d"), rem.Num());
	if (rem.Num() >= 0) {
		while (rem.Num() != 0) {
			AActor* toDest = rem.Pop();
			if (toDest) {
				toDest->Destroy();
			}
		}
	}


}

void AlevelManager::UpdateLevel() {

	next_Milestone += 2000;

	CreateLevelBlock();
	popBlock();

}