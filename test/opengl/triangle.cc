#include "../../src/opengl/util.hpp"
#include <iostream>

using namespace apytuu_engine_opengl;
using std::cerr;
using std::endl;

GLuint prgm, vao, vbo;

void render(){
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(prgm);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}

int main(){
	try{
		GLFWwindow* window = initGLFW(1000,500,"Triangle");
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		//create and bind the vertex array object
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		prgm = initProgram("vs0.glsl", "fs0.glsl");

		const GLfloat triangle[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f,  0.0f,
			0.0f, 0.5f, 0.0f
		};

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);


		beginRenderLoop(window, render);
		glDeleteBuffers(1, &vbo);
		glDeleteVertexArrays(1, &vao);
		glDeleteProgram(prgm);
		glfwTerminate();
	}
	catch(OpenGLException ex){
		cerr << "ERROR: " << ex.msg << endl;
	}
}
