#include "DelegateListener.h"
#include "EventsDelegatesCppGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADelegateListener::ADelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Crear un punto de luz
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");

	// Establecer el componente en el componente principal
	RootComponent = PointLight;

	// Apagar la luz al inicio del juego.
	PointLight->SetVisibility(false);

	// Cambiar el color para observarla mejor.
	PointLight->SetLightColor(FLinearColor::Blue);
}

// Called when the game starts or when spawned
void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();

	// Para prender la luz a traves de las clases con el delegado, se tiene que pasar a traves del GM.
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AEventsDelegatesCppGameModeBase * MyGameMode = Cast<AEventsDelegatesCppGameModeBase>(GameMode);

		if (MyGameMode != nullptr)
		{
			MyGameMode->MyStandardDelegate.BindUObject(this, &ADelegateListener::EnableLight);
		}
	}
	
}

// Called every frame
void ADelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Metodo para el delegado sin parametros
void ADelegateListener::EnableLight()
{
	PointLight->SetVisibility(true);
}
