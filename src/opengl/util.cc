#include "util.hpp"

using std::ifstream;
using std::ios_base;

char* apytuu_engine_opengl::readFile(const char* name){
	ifstream fin(name);
	if(fin){
		fin.seekg(0, ios_base::end);
		int s = fin.tellg();
		fin.seekg(0, ios_base::beg);
		char *buf = new char[s];
		fin.read(buf, s);
		fin.close();
		return buf;
	}
	else throw OpenGLException(name);
}

GLFWwindow* apytuu_engine_opengl::initGLFW(int w, int h, const char *title){
	//Initialise GLFW
	if(!glfwInit()){
		throw OpenGLException("glfwInit");
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	GLFWwindow* window = glfwCreateWindow(w, h, title, nullptr, nullptr);
	if(window == nullptr){
		throw OpenGLException("windowInit");
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		throw OpenGLException("glewInit");
	}

	return window;
}

void apytuu_engine_opengl::beginRenderLoop(GLFWwindow* window, void (*render)()){
	while (!glfwWindowShouldClose(window)){
		render();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

GLuint apytuu_engine_opengl::initProgram(const char *vsFileName, const char *fsFileName){
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	char *vss = readFile(vsFileName);
	glShaderSource(vs, 1, &vss, nullptr);
	delete[] vss;
	glCompileShader(vs);
	GLint success = 0;
	glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
	if(success == GL_FALSE){
		GLint s = 0;
		glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &s);
		char *msg = new char[s];
		glGetShaderInfoLog(vs, s, nullptr, msg);
		throw OpenGLException(msg);
	}

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	char *fss = readFile(fsFileName);
	glShaderSource(fs, 1, &fss, nullptr);
	delete[] fss;
	glCompileShader(fs);
	glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
	if(success == GL_FALSE){
		GLint s = 0;
		glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &s);
		char *msg = new char[s];
		glGetShaderInfoLog(fs, s, nullptr, msg);
		throw OpenGLException(msg);
	}

	GLuint prgm = glCreateProgram();
	glAttachShader(prgm, vs);
	glAttachShader(prgm, fs);
	glLinkProgram(prgm);
	glGetProgramiv(prgm, GL_LINK_STATUS, &success);
	if(success == GL_FALSE){
		throw OpenGLException("PRGM link fail");
	}

	glDetachShader(prgm, vs);
	glDetachShader(prgm, fs);
	glDeleteShader(vs);
	glDeleteShader(fs);

	return prgm;
}
