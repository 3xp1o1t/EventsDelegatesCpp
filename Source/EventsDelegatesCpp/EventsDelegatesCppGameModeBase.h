// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EventsDelegatesCppGameModeBase.generated.h"

/**
 * 
 */

// Delegado sin parametros. (Delegado = funcion de tipo puntero, mas segura).
DECLARE_DELEGATE(FStandardDelegateSignature)

UCLASS()
class EVENTSDELEGATESCPP_API AEventsDelegatesCppGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	// Delegado.
	FStandardDelegateSignature MyStandardDelegate;

};
