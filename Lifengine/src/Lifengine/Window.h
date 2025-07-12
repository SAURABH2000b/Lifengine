#include "lgpch.h"

#include "Lifengine/Core.h"
#include "Lifengine/Events/Event.h"
#include "Log.h"

namespace Lifengine {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Lifentine",
			unsigned int width = 1280,
			unsigned int height = 620)
			: Title(title), Width(width), Height(height)
		{

		}
	};

	//Interface representing a desktop system based Window
	class LIFENGINE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		//Create() needs to be implemented by the platform's .cpp file
		static Window* Create(const WindowProps& props = WindowProps());
	};

}