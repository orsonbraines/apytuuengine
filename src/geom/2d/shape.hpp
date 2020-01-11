#ifndef APYTUU_ENGINE_GEOM_2D_SHAPE
#define APYTUU_ENGINE_GEOM_2D_SHAPE
#include "../../vec.hpp"
#include "../ex.hpp"
using namespace ayptuu_engine_math;
namespace apytuu_engine_geom_2d{
	template<class T>
	class Shape2{
		virtual ~Shape2();
		bool in(const Vec<T,2> &p) const;
	};

	template<class T>
	class Line2 : public Shape2{
	private:
		Vec<T,2> p0, p1;
	};

	template<class T>
	class Rect2 : public Shape2{
	private:
		Vec<T,2> bl, tr;
	};

	template<class T>
	class Square2 : public Shape2{
	private:
		Vec<T,2> bl,
		T r;
		Rect2 rect;
	};

	template<class T>
	class Ellipse2 : public Shape2{
		Vec<T,2> c;
		Vec<T,2> r;
	};

	template<class T>
	class Circle2 : public Shape2{
		Vec<T,2> c;
		T r;
		Ellipse2 ellipse;
	};
}
#endif
