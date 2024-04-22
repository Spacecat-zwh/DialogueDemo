// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/LlamaDialogueWidget.h"

ULlamaDialogueWidget::ULlamaDialogueWidget(const FObjectInitializer& ObjectInitialize)
	:Super(ObjectInitialize)
{
	Order = 0;
	Content = TEXT("What can I do for you?");
	prompts[0] = TEXT("What are the three primary colors?");
	prompts[1] = TEXT("Generate a short story about 300 words.");
	prompts[2] = TEXT("Could you describe the composition of atoms?");
	prompts[3] = TEXT("Provide examples of a non-renewable source of energy.");
	InferenceTask = new FLlamaInferenceTask("", &Content, &Order);
}

bool ULlamaDialogueWidget::GetNextPrompt()
{
	if (Order < 8)
	{
		Content = prompts[Order / 2];
		std::string stdStr(TCHAR_TO_UTF8(*Content));
		InferenceTask->prompt = stdStr;
		Order += 1;
		return true;
	}
	return false;
}

void ULlamaDialogueWidget::LlamaInference()
{
	Content = TEXT("generating...");
	FRunnableThread::Create(InferenceTask, TEXT("InferenceTask"), 0, TPri_Normal);
}

float ULlamaDialogueWidget::GetAverageFPS()
{
	extern ENGINE_API float GAverageFPS;
	return GAverageFPS;
}

float ULlamaDialogueWidget::GetInferenceSpeed()
{
	return FLlamaModel::GetInstance().GetInferenceSpeed();
}

void ULlamaDialogueWidget::SetTargetInferenceSpeed(const float Speed)
{
	FTaskScheduler::GetInstance().SetTargetInferenceSpeed(Speed);
}

void ULlamaDialogueWidget::SetSchedulerState(const int State)
{
	FTaskScheduler::GetInstance().SetSchedulerState(State);
}
















