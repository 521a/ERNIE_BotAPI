// 秦伟杰 版权所有

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "HttpModule.h"
#include "CallWXYY.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnWXYYResponseRecieved, const FString &, Message, const FString &, errorMessage, bool, Success);
UCLASS()
class WXYY_API_API UCallWXYY : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	FString Token = "";

	TMap<FString, FString> messagesMap = {};

	UPROPERTY(BlueprintAssignable, Category = "WXYY_API")
	FOnWXYYResponseRecieved Finished;

private:
	// call wxyy
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "WXYY_API")
	static UCallWXYY *CallWXYY(UObject *WorldContextObject, const FString &Token, const TMap<FString, FString> &messagesMap);

	virtual void Activate() override;

	void OnResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool WasSuccessful);
	const UObject *WorldContextObject;
};
