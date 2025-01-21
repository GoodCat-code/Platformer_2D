#pragma once

#include "CoreMinimal.h"
#include "ECoctails.generated.h"

UENUM(BlueprintType, meta = (ToolTip = "List of coctails")) enum class ECoctails : uint8
{
	Coconut UMETA(DisplayName = "Coconut"),
	Other UMETA(DisplayName = "Other"),
	None UMETA(DisplayName = "None"),
};
