#include <iostream>
#include <random>
#include <chrono>
#include "../math/mat.hpp"

using namespace apytuu_engine_math;
using std::cerr;
using std::endl;
using std::default_random_engine;
using std::uniform_real_distribution;

int main(){
	default_random_engine eng(std::chrono::system_clock::now().time_since_epoch().count());
	uniform_real_distribution<double> dist(0,1);

	Vec<double,3> x;
	x.at(0) = dist(eng);
	x.at(1) = dist(eng);
	x.at(2) = dist(eng);

	Vec<double,3> y;
	y.at(0) = dist(eng);
	y.at(1) = dist(eng);
	y.at(2) = -(x.get(0)*y.get(0)+x.get(1)*y.get(1))/x.get(2);

	x.normalize();
	y.normalize();
	Vec<double,3> z = cross(x,y);
	cerr << x << endl << y << endl << z << endl;

	Mat<double, 3,3> m;
	for(int i=0;i<3;i++){
		m.at(0,i) = x.get(i);
		m.at(1,i) = y.get(i);
		m.at(2,i) = z.get(i);
	}

	cerr << m << endl;

	cerr << m * m.transposed() << endl;

	cerr << x*y << " " << x*z << " " << y*z << endl;
	cerr << (2 + (x.get(1)*y.get(2) - x.get(2)*y.get(1)) * (x.get(1)*y.get(2) - x.get(2)*y.get(1))
		- x.get(1)*x.get(1) - x.get(2)*x.get(2) - y.get(1)*y.get(1) -y.get(2)*y.get(2)) << endl;

	cerr << (x.get(0)*x.get(0) + x.get(1)*y.get(1)*(x.get(1)*y.get(1) - x.get(2)*y.get(2))
		- x.get(2)*y.get(2)*x.get(1)*y.get(1)+ x.get(0)*x.get(0)*y.get(1)*y.get(1) +
		2 * x.get(2)*x.get(2)*y.get(1)*y.get(1) + x.get(1)*x.get(1)*y.get(2)*y.get(2)) << endl;
}
