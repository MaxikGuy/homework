#include <iostream>
#include <stdlib.h>
#include "MyArr.h"

using namespace std;

int GetRandomInt(int min, int max) {
	int num = min + rand() % (max - min + 1);
	return num;
}

float GetRandomFloat(int min, int max) {
	int num = min + rand() % (max - min + 1);
	return (float)num;
}


////// INT //////

TArr::TArr(int min, int max) {
	cout << "Введите кол-во элементов массива: ";
	do {
		cin >> count;
	} while (count <= 0);
	elem = new int[count];
	for (int i = 0; i < count; i++) {
		elem[i] = GetRandomInt(min, max);
	}
}

TArr::TArr(int _count) {
	if (_count <= 0) throw "error";
	count = _count;
	elem = new int[count];
}

TArr::TArr(const TArr& arr) {
	count = arr.count;
	elem = new int[count];
	for (int i = 0; i < count; i++)
		elem[i] = arr[i];
}

TArr::~TArr() {
	if (count > 0)
		delete[] elem;
}

int& TArr::operator[](int index) {
	return elem[index];
}
const int& TArr::operator[](int index) const {
	return elem[index];
}

TArr& TArr::operator=(const TArr& arr) {
	if (this != &arr) {
		delete[] elem;
		count = arr.count;
		elem = new int[count];
		for (int i = 0; i < count; i++)
			elem[i] = arr[i];
	}
	return *this;
}

void TArr::Fill() {
	for (int i = 0; i < count; i++) {
		cin >> elem[i];
	}
}
void TArr::FillRand(int min, int max) {
	for (int i = 0; i < count; i++) {
		elem[i] = GetRandomInt(min, max);
	}
}



////// FLOAT //////

TArr_f::TArr_f(int min, int max) {
	cout << "Введите кол-во элементов массива: ";
	do {
		cin >> count;
	} while (count <= 0);
	elem = new float[count];
	for (int i = 0; i < count; i++) {
		elem[i] = GetRandomFloat(min, max);
	}
}

TArr_f::TArr_f(int _count) {
	if (_count <= 0) throw "error";
	count = _count;
	elem = new float[count];
}

TArr_f::TArr_f(const TArr_f& arr) {
	count = arr.count;
	elem = new float[count];
	for (int i = 0; i < count; i++)
		elem[i] = arr[i];
}

TArr_f::~TArr_f() {
	if (count > 0)
		delete[] elem;
}

float& TArr_f::operator[](int index) {
	return elem[index];
}
const float& TArr_f::operator[](int index) const {
	return elem[index];
}

TArr_f& TArr_f::operator=(const TArr_f& arr) {
	if (this != &arr) {
		delete[] elem;
		count = arr.count;
		elem = new float[count];
		for (int i = 0; i < count; i++)
			elem[i] = arr[i];
	}
	return *this;
}

void TArr_f::Fill() {
	for (int i = 0; i < count; i++) {
		cin >> elem[i];
	}
}
void TArr_f::FillRand(int min, int max) {
	for (int i = 0; i < count; i++) {
		elem[i] = GetRandomFloat(min, max);
	}
}