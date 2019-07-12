#include <aapch.h>
#include "Application.h"
#include "AngA/Events/ApplicationEvent.h"
#include "AngA/Log.h"

namespace AngA {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {

		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			ANGA_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			ANGA_TRACE(e);
		}

		while (true);
	}
}
