#pragma once

#include "CoreMinimal.h"
#include "Ecoctails.h"
#include "SThrowParams.generated.h"

USTRUCT(BlueprintType) struct FThrowParams
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) ECoctails Coctail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool isEnchanted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AActor *Main_Character;
};