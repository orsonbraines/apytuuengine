#include <iostream>
#include "../src/math/util.hpp"

using namespace apytuu_engine_math;
using std::cerr;
using std::endl;

int main(){
	Mat<float,4,4> tr;
	Vec<float,3> v3;
	v3.at(0) = 1;
	v3.at(1) = 2;
	v3.at(2) = 3;
	translation(tr, v3);

	Vec<float,4> v4;
	v4.at(0) = 10;
	v4.at(1) = 10;
	v4.at(2) = 10;
	v4.at(3) = 1;
	cerr << tr << endl;
	cerr << (tr * v4) << endl;

	scale(tr,v3);
	cerr << tr << endl;
	cerr << (tr * v4) << endl;

	v3.at(0) = 1;
	v3.at(1) = 1;
	v3.at(2) = 0;

	v4.at(0) = 1;
	v4.at(1) = 0;
	v4.at(2) = 0;
	v4.at(3) = 1;

	rotation(tr, v3, 3.1415926f);
	cerr << tr << endl;
	cerr << (tr*v4) << endl;


	v4.at(0) = 1.1f;
	v4.at(1) = 17.5f;
	v4.at(2) = -1.99f;
	v4.at(3) = 1;
	ortho(tr, 1.0f,2.0f,10.0f,20.0f,-2.0f,-1.0f);
	cerr << tr << endl;
	cerr << (tr*v4) << endl;
}
