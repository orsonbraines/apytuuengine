#ifndef APYTUU_ENGINE_MATH_VEC
#define APYTUU_ENGINE_MATH_VEC
#include <cstring>
#include <iostream>
#include "ex.hpp"
namespace apytuu_engine_math{
	template<class T, int N>
	class Vec{
	public:
		Vec();
		inline bool validate(int i) const;
		inline T& at(int i);
		T operator*(const Vec<T,N> &v) const;
	private:
		T buf[N];
	};

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
	T Vec<T,N>::operator*(const Vec<T,N> &v) const{
		T res;
		if(N > 0){
			res = buf[0] * v.buf[0];
			for(int i=1; i<N; i++){
				std::cerr << "res: " << res << std::endl;
				res += buf[i] * v.buf[i];
			}
		}
		else{
			memset((void*)&res,0,sizeof(T));
		}
		return res;
	}
}
#endif
