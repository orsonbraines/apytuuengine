#ifndef APYTUU_ENGINE_MATH_MAT
#define APYTUU_ENGINE_MATH_MAT
#include "vec.hpp"
#include <algorithm>
using std::min;
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
		inline const T& get(int r, int c) const;
		inline bool validate(int r, int c) const;
		template<int A, int B> Mat<T,A,B> resized() const;
		template<int C> Mat<T,M,C> operator*(const Mat<T,N,C> &m) const;
		Vec<T,M> operator*(const Vec<T,N> &v) const;
		void operator*=(const Mat<T,N,N> &m);
		void operator*=(const T &a);
		bool operator<(const Mat<T,M,N> &m) const;
		bool operator==(const Mat<T,M,N> &m) const;
		bool operator!=(const Mat<T,M,N> &m) const;
		inline T* ptr(int r, int c);
		inline const T* constptr(int r, int c) const;
		Mat<T,N,M> transposed() const;
		static const int S = M*N;
		static const int NBYTES = S*sizeof(T);
	private:
		T buf[M*N];
	};

	template<class T, int M, int N>
	Mat<T,M,N>::Mat(){
		memset((void*)buf, 0, NBYTES);
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
	const T& Mat<T,M,N>::get(int r, int c) const{
		if(!validate(r,c)){
			MathException ex;
			throw ex;
		}
		return *constptr(r,c);
	}

	template<class T, int M, int N>
	bool Mat<T,M,N>::validate(int r, int c) const{
		return r >= 0 && r < M && c >= 0 && c < N;
	}

	template<class T, int M, int N>
	template<int A, int B>
	Mat<T,A,B> Mat<T,M,N>::resized() const{
		Mat<T,A,B> res;
		int nr = min(A,M);
		int nc = min(B,N);
		for(int r=0; r<nr; r++)
			for(int c=0; c<nc; c++)
				*res.ptr(r,c) = *constptr(r,c);
		return res;
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

	template<class T, int M, int N>
	Vec<T,M> Mat<T,M,N>::operator*(const Vec<T,N> &v) const{
		Vec<T,M> res;
		for(int r=0; r<M; r++){
			for(int c=0; c<N; c++){
				res.at(r) += v.get(c) * *constptr(r,c);
			}
		}
		return res;
	}

	template<class T, int M, int N>
	void Mat<T,M,N>::operator*=(const Mat<T,N,N> &m){
		Mat<T,M,N> tmp = *this * m;
		memcpy((void*)buf, (const void*)tmp.buf, NBYTES);
	}

	template<class T, int M, int N>
	void Mat<T,M,N>::operator*=(const T &a){
		for(int i=0; i<S; i++)
			buf[i] *= a;
	}

	template<class T, int M, int N>
	bool Mat<T,M,N>::operator<(const Mat<T,M,N> &m) const{
		return memcmp((const void*)buf, (const void*)m.buf, NBYTES) < 0;
	}

	template<class T, int M, int N>
	bool Mat<T,M,N>::operator==(const Mat<T,M,N> &m) const{
		return memcmp((const void*)buf, (const void*)m.buf, NBYTES) == 0;
	}

	template<class T, int M, int N>
	bool Mat<T,M,N>::operator!=(const Mat<T,M,N> &m) const{
		return memcmp((const void*)buf, (const void*)m.buf, NBYTES) != 0;
	}

	template<class T, int M, int N>
	Mat<T,N,M> Mat<T,M,N>::transposed() const{
		Mat<T,N,M> res;
		for(int r=0; r<M; r++){
			for(int c=0; c<N; c++){
				*res.ptr(c,r) = *constptr(r,c);
			}
		}
		return res;
	}

	template<class T, int M, int N>
	Mat<T,M,N> operator*(const T &a, const Mat<T,M,N> &m){
		Mat<T,M,N> r = m;
		r *= a;
		return r;
	}

	template<class T, int M, int N>
	ostream& operator<<(ostream &o, const Mat<T,M,N> &m){
		for(int r=0; r<M; r++){
			for(int c=0; c<N; c++){
				o << m.get(r,c) << " ";
			}
			o << endl;
		}
		return o;
	}

	typedef Mat<float,2,2> Mat2f;
}

#endif
