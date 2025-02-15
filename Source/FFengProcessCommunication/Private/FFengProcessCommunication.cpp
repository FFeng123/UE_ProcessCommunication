// Fill out your copyright notice in the Description page of Project Settings.

#include "FFengProcessCommunication.h"
#include "Logging.h"

#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FFFengProcessCommunication"

void FFFengProcessCommunication::StartupModule()
{
}

void FFFengProcessCommunication::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFFengProcessCommunication, FFengProcessCommunication);