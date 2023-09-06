#include <iostream>
#include <stdlib.h>
#include "functions.h"

using namespace std;

float GetRandomNumber(int min, int max) {
	int num = min + rand() % (max - min + 1);

	return (float)num;
}

TArr::TArr(int min, int max) {
	cout << "¬ведите четное кол-во элементов массива: ";
	do {
		cin >> count;
	} while (count <= 0 || count % 2 == 1);
	elem = new float[count];
	for (int i = 0; i < count; i++) {
		elem[i] = GetRandomNumber(min, max);
	}
}

TArr::~TArr() {
	if (count > 0)
		delete[] elem;
}

float& TArr::operator[](int index) {
	return elem[index];
}


void SwapArr(TArr& arr) {
	float tmp;
	for (int i = 0; i < arr.count / 2; i++) {
		tmp = arr[i];
		arr[i] = arr[arr.count - i - 1];
		arr[arr.count - i - 1] = tmp;
	}
}