#ifndef APYTUU_ENGINE_MATH_MAT
#define APYTUU_ENGINE_MATH_MAT
#include "vec.hpp"

/**
* Matrix class for matrix math
*/
namespace apytuu_engine_math{
	template<class T, int M, int N>
	class Mat{
	public:
		Mat();
		Mat(T v);
		inline T& at(int r, int c);
		inline bool validate(int r, int c) const;
		template<int C> Mat<T,M,C> operator*(const Mat<T,N,C> &m) const;
		inline T* ptr(int r, int c);
		inline const T* constptr(int r, int c) const;
		static const int S = M*N;
	private:
		T buf[M*N];
	};

	template<class T, int M, int N>
	Mat<T,M,N>::Mat(){
		memset((void*)buf, 0, S*sizeof(T));
	}

	template<class T, int M, int N>
	Mat<T,M,N>::Mat(T v){
		for(int i=0;i<S;i++){
			buf[i] = v;
		}
	}

	template<class T, int M, int N>
	T* Mat<T,M,N>::ptr(int r, int c){
		return buf + r*N + c;
	}

	template<class T, int M, int N>
	const T* Mat<T,M,N>::constptr(int r, int c) const{
		return buf + r*N + c;
	}

	template<class T, int M, int N>
	T& Mat<T,M,N>::at(int r, int c){
		if(!validate(r,c)){
			MathException ex;
			throw ex;
		}
		return *ptr(r,c);
	}

	template<class T, int M, int N>
	bool Mat<T,M,N>::validate(int r, int c) const{
		return r >= 0 && r < M && c >= 0 && c < N;
	}

	template<class T, int M, int N>
	template<int C>
	Mat<T,M,C> Mat<T,M,N>::operator*(const Mat<T,N,C> &m) const{
		Mat<T,M,C> res;
		for(int r=0; r<M; r++){
			for(int c=0; c<C; c++){
				for(int i=0;i<N;i++){
					*res.ptr(r,c) += *constptr(r,i) * *m.constptr(i,c);
				}
			}
		}
		return res;
	}

	typedef Mat<float,2,2> Mat2f;
}

#endif
