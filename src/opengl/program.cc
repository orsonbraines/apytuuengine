#include "program.hpp"

namespace apytuu_engine_opengl{
	Program::Program(const char *vsFileName, const char *fsFileName) :
	program(initProgram(vsFileName, fsFileName)), n(0), buf(nullptr){
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		matLoc = glGetUniformLocation(program, "mat");
	}

	void Program::addAttribute(const string &name, GLint size){
		attributes.addAttribute(name, size);
	}

	void Program::addMesh(Mesh *mesh){
		meshes.push_back(pair<Mesh*,int>(mesh,n*attributes.stride));
		mesh->setAttributes(&attributes);
		n += mesh->numVertices();
	}

	void Program::initBuf(){
		buf = malloc(n*attributes.stride);
		for(auto &p : meshes){
			p.first->setBuf(buf + p.second);
		}
	}

	void Program::writeBuf(){
		cerr << "writing buf: ";
		float* fbuf = (float*) buf;
		for(int i=0;i<n*attributes.stride/sizeof(float);++i){
			cerr << fbuf[i] << " ";
		}
		cerr << endl;
		glBindVertexArray(vao);
		for(int i=0; i<attributes.attributes.size(); i++) glEnableVertexAttribArray(i);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, n*attributes.stride, buf, GL_STATIC_DRAW);
		free(buf);
		buf = nullptr;
		for(auto &p : meshes){
			p.first->setBuf(nullptr);
		}
	}

	void Program::draw(){
		glUseProgram(program);
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		for(int i=0; i<attributes.attributes.size(); i++)
			glVertexAttribPointer(i, attributes.attributes[i].size, GL_FLOAT, GL_FALSE, attributes.stride, (void*)attributes.attributes[i].offset);
		for(auto &p : meshes){
			glUniformMatrix4fv(matLoc, 1, GL_TRUE, p.first->matrix.getBuf());
			p.first->draw(p.second);
		}
	}

	void Program::deleteProgram(){
		glDeleteBuffers(1, &vbo);
		glDeleteVertexArrays(1, &vao);
		glDeleteProgram(program);
	}
}
