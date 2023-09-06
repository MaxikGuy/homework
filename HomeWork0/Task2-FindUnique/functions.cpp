#include <iostream>
#include <stdlib.h>
#include "functions.h"

using namespace std;

int GetRandomNumber(int min, int max) {
	int num = min + rand() % (max - min + 1);
	return num;
}

TArr::TArr(int min, int max) {
	cout << "¬ведите кол-во элементов массива: ";
	do {
		cin >> count;
	} while (count <= 0);
	elem = new int[count];
	for (int i = 0; i < count; i++) {
		elem[i] = GetRandomNumber(min, max);
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


TArr Unique(const TArr& arr) {
	int c_uniq = 1;
    for (int i = 1; i < arr.count; i++) {
        int flag = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) c_uniq++;
    }

	TArr tmp(c_uniq);
	int i_tmp = 1;
	tmp[0] = arr[0];

	for (int i = 1; i < arr.count; i++) {
		int flag = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			tmp[i_tmp++] = arr[i];
		}
	}
	return tmp;
}