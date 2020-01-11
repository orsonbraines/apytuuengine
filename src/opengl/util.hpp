#ifndef APYTUU_ENGINE_OPENGL_UTIL
#define APYTUU_ENGINE_OPENGL_UTIL
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "ex.hpp"
namespace apytuu_engine_opengl{
	char* readFile(const char* name);
	GLFWwindow* initGLFW(int w, int h, const char *title);
	void beginRenderLoop(GLFWwindow* window, void (*render)());
	GLuint initProgram(const char *vss, const char *fss);
}
#endif
