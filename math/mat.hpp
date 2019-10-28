#ifndef APYTUU_ENGINE_MATH_MAT
#define APYTUU_ENGINE_MATH_MAT
#include "ex.hpp"
/**
* Matrix class for matrix math
*/
namespace apytuu_engine_math{
	template<class T, int M, int N>
	class Mat{
	public:
		Mat(T v);
		T& at(int r, int c);
		bool validate(int r, int c);
	private:
		T buf[M*N];
		const int s = M*N;
	};

	template<class T, int M, int N>
	Mat<T,M,N>::Mat(T v){
		for(int i=0;i<s;i++){
			buf[i] = v;
		}
	}

	template<class T, int M, int N>
	T& Mat<T,M,N>::at(int r, int c){
		if(!validate(r,c)){
			MathException ex;
			throw ex;
		}
		return buf[r*N + c];
	}

	template<class T, int M, int N>
	bool Mat<T,M,N>::validate(int r, int c){
		return r >= 0 && r < M && c >= 0 && c < N;
	}

	typedef Mat<float,2,2> Mat2f;
}

#endif
