#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MIN 0
#define MAX 50

#include <iostream>

struct TArr {
	int count;
	float* elem;
	TArr(int min = MIN, int max = MAX);
	~TArr();

	float& operator[](int index);
	friend std::ostream& operator<<(std::ostream& out, const TArr& arr) {
		for (int i = 0; i < arr.count; i++)
			out << arr.elem[i] << ' ';
		return out;
	}
};

float GetRandomNumber(int min, int max);

void SwapArr(TArr& arr);


#endif // !FUNCTIONS_H