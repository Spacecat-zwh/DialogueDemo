#pragma once

#include "LlamaModel/Public/LlamaModel.h"


DECLARE_DELEGATE(FInferenceCompletedDelegate);

class DLLEXPORT FLlamaInferenceTask: public FRunnable
{
public:

	std::string prompt;
	
	FString* content;

	int32* order;
	
	FLlamaInferenceTask(std::string prompt, FString* content, int32* order): prompt(prompt), content(content), order(order) {}
	//
	// FInferenceCompletedDelegate OnInferenceCompleted;
	//
	// void DoTask(ENamedThreads::Type CurrentThread, const FGraphEventRef& MyCompletionGraphEvent);
	//
	// static ENamedThreads::Type GetDesiredThread() { return ENamedThreads::AnyThread; }
	// static ESubsequentsMode::Type GetSubsequentsMode() { return ESubsequentsMode::TrackSubsequents; }
	//
	// FORCEINLINE TStatId GetStatId() const
	// {
	// 	RETURN_QUICK_DECLARE_CYCLE_STAT(FLlamaInferenceTask, STATGROUP_ThreadPoolAsyncTasks);
	// }
	virtual bool Init();
	virtual uint32_t Run();
	virtual void Exit();
};
