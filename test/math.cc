#include <iostream>
#include "../math/mat.hpp"

using namespace apytuu_engine_math;
using std::cerr;
using std::endl;

int main(){
	Mat<int,2,3> m0;
	Mat<int,3,4> m1;
	m0.at(0,0) = 1;	m0.at(0,1) = 2;	m0.at(0,2) = 3;
	m0.at(1,0) = 4;	m0.at(1,1) = 5;	m0.at(1,2) = 6;

	m1.at(0,0) = 10; m1.at(0,1) = 20; m1.at(0,2) = 30; m1.at(0,3) = 40;
	m1.at(1,0) = 50; m1.at(1,1) = 60; m1.at(1,2) = 70; m1.at(1,3) = 80;
	m1.at(2,0) = 90; m1.at(2,1) = 100; m1.at(2,2) = 110; m1.at(2,3) = 120;

	Mat<int,2,4> mat = m0 * m1;

	for(int r=0;r<2;r++){
		for(int c=0;c<4;c++){
			cerr << mat.at(r,c) << " ";
		}
		cerr << endl;
	}

	Vec<int,3> v0,v1;
	v0.at(0) = 1; v0.at(1) = 2; v0.at(2) = 3;
	v1.at(0) = 4; v1.at(1) = 5; v1.at(2) = 6;

	cerr << (v0*v1) << endl;
}
