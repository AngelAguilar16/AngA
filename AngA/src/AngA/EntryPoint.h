#pragma once

#ifdef AA_PLATFORM_WINDOWS
	extern AngA::Application* AngA::CreateApplication();

	int main(int argc, char** argv) {
		auto app = AngA::CreateApplication();
		app->Run();
		delete app;
	}
#endif