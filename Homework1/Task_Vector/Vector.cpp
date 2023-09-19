#include <iostream>
#include <cmath>
#include "Vector.h"

using namespace std;

TVector_3d::TVector_3d(const float _x, const float _y, const float _z) {
	x = _x;
	y = _y;
	z = _z;
}
TVector_3d::TVector_3d(const TVector_3d& vect) {
	x = vect.x;
	y = vect.y;
	z = vect.z;
}

const TVector_3d& TVector_3d::operator=(const TVector_3d& vect) {
	x = vect.x;
	y = vect.y;
	z = vect.z;
	return (*this);
}

TVector_3d TVector_3d::operator+(const TVector_3d& vect) {
	TVector_3d tmp(x + vect.x, y + vect.y, z + vect.z);
	return tmp;
}
TVector_3d TVector_3d::operator-(const TVector_3d& vect) {
	TVector_3d tmp(x - vect.x, y - vect.y, z - vect.z);
	return tmp;
}
float TVector_3d::operator*(const TVector_3d& vect) {
	return x * vect.x + y * vect.y + z * vect.z;
}

TVector_3d& TVector_3d::operator+=(const TVector_3d& vect) {
	x += vect.x;
	y += vect.y;
	z += vect.z;
	return (*this);
}
TVector_3d& TVector_3d::operator-=(const TVector_3d& vect) {
	x -= vect.x;
	y -= vect.y;
	z -= vect.z;
	return (*this);
}

bool TVector_3d::operator==(const TVector_3d& vect) const {
	if (x == vect.x && y == vect.y && z == vect.z)
		return true;
	return false;
}
bool TVector_3d::operator!=(const TVector_3d& vect) const {
	return !((*this) == vect);
}

float TVector_3d::mod() {
	float ans = sqrt(x * x + y * y + z * z);
	return ans;
}
float TVector_3d::cos_btwn(TVector_3d& vect) {
	return (*this) * vect / (mod() * vect.mod());
}