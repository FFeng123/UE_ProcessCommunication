// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Windows.h"

#include "UnnamedPipe.generated.h"
/**
 *
 */
UCLASS(Blueprintable)
class FFENGPROCESSCOMMUNICATION_API UUnnamedPipe : public UObject
{
	GENERATED_BODY()
private:
	HANDLE handle;
	UUnnamedPipe();
public:
	UFUNCTION(BlueprintCallable, Category = "FFeng进程间通信", meta = (DisplayName = "从命令行获取匿名管道句柄"))
	static UUnnamedPipe* GetUnnamedPipeFromCLI(FString name);

	UFUNCTION(BlueprintCallable, Category = "FFeng进程间通信", meta = (DisplayName = "读取所有数据"))
	FString ReadAllData(bool& succeed);

	UFUNCTION(BlueprintCallable, Category = "FFeng进程间通信", meta = (DisplayName = "写入数据"))
	bool WriteData(FString data);

	UFUNCTION(BlueprintCallable, Category = "FFeng进程间通信", meta = (DisplayName = "关闭管道"))
	bool ClosePipe();

	UFUNCTION(BlueprintPure, Category = "FFeng进程间通信", meta = (DisplayName = "获取管道句柄"))
	int64 GetHandle();
};
