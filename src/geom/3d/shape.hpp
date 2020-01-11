#ifndef APYTUU_ENGINE_GEOM_3D_SHAPE
#define APYTUU_ENGINE_GEOM_3D_SHAPE
#include "../../math/vec.hpp"
#include "../ex.hpp"
using namespace apytuu_engine_math;
namespace apytuu_engine_geom_3d{
	template<class T>
	class Shape3{
	public:
		virtual ~Shape3();
		virtual bool in(const Vec<T,3> &p) const = 0;
	protected:
		Shape3();
	};

	template<class T>
	class Line3 : public Shape3<T>{
	private:
		Vec<T,3> p0, p1;
	};

	template<class T>
	class Box3 : public Shape3<T>{
	public:
		Box3();
		Box3(const Vec<T,3> &r, const Vec<T,3> &a);
		const Vec<T,3>& getPos();
		const Vec<T,3>& getX();
		const Vec<T,3>& getY();
		const Vec<T,3>& getZ();
		void setPos(const Vec<T,3> &r);
		void setAxes(const Vec<T,3> &a);
		virtual bool in(const Vec<T,3> &p) const;
	private:
		Vec<T,3> r,x,y,z;
	};

	template<class T>
	class Cube3 : public Shape3<T>{
	public:
		Cube3();
		Cube3(const Vec<T,3> &r, T s);
		const Vec<T,3>& getPos();
		const Vec<T,3>& getX();
		const Vec<T,3>& getY();
		const Vec<T,3>& getZ();
		T getSize();
		void setSize(T s);
		virtual bool in(const Vec<T,3> &p) const;
	private:
		T s;
		Box3<T> box;
	};

	template<class T>
	class Ellipsoid3 : public Shape3<T>{
	private:
		Vec<T,3> c,x,y,z;
	};

	template<class T>
	class Sphere3 : public Shape3<T>{
	private:
		Vec<T,3> c;
		T r;
		Ellipsoid3<T> ellipsoid;
	};
}
#endif
