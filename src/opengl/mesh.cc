#include "mesh.hpp"
namespace apytuu_engine_opengl{
	VertexAttribute::VertexAttribute(const string &name, GLint size, GLuint offset) :
	name(name), size(size), offset(offset){}

	VertexAttributes::VertexAttributes() : attributes(), stride(0) {}

	void VertexAttributes::addAttribute(const string &name, GLint size){
		attributes.push_back(VertexAttribute(name, size, stride));
		stride += size * sizeof(float);
	}

	Mesh::Mesh(int n) : n(n), buf(nullptr), attributes(nullptr) {}

	int Mesh::numVertices() {return n;}

	void Mesh::setBuf(void *buf){this->buf = buf;}
	void Mesh::setAttributes(VertexAttributes *attributes) {this->attributes = attributes;}
	int Mesh::getOffset(int attributeIdx, int vertexIdx) {
		return attributes->stride * vertexIdx + attributes->attributes[attributeIdx].offset;
	}

	void Mesh::writeAttribute(int idx, void(*f)(int, void*)){
		if(attributes == nullptr || buf == nullptr) throw OpenGLException("Mesh without buf or attributes");
		for(int i=0; i<n; i++) f(i, buf + getOffset(idx, i));
	}

	CubeMesh::CubeMesh() : Mesh(36) {}

	void CubeMesh::writePositions() {
		float *v[36];
		for(int i=0;i<n;i++) v[i] = (float*)(buf + getOffset(0,i));
		//1st triangle
		v[0][0] = -1.0f;	v[0][1] = 1.0f;		v[0][2] = 1.0f;
		v[1][0] = -1.0f;	v[1][1] = -1.0f;	v[1][2] = 1.0f;
		v[2][0] = 1.0f;		v[2][1] = -1.0f;	v[2][2] = 1.0f;

		v[3][0] = -1.0f;	v[3][1] = 1.0f;		v[3][2] = 1.0f;
		v[4][0] = 1.0f;		v[4][1] = -1.0f;	v[4][2] = 1.0f;
		v[5][0] = 1.0f;		v[5][1] = 1.0f;		v[5][2] = 1.0f;

		v[6][0] = 1.0f;		v[6][1] = 1.0f;			v[6][2] = 1.0f;
		v[7][0] = 1.0f;		v[7][1] = -1.0f;		v[7][2] = 1.0f;
		v[8][0] = 1.0f;		v[8][1] = -1.0f;		v[8][2] = -1.0f;

		v[9][0] = 1.0f;			v[9][1] = 1.0f;		v[9][2] = 1.0f;
		v[10][0] = 1.0f;		v[10][1] = -1.0f;	v[10][2] = -1.0f;
		v[11][0] = 1.0f;		v[11][1] = 1.0f;	v[11][2] = -1.0f;

		v[12][0] = 1.0f;		v[12][1] = 1.0f;	v[12][2] = -1.0f;
		v[13][0] = 1.0f;		v[13][1] = -1.0f;	v[13][2] = -1.0f;
		v[14][0] = -1.0f;		v[14][1] = -1.0f;	v[14][2] = -1.0f;

		v[15][0] = 1.0f;		v[15][1] = 1.0f;	v[15][2] = -1.0f;
		v[16][0] = -1.0f;		v[16][1] = -1.0f;	v[16][2] = -1.0f;
		v[17][0] = -1.0f;		v[17][1] = 1.0f;	v[17][2] = -1.0f;

		v[18][0] = -1.0f;		v[18][1] = 1.0f;	v[18][2] = -1.0f;
		v[19][0] = -1.0f;		v[19][1] = -1.0f;	v[19][2] = -1.0f;
		v[20][0] = -1.0f;		v[20][1] = -1.0f;	v[20][2] = 1.0f;

		v[21][0] = -1.0f;		v[21][1] = 1.0f;	v[21][2] = -1.0f;
		v[22][0] = -1.0f;		v[22][1] = -1.0f;	v[22][2] = 1.0f;
		v[23][0] = -1.0f;		v[23][1] = 1.0f;	v[23][2] = 1.0f;

		v[18][0] = -1.0f;		v[18][1] = 1.0f;	v[18][2] = -1.0f;
		v[19][0] = -1.0f;		v[19][1] = -1.0f;	v[19][2] = -1.0f;
		v[20][0] = -1.0f;		v[20][1] = -1.0f;	v[20][2] = 1.0f;

		v[21][0] = -1.0f;		v[21][1] = 1.0f;	v[21][2] = -1.0f;
		v[22][0] = -1.0f;		v[22][1] = -1.0f;	v[22][2] = 1.0f;
		v[23][0] = -1.0f;		v[23][1] = 1.0f;	v[23][2] = 1.0f;

		v[24][0] = -1.0f;		v[24][1] = 1.0f;	v[24][2] = -1.0f;
		v[25][0] = -1.0f;		v[25][1] = 1.0f;	v[25][2] = 1.0f;
		v[26][0] = 1.0f;		v[26][1] = 1.0f;	v[26][2] = 1.0f;

		v[27][0] = -1.0f;		v[27][1] = 1.0f;	v[27][2] = -1.0f;
		v[28][0] = 1.0f;		v[28][1] = 1.0f;	v[28][2] = 1.0f;
		v[29][0] = 1.0f;		v[29][1] = 1.0f;	v[29][2] = -1.0f;

		v[30][0] = 1.0f;		v[30][1] = -1.0f;	v[30][2] = -1.0f;
		v[31][0] = 1.0f;		v[31][1] = -1.0f;	v[31][2] = 1.0f;
		v[32][0] = -1.0f;		v[32][1] = -1.0f;	v[32][2] = 1.0f;

		v[33][0] = 1.0f;		v[33][1] = -1.0f;	v[33][2] = -1.0f;
		v[34][0] = -1.0f;		v[34][1] = -1.0f;	v[34][2] = 1.0f;
		v[35][0] = -1.0f;		v[35][1] = -1.0f;	v[35][2] = -1.0f;
	}

	void CubeMesh::draw(int offset){
		glDrawArrays(GL_TRIANGLES, offset, n);
	}
}
