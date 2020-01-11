#ifndef APYTUU_ENGINE_GEOM_3D_SHAPE_IMPL
#define APYTUU_ENGINE_GEOM_3D_SHAPE_IMPL
#include "shape.hpp"

namespace apytuu_engine_geom_3d{
	template<class T>
	Box3<T>::Box3() : r(), x(), y(), z() {}

	template<class T>
	Box3<T>::Box3(const Vec<T,3> &r, const Vec<T,3> &a) : r(r){
		setAxes(a);
	}

	template<class T> const Vec<T,3>& Box3<T>::getPos() {return r;}
	template<class T> const Vec<T,3>& Box3<T>::getX() {return x;}
	template<class T> const Vec<T,3>& Box3<T>::getY() {return y;}
	template<class T> const Vec<T,3>& Box3<T>::getZ() {return z;}

	template<class T> void Box3<T>::setPos(const Vec<T,3> &r) {this->r = r;}

	template<class T>
	void Box3<T>::setAxes(const Vec<T,3> &a){
		x.at(0) = a.get(0);
		x.at(1) = 0;
		x.at(2) = 0;

		y.at(0) = 0;
		y.at(1) = a.get(1);
		y.at(2) = 0;

		z.at(0) = 0;
		z.at(1) = 0;
		z.at(2) = a.get(2);
	}

	template<class T>
	bool Box3<T>::in(const Vec<T,3> &p) const{
		Vec<T,3> d = p-r;
		return d*x >= 0 && d*x <= d.norm2() && d*y >= 0 && d*y <= d.norm2() && d*z >= 0 && d*z <= d.norm2();
	}

	template<class T>
	Cube3<T>::Cube3() : box(), s() {}

	template<class T>
	Cube3<T>::Cube3(const Vec<T,3> &r, T s) : s(s){
		box.setPos(r);
		setSize(s);
	}

	template<class T> const Vec<T,3>& Cube3<T>::getPos() {return box.getPos();}
	template<class T> const Vec<T,3>& Cube3<T>::getX() {return box.getX();}
	template<class T> const Vec<T,3>& Cube3<T>::getY() {return box.getY();}
	template<class T> const Vec<T,3>& Cube3<T>::getZ() {return box.getZ();}
	template<class T> T Cube3<T>::getSize() {return s;}

	template<class T> void Cube3<T>::setSize(T s){
		this->s = s;
		Vec<T,3> a;
		a.at(0) = s;
		a.at(1) = s;
		a.at(2) = s;
		box.setAxes(a);
	}

	template<class T>
	bool Cube3<T>::in(const Vec<T,3> &p) const{
		return box.in(p);
	}
}

#endif
