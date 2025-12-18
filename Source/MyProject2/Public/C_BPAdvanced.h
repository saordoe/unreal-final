// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_BPAdvanced.generated.h"

UCLASS(Blueprintable, BlueprintType)
class MYPROJECT2_API AC_BPAdvanced : public AActor
{
	GENERATED_BODY()

public:
	AC_BPAdvanced();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* TargetMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* CollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float FloatAmplitude = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float FloatSpeed = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float RotationSpeed = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Respawn")
	float RespawnDelay = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Respawn")
	FVector RespawnOffset = FVector(200.0f, 200.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Respawn")
	bool bRandomizeRespawnOffset = true;

private:
	float RunningTime;
	FVector StartLocation;
	bool bIsHidden;

	UFUNCTION()
	void OnTargetHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void RespawnTarget();
	FVector GetRandomRespawnLocation();
};