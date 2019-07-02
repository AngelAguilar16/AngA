#include <AngA.h>

class Sandbox : public AngA::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

AngA::Application* AngA::CreateApplication(){
	return new Sandbox();
}