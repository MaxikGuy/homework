#include "functions.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>

#define MIN 0
#define MAX 30

using namespace std;

float GetRandomNumber(int min, int max) {
	int num = min + rand() % (max - min + 1);

	return (float)num;
}

TArr::TArr() {
	cout << "Input count of elements in array: ";
	do {
		cin >> count;
	} while (count <= 0);
	elem = new float[count];
	for (int i = 0; i < count; i++) {
		elem[i] = GetRandomNumber(MIN, MAX);
	}
}

TArr::TArr(int _count) {
	count = _count;
	elem = new float[count];
	for (int i = 0; i < count; i++) {
		elem[i] = GetRandomNumber(MIN, MAX);
	}
}

TArr::TArr(int _count, int min, int max) {
	count = _count;
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


void ChangeToSqrt(TArr& arr, float MoreThan) {
	for (int i = 0; i < arr.count; i++) {
		if (arr[i] >= MoreThan)
			arr[i] = sqrt(arr[i]);
	}
}

