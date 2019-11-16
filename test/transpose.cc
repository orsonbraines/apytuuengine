#include <iostream>
#include "../math/mat.hpp"

using namespace apytuu_engine_math;
using std::cerr;
using std::endl;

int main(){
	Mat<int,2,3> m0;
	m0.at(0,0) = 1;	m0.at(0,1) = 2;	m0.at(0,2) = 3;
	m0.at(1,0) = 4;	m0.at(1,1) = 5;	m0.at(1,2) = 6;

	Mat<int,3,2> mt = m0.transposed();
	cerr << mt << endl;
}
