#ifndef APYTUU_ENGINE_OPENGL_PROGRAM
#define APYTUU_ENGINE_OPENGL_PROGRAM
#include "mesh.hpp"
#include <list>
#include <utility>
#include <cstdlib>

using std::list;
using std::pair;

namespace apytuu_engine_opengl{

	class Program{
	public:
		Program(const char *vsFileName, const char *fsFileName);
		void addAttribute(const string &name, GLint size);
		void addMesh(Mesh *mesh);
		void initBuf();
		void writeBuf();
		void draw();
		void deleteProgram();
	private:
		VertexAttributes attributes;
		GLuint vao, vbo, program, matLoc;
		list<pair<Mesh*,int>> meshes;
		void* buf;
		int n;
	};
}
#endif
