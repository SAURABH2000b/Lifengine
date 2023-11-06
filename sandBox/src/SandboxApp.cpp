#include<Lifengine.h>

class Sandbox : public Lifengine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Lifengine::Application* Lifengine::CreateApplication()
{
	return new Sandbox;
}
