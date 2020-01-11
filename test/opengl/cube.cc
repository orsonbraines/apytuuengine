#include "../../src/opengl/program.hpp"
#include <iostream>

using namespace apytuu_engine_opengl;
using std::cerr;
using std::endl;

bool right_mouse_button_down = false;
double last_xpos = -1.0;
double last_ypos = -1.0;
CubeMesh mesh;
Mat<float,4,4> rmat;

void colourSetter(int i, void *b){
	float *f = (float*)b;
	if(i<6){
		f[0] = 0.75f;
		f[1] = 0;
		f[2] = 0;
	}
	else if(i<12){
		f[0] = 0;
		f[1] = 0;
		f[2] = 0.75f;
	}
	else if(i<18){
		f[0] = 0;
		f[1] = 0.75f;
		f[2] = 0;
	}
	else if(i<24){
		f[0] = 0.75f;
		f[1] = 0;
		f[2] = 0.75f;
	}
	else if(i<30){
		f[0] = 0.75;
		f[1] = 0.75f;
		f[2] = 0;
	}
	else{
		f[0] = 0.0f;
		f[1] = 0.75f;
		f[2] = 0.75f;
	}
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
	if(button == GLFW_MOUSE_BUTTON_LEFT){
		right_mouse_button_down = action == GLFW_PRESS;
		if(action == GLFW_RELEASE){
			last_xpos = -1;
			last_ypos = -1;
		}
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
	if(right_mouse_button_down){
		if(last_xpos > 0 && last_ypos > 0){
			float dx = xpos - last_xpos;
			float dy = ypos - last_ypos;
			cerr << "delta " << dx << ", " << dy << endl;
			yaw(rmat, dx/100.0f);
			mesh.matrix *= rmat;
			pitch(rmat, -dy/100.0f);
			mesh.matrix *= rmat;
		}
		last_xpos = xpos;
		last_ypos = ypos;
	}
}

int main(){
	try{
		GLFWwindow* window = initGLFW(500,500,"Cube");
		glfwSetCursorPosCallback(window, cursor_position_callback);
		glfwSetMouseButtonCallback(window, mouse_button_callback);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);

		Program program("cubevs.glsl", "cubefs.glsl");

		program.addAttribute("r", 3);
		program.addAttribute("vertexColour", 3);
		program.addMesh(&mesh);
		program.initBuf();
		mesh.writePositions();
		mesh.writeAttribute(1, colourSetter);
		program.writeBuf();

		Vec<float, 3> sv;
		sv.at(0) = 0.5f;
		sv.at(1) = 0.5f;
		sv.at(2) = -0.5f;
		scale(mesh.matrix, sv);

		while (!glfwWindowShouldClose(window)){
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			program.draw();
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		program.deleteProgram();
		glfwTerminate();
	}
	catch(OpenGLException ex){
		cerr << "ERROR: " << ex.msg << endl;
	}
}
