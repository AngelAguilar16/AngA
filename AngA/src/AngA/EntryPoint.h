#pragma once

#ifdef AA_PLATFORM_WINDOWS
	extern AngA::Application* AngA::CreateApplication();

	int main(int argc, char** argv) {
		AngA::Log::Init();
		ANGA_CORE_WARN("Log Inicializado!");
		ANGA_INFO("Bienvenido a AngA Game Engine!");

		auto app = AngA::CreateApplication();
		app->Run();
		delete app;
	}
#endif