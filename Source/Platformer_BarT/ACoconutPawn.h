#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SphereComponent.h"
#include "SThrowParams.h"
#include "ACoconutPawn.generated.h"

UCLASS()
class PLATFORMER_BART_API AACoconutPawn : public APawn
{
	GENERATED_BODY()

public:
	AACoconutPawn();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components") USceneComponent* Root_component; // Root Component
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components") UStaticMeshComponent* Coconut_mesh; // Coconut ball
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components") USphereComponent* Coconut_sphere_collision;	// Sphere coliision for coconut ball
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components") UStaticMeshComponent* Platform_mesh;	// Platform mesh for character mounting

	UPROPERTY(BlueprintReadWrite, EditAnywhere) bool is_snapped = false;	// character snapped to the coconut ball
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true")) FVector outside_velocity;	// starting velocity from outside
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true")) FThrowParams throw_parametres;	//	SThrowParams.h

protected:
	virtual void BeginPlay() override;

};
