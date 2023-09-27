#include <iostream>
#include <fstream>
#include <sstream>
#include "group.h"
#include "MyArr.h"

using namespace std;

TGroup::TGroup(const string& filename) {
	ScanFile(filename);
}
TGroup::TGroup(const TGroup& grp) {
	size = grp.size;
	count = grp.count;
	students = new TPerson[size];
	for (int i = 0; i < count; i++) {
		students[i] = grp.students[i];
	}
}
TGroup::~TGroup() {
	if (size > 0) {
		delete[] students;
	}
}

void TGroup::ScanFile(const string& filename) {
	ifstream file(filename);
	string line;

	if (file.is_open()) {
		ChangeMemorry(30);
		while (getline(file, line)){
			istringstream iss(line);
			string name;
			string surname;
			string patronymic;
			string date_of_birth;
			string phone_number;

			if (iss >> name >> surname >> patronymic >> date_of_birth >> phone_number) {
				TPerson tmp(name, surname, patronymic, date_of_birth, phone_number);
				AddStudent(tmp);
			}
			else {
				file.close();
				string exp = "Error reading data from string: " + line;
				throw exp;
			}
		}
		file.close();
	}
	else {
		string exp = "Can't open file: " + filename;
		throw exp;
	}
}

//////////////////////////////////////
TArr TGroup::FindByName(string name) {
	int ind_count = 0;

	for (int i = 0; i < count; i++)
		if (students[i].name == name) {
			ind_count++;
		}

	if (!ind_count) {
		TArr res;
		return res;
	}

	TArr res(ind_count);
	int ind = 0;
	for (int i = 0; i < count; i++) {
		if (students[i].name == name)
			res[ind++] = i;
	}

	return res;
}
TArr TGroup::FindBySurname(string surname) { // students[i].surname == surname
	int ind_count = 0;

	for (int i = 0; i < count; i++)
		if (students[i].surname == surname) {
			ind_count++;
		}

	if (!ind_count) {
		TArr res;
		return res;
	}

	TArr res(ind_count);
	int ind = 0;
	for (int i = 0; i < count; i++) {
		if (students[i].surname == surname)
			res[ind++] = i;
	}

	return res;
}
TArr TGroup::FindByPatronymic(string patronymic) { // students[i].patronymic == patronymic
	int ind_count = 0;

	for (int i = 0; i < count; i++)
		if (students[i].patronymic == patronymic) {
			ind_count++;
		}

	if (!ind_count) {
		TArr res;
		return res;
	}

	TArr res(ind_count);
	int ind = 0;
	for (int i = 0; i < count; i++) {
		if (students[i].patronymic == patronymic)
			res[ind++] = i;
	}

	return res;
}

int TGroup::FindStudent(const TPerson& p) {
	int ind = -1;
	for (int i = 0; i < count; i++)
		if (students[i] == p) {
			ind = i;
			break;
		}
	return ind;
}

TArr TGroup::FindByDate(string date) { // students[i].GetDate() == date
	int ind_count = 0;

	for (int i = 0; i < count; i++)
		if (students[i].GetDate() == date) {
			ind_count++;
		}

	if (!ind_count) {
		TArr res;
		return res;
	}

	TArr res(ind_count);
	int ind = 0;
	for (int i = 0; i < count; i++) {
		if (students[i].GetDate() == date)
			res[ind++] = i;
	}

	return res;
}
TArr TGroup::FindByDay(int day) { // students[i].GetDay() == day
	int ind_count = 0;

	for (int i = 0; i < count; i++)
		if (students[i].GetDay() == day) {
			ind_count++;
		}

	if (!ind_count) {
		TArr res;
		return res;
	}

	TArr res(ind_count);
	int ind = 0;
	for (int i = 0; i < count; i++) {
		if (students[i].GetDay() == day)
			res[ind++] = i;
	}

	return res;
}
TArr TGroup::FindByMonth(int month) { // students[i].GetMonth() == month
	int ind_count = 0;

	for (int i = 0; i < count; i++)
		if (students[i].GetMonth() == month) {
			ind_count++;
		}

	if (!ind_count) {
		TArr res;
		return res;
	}

	TArr res(ind_count);
	int ind = 0;
	for (int i = 0; i < count; i++) {
		if (students[i].GetMonth() == month)
			res[ind++] = i;
	}

	return res;
}
TArr TGroup::FindByYear(int year) { // students[i].GetYear() == year
	int ind_count = 0;

	for (int i = 0; i < count; i++)
		if (students[i].GetYear() == year) {
			ind_count++;
		}

	if (!ind_count) {
		TArr res;
		return res;
	}

	TArr res(ind_count);
	int ind = 0;
	for (int i = 0; i < count; i++) {
		if (students[i].GetYear() == year)
			res[ind++] = i;
	}

	return res;
}

int TGroup::FindByPhone(string phone) {
	int res = -1;
	for (int i = 0; i < count; i++)
		if (students[i].phone_number == phone) {
			res = i;
			break;
		}
	return res;
}

void TGroup::AddStudent() {
	TPerson tmp;
	tmp.Set();
	AddStudent(tmp);
}
void TGroup::AddStudent(const TPerson& p) {
	if (FindStudent(p) == -1) {
		if (size == count)
			resize();
		students[count++] = p;
	}
}

void TGroup::DeleteStudent(int index) {
	if (index > -1 && index < count)
		for (int i = index; i < count - 1; i++)
			students[i] = students[i + 1];
	count--;
}
void TGroup::DeleteStudent(const TPerson& p) {
	DeleteStudent(FindStudent(p));
}

TPerson& TGroup::operator[](int index) {
	if (index >= count) throw "error: index out of range";
	return students[index];
}

void TGroup::resize(int dsize) {
	if (dsize <= 0) throw "error resize of group";
	size += dsize;
	TPerson* tmp = new TPerson[size];
	for (int i = 0; i < count; i++)
		tmp[i] = students[i];
	delete[] students;
	students = tmp;
}
void TGroup::ChangeMemorry(int _size) {
	if (size > 0) {
		delete[] students;
		size = _size;
		count = 0;
		students = new TPerson[size];
	}
}