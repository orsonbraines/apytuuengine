#ifndef APYTUU_ENGINE_OPENGL_MESH
#define APYTUU_ENGINE_OPENGL_MESH
#include "../math/util.hpp"
#include "util.hpp"
#include <string>
#include <vector>
#include <iostream>

using std::cerr;
using std::endl;
using std::string;
using std::vector;
using apytuu_engine_math::Mat;
using apytuu_engine_math::Vec;

namespace apytuu_engine_opengl{
	class VertexAttribute{
	public:
		VertexAttribute(const string &name, GLint size, GLuint offset);
		GLint size;
		GLuint offset;
		string name;
	};

	class VertexAttributes{
	public:
		VertexAttributes();
		void addAttribute(const string &name, GLint size);
		vector<VertexAttribute> attributes;
		GLuint stride;
	};

	class Mesh{
	public:
		int numVertices();
		void setBuf(void *buf);
		void setAttributes(VertexAttributes *attributes);
		int getOffset(int attributeIdx, int vertexIdx);
		virtual void draw(int offset) = 0;
		virtual void writePositions() = 0;
		virtual void writeAttribute(int idx, void(*f)(int, void*));
		Mat<float,4,4> matrix;
	protected:
		Mesh(int n);
		int n;
		void *buf;
		VertexAttributes *attributes;
	};

	class CubeMesh : public Mesh{
	public:
		CubeMesh();
		virtual void draw(int offset);
		virtual void writePositions();
	};
}
#endif
