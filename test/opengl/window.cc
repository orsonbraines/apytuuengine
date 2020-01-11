#include "../../src/opengl/util.hpp"

using namespace apytuu_engine_opengl;

void render(){
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(){
	GLFWwindow* window = initGLFW(1000,500,"Test");
	glClearColor(0.4f, 0.0f, 0.4f, 0.0f);
	beginRenderLoop(window, render);
	glfwTerminate();
}
