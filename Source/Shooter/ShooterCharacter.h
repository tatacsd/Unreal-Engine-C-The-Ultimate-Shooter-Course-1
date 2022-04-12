// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class SHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called for forwards/backwards inputs
	void MoveForward(float Value);

	// Called for side to side input
	void MoveRight(float Valeu);

	/**
		Called via input to turn at a give rate
		@param Rate  This is a normalized rate, ie 1.0 means 100 % of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
		Called via input to look up/down at a give rate
		@param Rate  This is a normalized rate, ie 1.0 means 100 % of desired rate
	*/
	void LookUpAtRate(float Rate);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

// forward declaring -> promise that the class exist
private:
	/** Camera boom positioning the camera behind the character*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom; // just address

	/** Camera that follows the character*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** Base turn rate in degrees/sec. Other scaling may affect final turn rate*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. v */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseLookUpRate;

public:
	/** returns CameraBoom subobject*/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; } // HELP IN PERFORMANCE the forceinline

	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; } 

};
