#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class Vector {
private:
	int size;
	T* elem;
public:
	Vector(int _size = 10);
	//Vector(const Vector<T>& v);
	~Vector();

	const Vector<T>& operator=(const Vector<T>& v);

	Vector<T> operator+(const Vector<T>& v);
	Vector<T> operator-(const Vector<T>& v);
	double operator*(const Vector<T>& v);

	bool operator==(const Vector<T>& v);
	bool operator!=(const Vector<T>& v);

	double mod();

	friend ostream& operator<<(ostream& out, const Vector<T>& v) {
		out << "(" << v.elem[0] << ", ";
		for (int i = 1; i < v.size - 1; i++)
			out << v.elem[i] << ", ";
		out << v.elem[v.size - 1] << ") ";
		return out;
	}
	friend istream& operator>>(istream& in, Vector<T>& v) {
		for (int i = 0; i < v.size; i++)
			in >> v.elem[i];
		return in;
	}
};

template <typename T>
Vector<T>::Vector(int _size) {
	if (_size <= 0) throw "size error";
	size = _size;
	elem = new T[size];
}
/*
template <typename T>
Vector<T>::Vector(const Vector<T>& v) {
	if (size != v.size) {
		delete[] elem;
		size = v.size;
		elem = new T[size];
	}
	for (int i = 0; i < size; i++)
		elem[i] = v.elem[i];
}*/
template <typename T>
Vector<T>::~Vector() {
	if (size > 0)
		delete[] elem;
}

template <typename T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
	if (size != v.size) {
		delete[] elem;
		size = v.size;
		elem = new T[size];
	}
	for (int i = 0; i < size; i++)
		elem[i] = v.elem[i];
	return (*this);
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& v) {
	if (size != v.size) throw "size error";
	Vector<T> tmp(size);
	for (int i = 0; i < size; i++)
		tmp.elem[i] = elem[i] + v.elem[i];
	return tmp;
}
template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& v) {
	if (size != v.size) throw "size error";
	Vector<T> tmp(size);
	for (int i = 0; i < size; i++)
		tmp.elem[i] = elem[i] - v.elem[i];
	return tmp;
}
template <typename T>
double Vector<T>::operator*(const Vector<T>& v) {
	if (size != v.size) throw "size error";
	T ans = 0;
	for (int i = 0; i < size; i++)
		ans += elem[i] * v.elem[i];
	return (double)ans;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& v) {
	if (this == &v) return true;
	if (size != v.size) return false;
	for (int i = 0; i < size; i++)
		if (elem[i] != v.elem[i])
			return false;
	return true;
}
template <typename T>
bool Vector<T>::operator!=(const Vector<T>& v) {
	return !((*this) == v);
}

template <typename T>
double Vector<T>::mod() {
	T ans = 0;
	for (int i = 0; i < size; i++)
		ans += elem[i] * elem[i];
	return sqrt((double)ans);
}

#endif // !VECTOR_H