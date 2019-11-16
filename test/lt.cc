#include <iostream>
#include "../math/mat.hpp"

using namespace apytuu_engine_math;
using std::cerr;
using std::endl;

int main(){
	Mat<int,2,2> m0;
	m0.at(0,0) = 1;	m0.at(0,1) = 2;
	m0.at(1,0) = 4;	m0.at(1,1) = 5;

	Mat<int,2,2> m1;
	m1.at(0,0) = 2;	m1.at(0,1) = 1;
	m1.at(1,0) = 4;	m1.at(1,1) = 5;

	cerr << (m0 < m1) << endl;
}
