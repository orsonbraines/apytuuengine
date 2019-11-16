#include <iostream>
#include "../math/mat.hpp"

using namespace apytuu_engine_math;
using std::cerr;
using std::endl;

int main(){
	Mat<int,2,3> m0;
	m0.at(0,0) = 1;	m0.at(0,1) = 2;	m0.at(0,2) = 3;
	m0.at(1,0) = 4;	m0.at(1,1) = 5;	m0.at(1,2) = 6;

	Vec<int,3> v0;
	v0.at(0) = 1;	v0.at(1) = 2;	v0.at(2) = 3;

	cerr << (m0 * v0) << endl;

	m0 *= 2;
	cerr << m0 << endl << (3*m0) << endl;
}
