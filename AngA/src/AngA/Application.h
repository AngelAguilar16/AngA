#pragma once
#include "Core.h"

namespace AngA {

	class ANGA_API Application{
	public:
		Application();
		~Application();

		void Run();
	};

	Application* CreateApplication();

}

