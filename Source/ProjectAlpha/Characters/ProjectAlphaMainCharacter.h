// Copyright mozahzah.io 2022

#pragma once

#include "CoreMinimal.h"

#include "AkAudioBank.h"
#include "GameFramework/Character.h"
#include "ProjectAlphaMainCharacter.generated.h"

class AWeapon;
class APreSmokeActor;
class UAkAudioEvent;
class UAkComponent;
class UParticleSystemComponent;

UCLASS()
class PROJECTALPHA_API AProjectAlphaMainCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(EditAnywhere, Category = "Wwise") 
	UAkAudioBank* init;

	UPROPERTY(EditAnywhere, Category = "Wwise") 
	UAkAudioBank* test;
	// MAIN
	AProjectAlphaMainCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(EditAnywhere) float Health = 100.f;

	// Movement and Animation
	UPROPERTY(BlueprintReadOnly) 
	bool bIsMovingFwd;

	UPROPERTY(BlueprintReadOnly) 
	bool bIsMovingBwd;

	UPROPERTY(BlueprintReadOnly) 
	bool bIsMovingRight;

	UPROPERTY(BlueprintReadOnly) 
	bool bIsMovingLeft;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUp(float AxisValue);
	void LookRight(float AxisValue);
	void Sprint();
	void NotSprint();
	bool bIsSprinting = false;
	
	// ABILITIES
	float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(BlueprintReadOnly) 
	AWeapon* Weapon;

	UPROPERTY(EditAnywhere) 
	UParticleSystemComponent* WeaponLeftHand = nullptr;

	UPROPERTY(EditAnywhere) 
	UParticleSystemComponent* WeaponRightHand = nullptr;

	TSubclassOf<APreSmokeActor> GetPreSmoke();

	APreSmokeActor* PreSmoke;

	UPROPERTY(EditAnywhere) 
	TSubclassOf<APreSmokeActor> PreSmokeBlueprint;

	// AUDIO
	UFUNCTION(BlueprintCallable) 
	void OnFootStepEvent(); 

	void GetSurfaceMaterial();
	void SnapFinger();
	void ApplyOcclusionAndObstruction(FHitResult Hit);
	void GetFocusPoint();
	void MakeFast();
	void ApplyPassBy();
	bool yes = false;

	// WWISE Objects
	class UAkComponent* AkMainComponent = nullptr;

	UPROPERTY(EditAnywhere, Category = "Wwise") 
	UAkAudioEvent* FootStepEvent = nullptr;

	UPROPERTY(EditAnywhere, Category = "Wwise") 
	UAkAudioEvent* SnapEvent = nullptr;

	UPROPERTY(EditAnywhere, Category = "Wwise") 
	UAkAudioEvent *PassByEvent = nullptr;

    class UAkSwitchValue* CurrentSwitch = nullptr;
	FString SurfaceType;
};