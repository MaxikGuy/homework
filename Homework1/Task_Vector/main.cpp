#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	TVector_3d a(1, 1, 0);
	TVector_3d b(0, 1, 0);
	TVector_3d c;

	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << endl;

	cout << a << endl;
	cout << b << endl;

	// poerator+
	c = a + b;
	cout << "poerator+: " << c << endl;

	// poerator-
	c = a - b;
	cout << "poerator-: " << c << endl;

	// poerator*
	cout << "poerator*: " << a*b << endl;

	// poerator+=
	c = a;
	c += b;
	cout << "poerator+=: " << c << endl;

	// poerator-=
	c = a;
	c -= b;
	cout << "poerator-=: " << c << endl;
	


	cout << "a.mod(): " << a.mod() << endl;
	cout << "a.cos_btwn(b): " << a.cos_btwn(b);


	return 0;
}