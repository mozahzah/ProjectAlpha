// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PreSmokeActor.h"
#include "ProjectAlphaMainCharacter.generated.h"


class AWeapon;
class APreSmokeActor;
class UParticleSystemComponent;

UCLASS()
class PROJECTALPHA_API AProjectAlphaMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AProjectAlphaMainCharacter();
	UPROPERTY(BlueprintReadOnly) bool bIsMovingFwd;
	UPROPERTY(BlueprintReadOnly) bool bIsMovingBwd;
	UPROPERTY(BlueprintReadOnly) bool bIsMovingRight;
	UPROPERTY(BlueprintReadOnly) bool bIsMovingLeft;
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUp(float AxisValue);
	void LookRight(float AxisValue);
	void Sprint();
	void NotSprint();
	void SnapFinger();
	bool bIsSprinting = false;
	void GetSurfaceMaterial();
	void ApplyOcclusionAndObstruction(FHitResult Hit);
	TSubclassOf<APreSmokeActor> GetPreSmoke();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	
	void GetFocusPoint();
	
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AWeapon> WeaponClass;

	UPROPERTY(BlueprintReadOnly)
	AWeapon* Weapon;

	UPROPERTY(EditAnywhere)
	UParticleSystemComponent* WeaponLeftHand = nullptr;

	UPROPERTY(EditAnywhere)
	UParticleSystemComponent* WeaponRightHand = nullptr;

	APreSmokeActor* PreSmoke;
	UPROPERTY(EditAnywhere)
	TSubclassOf<APreSmokeActor> PreSmokeBlueprint;

	UPROPERTY(EditAnywhere)
	float Health = 100.f;

	UFUNCTION(BlueprintCallable)
	void OnFootStepEvent();

	class UAkComponent* AkMainComponent = nullptr;

	UPROPERTY(EditAnywhere, Category = "Wwise")
    class UAkAudioEvent* FootStepEvent = nullptr;

	UPROPERTY(EditAnywhere, Category = "Wwise")
	class UAkAudioEvent* FingerSnapEvent = nullptr;

    class UAkSwitchValue* CurrentSwitch = nullptr;
	FString SurfaceType;
	int32 PlayingId = 0;

	UPROPERTY(EditAnywhere)
	bool bRVAPisOn = false;

	class UAkGameObject* CharacterAkGameObject;

};
