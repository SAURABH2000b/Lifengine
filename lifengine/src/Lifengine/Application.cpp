#include "lgpch.h"
#include "Application.h"

#include "Lifengine/Events/ApplicationEvent.h"
#include "Lifengine/Log.h"

namespace Lifengine {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(100, 200);
		if (e.IsInCategory(EventCategoryApplication))
		{
			LG_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			LG_TRACE(e);
		}
		while (true);
	}

}

