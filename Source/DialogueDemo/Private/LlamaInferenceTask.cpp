#include "../Public/LlamaInferenceTask.h"

// void FLlamaInferenceTask::DoTask(ENamedThreads::Type CurrentThread, const FGraphEventRef& MyCompletionGraphEvent)
// {
// 	FLlamaModel::GetInstance().Inference(prompt, content);
// 	
// 	OnInferenceCompleted.ExecuteIfBound();
// }

bool FLlamaInferenceTask::Init()
{
	return true;
}

uint32_t FLlamaInferenceTask::Run()
{
	FLlamaModel::GetInstance().Inference(prompt, content);
	return 0;
}

void FLlamaInferenceTask::Exit()
{
	(*order) += 1;
}








