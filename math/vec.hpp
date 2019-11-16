#ifndef APYTUU_ENGINE_MATH_VEC
#define APYTUU_ENGINE_MATH_VEC
#include <cstring>
#include <cmath>
#include <iostream>
#include "ex.hpp"
using std::ostream;
using std::endl;
namespace apytuu_engine_math{
	template<class T, int N>
	class Vec{
	public:
		Vec();
		inline bool validate(int i) const;
		inline T& at(int i);
		inline const T& get(int i) const;
		inline T norm2() const;
		inline T norm() const;
		void normalize();
		Vec<T,N> normalized() const;
		void operator*=(T a);
		void operator/=(T a);
		inline Vec<T,N> operator-() const;
		T operator*(const Vec<T,N> &v) const;
		inline bool operator<(const Vec<T,N> &v) const;
		inline bool operator==(const Vec<T,N> &v) const;
		inline bool operator!=(const Vec<T,N> &v) const;
		static const int NBYTES = N * sizeof(T);
	private:
		T buf[N];
	};

	template<class T, int N>
	Vec<T,N> operator*(T a, const Vec<T,N> &v){
		Vec<T,N> res = v;
		res *= a;
		return res;
	}

	template<class T, int N>
	Vec<T,N> operator/(const Vec<T,N> &v, T a){
		Vec<T,N> res = v;
		res /= a;
		return res;
	}

	template<class T, int N>
	ostream& operator<<(ostream &o, const Vec<T,N> &v){
		for(int i=0; i<N; i++){
			o << v.get(i) << " ";
		}
		o << endl;
		return o;
	}

	template<class T, int N>
	Vec<T,N>::Vec(){
		memset((void*)buf,0,N*sizeof(T));
	}

	template<class T, int N>
	bool Vec<T,N>::validate(int i) const{
		return i >= 0 && i <= N;
	}

	template<class T, int N>
	T& Vec<T,N>::at(int i){
		if(!validate(i)){
			MathException ex;
			throw ex;
		}
		return buf[i];
	}

	template<class T, int N>
	const T& Vec<T,N>::get(int i) const{
		if(!validate(i)){
			MathException ex;
			throw ex;
		}
		return buf[i];
	}

	template<class T, int N>
	T Vec<T,N>::norm2() const {
		return *this * *this;
	}

	template<class T, int N>
	T Vec<T,N>::norm() const{
		return sqrt(norm2());
	}

	template<class T, int N>
	void Vec<T,N>::normalize(){
		*this /= norm();
	}

	template<class T, int N>
	Vec<T,N> Vec<T,N>::normalized() const{
		return *this / norm();
	}

	template<class T, int N>
	void Vec<T,N>::operator*=(T a){
		for(int i=0; i<N; i++) buf[i] *= a;
	}

	template<class T, int N>
	void Vec<T,N>::operator/=(T a){
		for(int i=0; i<N; i++) buf[i] /= a;
	}

	template<class T, int N>
	Vec<T,N> Vec<T,N>::operator-() const {return -1 * *this;}

	template<class T, int N>
	T Vec<T,N>::operator*(const Vec<T,N> &v) const{
		T res;
		if(N > 0){
			res = buf[0] * v.buf[0];
			for(int i=1; i<N; i++){
				res += buf[i] * v.buf[i];
			}
		}
		else{
			memset((void*)&res,0,sizeof(T));
		}
		return res;
	}

	template<class T, int N>
	bool Vec<T,N>::operator<(const Vec<T,N> &v) const{
		return memcmp((const void*)buf, (const void*)v.buf, NBYTES) < 0;
	}

	template<class T, int N>
	bool Vec<T,N>::operator==(const Vec<T,N> &v) const{
		return memcmp((const void*)buf, (const void*)v.buf, NBYTES) == 0;
	}

	template<class T, int N>
	bool Vec<T,N>::operator!=(const Vec<T,N> &v) const{
		return memcmp((const void*)buf, (const void*)v.buf, NBYTES) != 0;
	}

	template<class T>
	Vec<double,3> cross(const Vec<T,3> &v0, const Vec<T,3> &v1){
		Vec<T,3> res;
		res.at(0) = v0.get(1) * v1.get(2) - v0.get(2) * v1.get(1);
		res.at(1) = v0.get(2) * v1.get(0) - v0.get(0) * v1.get(2);
		res.at(2) = v0.get(0) * v1.get(1) - v0.get(1) * v1.get(0);
		return res;
	}
}
#endif
