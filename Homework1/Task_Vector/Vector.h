#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class TVector_3d {
private:
	float x;
	float y;
	float z;

public:
	TVector_3d(const float _x = 0, const float _y = 0, const float _z = 0);
	TVector_3d(const TVector_3d& vect);

	friend istream& operator>>(istream& in, TVector_3d& vect);
	friend ostream& operator<<(ostream& out, const TVector_3d& vect);

	float GetX() const { return x; }
	float GetY() const { return y; }
	float GetZ() const { return z; }

	const TVector_3d& operator=(const TVector_3d& vect);

	TVector_3d operator+(const TVector_3d& vect);
	TVector_3d operator-(const TVector_3d& vect);
	float operator*(const TVector_3d& vect);

	TVector_3d& operator+=(const TVector_3d& vect);
	TVector_3d& operator-=(const TVector_3d& vect);

	bool operator==(const TVector_3d& vect) const;
	bool operator!=(const TVector_3d& vect) const;

	float mod();
	float cos_btwn(TVector_3d& vect);
};

#endif // !VECTOR_H
