#pragma once
#include "Application.h"

#ifdef LG_PLATFORM_WINDOWS

extern Lifengine::Application* Lifengine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Lifengine::CreateApplication();
	app->Run();
	delete app;
}

#endif