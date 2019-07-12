#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace AngA {

	class ANGA_API Application{
	public:
		Application();
		~Application();

		void Run();
	};

	Application* CreateApplication();

}

