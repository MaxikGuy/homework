#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

struct TArr {
	int count;
	float* elem;
	TArr();
	TArr(int _count);
	TArr(int _count, int min, int max);
	~TArr();

	float& operator[](int index);
	friend std::ostream& operator<<(std::ostream& out, const TArr& arr) {
		for (int i = 0; i < arr.count; i++)
			out << arr.elem[i] << ' ';
		return out;
	}
};

float GetRandomNumber(int min, int max);


void ChangeToSqrt(TArr& arr, float MoreThan = 10);


#endif // !FUNCTIONS_H