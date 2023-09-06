#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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
};

int GetRandomNumber(int min, int max);

TArr Unique(const TArr& arr);


#endif // !FUNCTIONS_H