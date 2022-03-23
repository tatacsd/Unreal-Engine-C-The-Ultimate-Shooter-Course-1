// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Display a msg on the output log to make sure the function is called
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay() called!")); // Pass the text encoded in unicode

	//using brace initialization we are garanteed we will initialize (without entering a value it will be zero
	int myInt{ 42 };
	UE_LOG(LogTemp, Warning, TEXT("int myInt: %d"), myInt);
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

