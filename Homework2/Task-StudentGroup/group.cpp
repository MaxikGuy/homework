#include <iostream>
#include <fstream>
#include <sstream>
#include "group.h"

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

void TGroup::FindByName(string name) {
	bool flag = true;
	for (int i = 0; i < count; i++)
		if (students[i].GetName() == name) {
			cout << i << ". " << students[i] << endl;
			flag = false;
		}
	if (flag)
		cout << "Студентов с таким именем не найдено." << endl;
}
void TGroup::FindBySurname(string surname) {
	bool flag = true;
	for (int i = 0; i < count; i++)
		if (students[i].GetSurname() == surname) {
			cout << i << ". " << students[i] << endl;
			flag = false;
		}
	if (flag)
		cout << "Студентов с такой фамилией не найдено." << endl;
}
void TGroup::FindByPatronymic(string patronymic) {
	bool flag = true;
	for (int i = 0; i < count; i++)
		if (students[i].GetPatronymic() == patronymic) {
			cout << i << ". " << students[i] << endl;
			flag = false;
		}
	if (flag)
		cout << "Студентов с таким отчеством не найдено." << endl;
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

void TGroup::FindByDate(string date) {
	bool flag = true;
	for (int i = 0; i < count; i++)
		if (students[i].GetDate() == date) {
			cout << i << ". " << students[i] << endl;
			flag = false;
		}
	if (flag)
		cout << "Студентов с такой датой рождения не найдено." << endl;
}
void TGroup::FindByDay(int day) {
	bool flag = true;
	for (int i = 0; i < count; i++)
		if (students[i].GetDay() == day) {
			cout << i << ". " << students[i] << endl;
			flag = false;
		}
	if (flag)
		cout << "Студентов с таким днем рождения не найдено." << endl;
}
void TGroup::FindByMonth(int month) {
	bool flag = true;
	for (int i = 0; i < count; i++)
		if (students[i].GetMonth() == month) {
			cout << i << ". " << students[i] << endl;
			flag = false;
		}
	if (flag)
		cout << "Студентов с таким месяцем рождения не найдено." << endl;
}
void TGroup::FindByYear(int year) {
	bool flag = true;
	for (int i = 0; i < count; i++)
		if (students[i].GetYear() == year) {
			cout << i << ". " << students[i] << endl;
			flag = false;
		}
	if (flag)
		cout << "Студентов с таким годом рождения не найдено." << endl;
}

void TGroup::FindByPhone(string phone) {
	bool flag = true;
	for (int i = 0; i < count; i++)
		if (students[i].GetPhone() == phone) {
			cout << i << ". " << students[i] << endl;
			flag = false;
		}
	if (flag)
		cout << "Студентов с таким днем рождения не найдено." << endl;
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
	if (index < count) throw "error: index out of range";
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