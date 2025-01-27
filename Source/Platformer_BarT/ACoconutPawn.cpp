#include "ACoconutPawn.h"

// Sets default values
AACoconutPawn::AACoconutPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 1.	Root Component
	Root_component = CreateDefaultSubobject<USceneComponent>(TEXT("Root_component"));
	RootComponent = Root_component;
	Root_component->SetWorldScale3D(FVector(1.0, 1.0, 1.0));

	// 2.	Coconut ball mesh
	Coconut_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coconut_mesh"));
	Coconut_mesh->SetupAttachment(Root_component);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Coconut_Mesh_Asset(TEXT("/Script/Engine.StaticMesh'/Game/Bartender/Meshes/General/Coconut/SM_Coconut.SM_Coconut'"));
	Coconut_mesh->SetStaticMesh(Coconut_Mesh_Asset.Object);
	Coconut_mesh->SetWorldScale3D(FVector(0.0425, 0.0425, 0.0425));
		// Physic setting
	Coconut_mesh->SetSimulatePhysics(true);
	Coconut_mesh->SetMassOverrideInKg(NAME_None, 1000.0f);
	Coconut_mesh->SetLinearDamping(0.5f);
	Coconut_mesh->SetAngularDamping(0.1f);
		// Collision setting
	Coconut_mesh->SetCollisionProfileName(TEXT("Coconut_ball")); // Preset in Project Setting
		// Other
	Coconut_mesh->BodyInstance.bLockXTranslation = true;
	Coconut_mesh->BodyInstance.bLockYRotation = true;
	Coconut_mesh->BodyInstance.bLockZRotation = true;
	Coconut_mesh->bAlwaysCreatePhysicsState = true;

	// 3.	Coconut sphere collision
	Coconut_sphere_collision = CreateDefaultSubobject<USphereComponent>(TEXT("Coconut_sphere_collision"));
	Coconut_sphere_collision->SetupAttachment(Coconut_mesh);
	Coconut_sphere_collision->SetSphereRadius(1650.0f);
		// Collision setting
	Coconut_sphere_collision->SetCollisionProfileName(TEXT("Blockall"));
	Coconut_sphere_collision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	Coconut_sphere_collision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	Coconut_sphere_collision->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Ignore); // Mantle to ignore (default block)
																 
	// 4.	Platform mesh
	Platform_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform_mesh"));
	Platform_mesh->SetupAttachment(Root_component);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Platform(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	Platform_mesh->SetStaticMesh(Platform.Object);
	static ConstructorHelpers::FObjectFinder<UMaterial> Cube_material(TEXT("/Script/Engine.Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'"));
	Platform_mesh->SetMaterial(0, Cube_material.Object);
	Platform_mesh->SetWorldScale3D(FVector(0.5, 0.6, 0.1));
		//	Collision setting
	Platform_mesh->SetCollisionProfileName(TEXT("Spectator"));
	Platform_mesh->SetCollisionObjectType(ECC_WorldDynamic);
	Platform_mesh->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Ignore); // Mantle to ignore (default block)
	Platform_mesh->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Ignore);
	Platform_mesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	Platform_mesh->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Ignore); // Interactable to ignore (default overlap)

}

// Called when the game starts or when spawned
void AACoconutPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AACoconutPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AACoconutPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

