#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	Vector<int> a(3);
	Vector<int> b(3);
	//Vector<int> c;
	//Vector<int> d(3);

	try {
		cout << "a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;
		cout << "a = " << a << endl;
		cout << "b = " << b << "\n" << endl;

		cout << "operator+: " << a + b << endl;
		cout << "operator-: " << a - b << endl;
		cout << "operator*: " << a * b << endl;
		cout << "operator==: " << (a == b) << endl;
		cout << "operator!=: " << (a != b) << endl;
		cout << "a.mod(): " << a.mod() << endl;
	}
	catch (const string& exp) {
		cout << exp << endl;
	}


	return 0;
}