// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SchedulingSystem/TaskScheduler/Public/TaskScheduler.h"
#include "LlamaInferenceTask.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LlamaDialogueWidget.generated.h"

#define TARGET_INFERENCE_SPEED 45

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

	UFUNCTION(BlueprintCallable, Category="Game Performance")
	float GetAverageFPS();

	UFUNCTION(BlueprintCallable, Category="Game Performance")
	float GetInferenceSpeed();

	UFUNCTION(BlueprintCallable, Category="Game Performance")
	void SetTargetInferenceSpeed(const float Speed);

	UFUNCTION(BlueprintCallable, Category="Scheduler")
	void SetSchedulerState(const int State);
	
private:
	FString prompts[5];
	
};


