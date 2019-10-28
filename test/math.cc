#include <iostream>
#include "../math/mat.hpp"

using namespace apytuu_engine_math;
using std::cerr;
using std::endl;

int main(){
	Mat2f mat(1);
	mat.at(0,1) = 2;
	mat.at(1,0) = 3;
	mat.at(1,1) = 4;

	for(int r=0;r<2;r++){
		for(int c=0;c<2;c++){
			cerr << mat.at(r,c) << " ";
		}
		cerr << endl;
	}
}
