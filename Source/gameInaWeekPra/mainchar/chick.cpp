// Fill out your copyright notice in the Description page of Project Settings.


#include "chick.h"
#include "Camera/CameraComponent.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "../kusaGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"

// Sets default values
Achick::Achick()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	cameraBoom->SetupAttachment(RootComponent);
	cameraBoom->bDoCollisionTest = false;
	cameraBoom->TargetArmLength = 800;
	cameraBoom->SocketOffset = FVector(0.f, 0.f, 0.f);
	cameraBoom->SetRelativeRotation(FRotator(-10, -90, 0));
	//cameraBoom->RelativeRotation = FRotator(0.f, 0.f, 0.f);
	cameraBoom->bUsePawnControlRotation = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName);


	partBox = CreateDefaultSubobject<UBoxComponent>(TEXT("poo"));
	partBox->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void Achick::BeginPlay()
{
	Super::BeginPlay();
	animState = 0;
	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	gameInst->chickMat = 1;
	gameInst->PowerTimer = 0;
	
}

// Called every frame
void Achick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveForword();

	if (animState == 1) {
		if (GetCharacterMovement()->Velocity.Z == 0) {
			animState = 2;
		}
	}

	if (doubleJumpPower <= 0) {
		doubleJumpPower = 0;
	}
	if (doubleJumpPower >= 500) {
		doubleJumpPower = 500;
	}

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	gameInst->playerXpos = GetRootComponent()->GetComponentLocation().X;


	//mat of chicken 
	if (gameInst->chickMat == 1) {
		GetCharacterMovement()->MaxWalkSpeed = 500;
		GetCharacterMovement()->JumpZVelocity = 500;
	}
	else if (gameInst->chickMat == 2) {

		GetCharacterMovement()->MaxWalkSpeed = 1000;
		GetCharacterMovement()->JumpZVelocity = 800;
	}
	else if (gameInst->chickMat == 3) {
		doubleJumpPower = 500;
		GetCharacterMovement()->MaxWalkSpeed = 700;
		GetCharacterMovement()->JumpZVelocity = 600;
	}


	if (gameInst->PowerTimer > 0) {
		gameInst->PowerTimer -= 60 * DeltaTime;
	}
	else {
		gameInst->chickMat = 1;
	}

	if (doubleJumpPower > doubleJumpPowerItr) {
		doubleJumpPowerItr += 300 * DeltaTime;
	}

	if (doubleJumpPower < doubleJumpPowerItr) {
		doubleJumpPowerItr -= 300 * DeltaTime;
	}

	if (RootComponent->GetComponentLocation().Z <= -400) {
		UGameplayStatics::OpenLevel(GetWorld(), "gameover");
	}
}

// Called to bind functionality to input
void Achick::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("jump", IE_Pressed, this, &Achick::jump);

}

void Achick::MoveForword() {
	if (Controller != nullptr) {

		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, 1);
	}
}

void Achick::jump() {
	if (GetCharacterMovement()->IsFalling()) {
		if (doubleJumpPower >= 60) {
			LaunchCharacter(FVector(100, 0, 500), false, true);
			doubleJumpPower -= 60;

			UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
			gameInst->pooMterAnim = true;


			if (poo && GetWorld()) {
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), poo, partBox->GetComponentLocation(), FRotator(0), true);
			}
		}
		if (doubleJumpPower <= 0) {
			doubleJumpPower = 0;
		}
		return;
	}
	animState = 1;
	Jump();
}