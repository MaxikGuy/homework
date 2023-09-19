#ifndef _MYARR_H
#define _MYARR_H

#include <iostream>

struct TArr {
	int count;
	int* elem;

	TArr(int _count);
	TArr(int min, int max);
	TArr(const TArr& arr);
	~TArr();

	int& operator[](int index);
	const int& operator[](int index) const;

	TArr& operator=(const TArr& arr);

	friend std::ostream& operator<<(std::ostream& out, const TArr& arr) {
		for (int i = 0; i < arr.count; i++)
			out << arr.elem[i] << ' ';
		return out;
	}

	void Fill();
	void FillRand(int min, int max);
};

struct TArr_f {
	int count;
	float* elem;

	TArr_f(int _count);
	TArr_f(int min, int max);
	TArr_f(const TArr_f& arr);
	~TArr_f();

	float& operator[](int index);
	const float& operator[](int index) const;

	TArr_f& operator=(const TArr_f& arr);

	friend std::ostream& operator<<(std::ostream& out, const TArr_f& arr) {
		for (int i = 0; i < arr.count; i++)
			out << arr.elem[i] << ' ';
		return out;
	}

	void Fill();
	void FillRand(int min, int max);
};

int GetRandomInt(int min, int max);
float GetRandomFloat(int min, int max);

#endif // !_MYARR_H