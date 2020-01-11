#ifndef APYTUU_ENGINE_MATH_UTIL
#define APYTUU_ENGINE_MATH_UTIL
#include "mat.hpp"
namespace apytuu_engine_math{
	template<class T, int N>
	void identity(Mat<T,N,N> &mat){
		for(int r = 0; r < N; r++){
			for(int c = 0; c < N; c++){
				mat.at(r,c) = (r == c ? 1 : 0);
			}
		}
	}

	template<class T>
	void translation(Mat<T,4,4> &mat, const Vec<T,3> &v){
		for(int r = 0; r < 4; r++){
			for(int c = 0; c < 4; c++){
				if(c == 3 && r < 3) mat.at(r,c) = v.get(r);
				else mat.at(r,c) = (r == c ? 1 : 0);
			}
		}
	}

	template<class T>
	void scale(Mat<T,4,4> &mat, const Vec<T,3> &v){
		for(int r = 0; r < 4; r++){
			for(int c = 0; c < 4; c++){
				if(c == r){
					mat.at(r,c) = (r == 3 ? 1 : v.get(r));
				}
				else mat.at(r,c) = 0;
			}
		}
	}

	template<class T>
	void roll(Mat<T,4,4> &mat, T t){
		mat.at(0,0) = cos(t);	mat.at(0,1) = sin(t);	mat.at(0,2) = 0;	mat.at(0,3) = 0;
		mat.at(1,0) = -sin(t);	mat.at(1,1) = cos(t);	mat.at(1,2) = 0;	mat.at(1,3) = 0;
		mat.at(2,0) = 0;		mat.at(2,1) = 0;		mat.at(2,2) = 1;	mat.at(2,3) = 0;
		mat.at(3,0) = 0;		mat.at(3,1) = 0;		mat.at(3,2) = 0;	mat.at(3,3) = 1;
	}

	template<class T>
	void pitch(Mat<T,4,4> &mat, T t){
		mat.at(0,0) = 1;	mat.at(0,1) = 0;		mat.at(0,2) = 0;		mat.at(0,3) = 0;
		mat.at(1,0) = 0;	mat.at(1,1) = cos(t);	mat.at(1,2) = sin(t);	mat.at(1,3) = 0;
		mat.at(2,0) = 0;	mat.at(2,1) = -sin(t);	mat.at(2,2) = cos(t);	mat.at(2,3) = 0;
		mat.at(3,0) = 0;	mat.at(3,1) = 0;		mat.at(3,2) = 0;		mat.at(3,3) = 1;
	}

	template<class T>
	void yaw(Mat<T,4,4> &mat, T t){
		mat.at(0,0) = cos(t);	mat.at(0,1) = 0;	mat.at(0,2) = -sin(t);	mat.at(0,3) = 0;
		mat.at(1,0) = 0;		mat.at(1,1) = 1;	mat.at(1,2) = 0;		mat.at(1,3) = 0;
		mat.at(2,0) = sin(t);	mat.at(2,1) = 0;	mat.at(2,2) = cos(t);	mat.at(2,3) = 0;
		mat.at(3,0) = 0;		mat.at(3,1) = 0;	mat.at(3,2) = 0;		mat.at(3,3) = 1;
	}

	// v' = v proj a + cos(t) * v perp d + sin(t) * d cross v
	template<class T>
	void rotation(Mat<T,4,4> &mat, Vec<T,3> a, T t){
		a.normalize();

		const T a0 = a.get(0);
		const T a02 = a0 * a0;
		const T a1 = a.get(1);
		const T a12 = a1 * a1;
		const T a2 = a.get(2);
		const T a22 = a2 * a2;
		const T st = sin(t);
		const T ct = cos(t);

		mat.at(0,0) = a02 + (a12+a22)*ct;
		mat.at(0,1) = a0*a1*(1-ct) - a2*st;
		mat.at(0,2) = a0*a2*(1-ct) + a1*st;
		mat.at(0,3) = 0;

		mat.at(1,0) = a1*a0*(1-ct) + a2*st;
		mat.at(1,1) = a12 + (a02+a22)*ct;
		mat.at(1,2) = a1*a2*(1-ct) - a0*st;
		mat.at(1,3) = 0;

		mat.at(2,0) = a2*a0*(1-ct) - a1*st;
		mat.at(2,1) = a2*a1*(1-ct) + a0*st;
		mat.at(2,2) = a22 + (a02+a12)*ct;
		mat.at(2,3) = 0;

		mat.at(3,0) = 0;
		mat.at(3,1) = 0;
		mat.at(3,2) = 0;
		mat.at(3,3) = 1;
	}

	template<class T>
	void ortho(Mat<T,4,4> &mat, T l, T r, T d, T u, T b, T f){
		mat.at(0,0) = 2/(r-l);	mat.at(0,1) = 0;		mat.at(0,2) = 0;		mat.at(0,3) = -1 - (2*l)/(r-l);
		mat.at(1,0) = 0;		mat.at(1,1) = 2/(u-d);	mat.at(1,2) = 0;		mat.at(1,3) = -1 - (2*d)/(u-d);
		mat.at(2,0) = 0;		mat.at(2,1) = 0;		mat.at(2,2) = 2/(f-b);	mat.at(2,3) = -1 - (2*b)/(f-b);
		mat.at(3,0) = 0;		mat.at(3,1) = 0;		mat.at(3,2) = 0;		mat.at(3,3) = 1;
	}
}
#endif
