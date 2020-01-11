#include "../math/vec.hpp"
using namespace apytuu_engine_math;
int main(){
	Vec<int,3> v0,v1;
	v0.at(0) = 1;
	v0.at(1) = 2;
	v0.at(2) = 3;
	v1.at(0) = 3;
	v1.at(1) = 2;
	v1.at(2) = 1;

	std::cout << (v0*v1) << std::endl;
}
