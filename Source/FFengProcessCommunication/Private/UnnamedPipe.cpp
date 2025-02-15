// Fill out your copyright notice in the Description page of Project Settings.


#include "UnnamedPipe.h"
#include "Misc/CommandLine.h"

UUnnamedPipe::UUnnamedPipe() : handle(0)
{
}

UUnnamedPipe* UUnnamedPipe::GetUnnamedPipeFromCLI(FString name)
{
	int64 value;
	FParse::Value(FCommandLine::Get(), *name, value);
	if (value != 0)
	{
		UUnnamedPipe* pipe = NewObject<UUnnamedPipe>();
		pipe->handle = (HANDLE)value;
		return pipe;
	}

	return nullptr;
}

FString UUnnamedPipe::ReadAllData(bool& succeed)
{
	DWORD dwRead;
	char buffer[128];
	BOOL bSuccess = FALSE;
	FString str;
	do
	{
		bSuccess = ReadFile(handle, buffer, 128, &dwRead, NULL);
		if (!bSuccess || dwRead == 0)
		{
			break;
		}
		str += UTF8_TO_TCHAR(buffer);
	} while (dwRead > 0);

	if (str.IsEmpty())
	{
		succeed = false;
		return "";
	}
	succeed = true;
	return str;
}

bool UUnnamedPipe::WriteData(FString data)
{
	char* buffer = TCHAR_TO_UTF8(*data);
	DWORD dwWritten;
	BOOL bSuccess = WriteFile(handle, buffer, strlen(buffer), &dwWritten, NULL);
	return bSuccess;
}

bool UUnnamedPipe::ClosePipe()
{
	return CloseHandle(handle);
}

int64 UUnnamedPipe::GetHandle()
{
	return int64(handle);
}
