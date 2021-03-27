/*
* Override Events
* Override ActorOverlap Events to do something
* when actor overlap another actor.
* 4.26.1
*/

#include "MyTriggerVolume.h"
#include "EventsDelegatesCppGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyTriggerVolume::AMyTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Crear nuevo componente para la instancia y inicializarlo.
	TriggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");
	TriggerZone->SetBoxExtent(FVector(200, 200, 100));
}

// Called when the game starts or when spawned
void AMyTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Implentacion de las funciones para detertar solapados.
void AMyTriggerVolume::NotifyActorBeginOverlap(AActor* OtherActor)
{
	// Quien lo esta tocando?
	auto Message = FString::Printf(TEXT("%s esta dentro de mi rango."), *(OtherActor->GetName()));

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);

	// Ejecutar el delegado de GM y llamar a la funcion EnableLight en Delegate Listener.cpp
	UWorld* TheWorld = GetWorld();

	if (TheWorld != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AEventsDelegatesCppGameModeBase* MyGameMode = Cast<AEventsDelegatesCppGameModeBase>(GameMode);

		if (MyGameMode != nullptr)
		{
			MyGameMode->MyStandardDelegate.ExecuteIfBound();
		}
	}
}

void AMyTriggerVolume::NotifyActorEndOverlap(AActor* OtherActor)
{
	// Quien dejo de tacarlo?
	auto Message = FString::Printf(TEXT("%s ya no me esta tocando."), *(OtherActor->GetName()));

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, Message);
}

