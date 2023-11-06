#pragma once
#include "Core.h"
namespace Lifengine {

	class LIFENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be defined in Lifegine client
	Application* CreateApplication();

}

