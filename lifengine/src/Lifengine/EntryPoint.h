#pragma once
#include "Application.h"
#include "Log.h"

#ifdef LG_PLATFORM_WINDOWS

extern Lifengine::Application* Lifengine::CreateApplication();

int main(int argc, char** argv)
{
	Lifengine::Log::Init();
	LG_CORE_ERROR("Dummy Error!");
	int a = 5;
	LG_INFO("Initilized Client Log! Var={0}", a);

	auto app = Lifengine::CreateApplication();
	app->Run();
	delete app;
}

#endif