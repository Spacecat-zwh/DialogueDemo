// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LlamaInferenceTask.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LlamaDialogueWidget.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGUEDEMO_API ULlamaDialogueWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	FLlamaInferenceTask* InferenceTask;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Llama Dialogue")
	FString Content;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Llama Dialogue")
	int32 Order;
	
	ULlamaDialogueWidget(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintCallable, Category="Llama Dialogue")
	bool GetNextPrompt();

	UFUNCTION(BlueprintCallable, Category="Llama Dialogue")
	void LlamaInference();
	
private:
	FString prompts[5];
	
};


