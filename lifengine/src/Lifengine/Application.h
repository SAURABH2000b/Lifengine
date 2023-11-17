#pragma once

#include "Core.h"
#include "Events/Event.h"
#include"Window.h"

namespace Lifengine {

	class LIFENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in Lifegine client
	Application* CreateApplication();

}

