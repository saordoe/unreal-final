#include "C_BPAdvanced.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

AC_BPAdvanced::AC_BPAdvanced()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	RootComponent = CollisionComponent;
	CollisionComponent->InitSphereRadius(50.0f);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionComponent->SetCollisionResponseToAllChannels(ECR_Block);
	CollisionComponent->SetNotifyRigidBodyCollision(true);

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetMesh"));
	TargetMesh->SetupAttachment(RootComponent);
	TargetMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	RunningTime = 0.0f;
	bIsHidden = false;
}

void AC_BPAdvanced::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	CollisionComponent->OnComponentHit.AddDynamic(this, &AC_BPAdvanced::OnTargetHit);
}

void AC_BPAdvanced::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsHidden)
	{
		return;
	}

	RunningTime += DeltaTime;

	float ZOffset = FMath::Sin(RunningTime * FloatSpeed) * FloatAmplitude;
	FVector NewLocation = StartLocation + FVector(0.0f, 0.0f, ZOffset);
	SetActorLocation(NewLocation);

	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += RotationSpeed * DeltaTime;
	SetActorRotation(NewRotation);
}

void AC_BPAdvanced::OnTargetHit(UPrimitiveComponent * HitComponent, AActor * OtherActor,
	UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	if (OtherActor && OtherActor != this && !bIsHidden)
	{
		UE_LOG(LogTemp, Warning, TEXT("Target hit by: %s"), *OtherActor->GetName());

		bIsHidden = true;
		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);

		FTimerHandle RespawnTimerHandle;
		GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &AC_BPAdvanced::RespawnTarget, RespawnDelay, false);
	}
}

void AC_BPAdvanced::RespawnTarget()
{
	FVector NewLocation = GetRandomRespawnLocation();
	SetActorLocation(NewLocation);
	StartLocation = NewLocation;

	RunningTime = 0.0f;

	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	bIsHidden = false;
}

FVector AC_BPAdvanced::GetRandomRespawnLocation()
{
	if (bRandomizeRespawnOffset)
	{
		float RandomX = FMath::FRandRange(-RespawnOffset.X, RespawnOffset.X);
		float RandomY = FMath::FRandRange(-RespawnOffset.Y, RespawnOffset.Y);
		float RandomZ = FMath::FRandRange(-RespawnOffset.Z, RespawnOffset.Z);

		return StartLocation + FVector(RandomX, RandomY, RandomZ);
	}
	else
	{
		return StartLocation + RespawnOffset;
	}
}