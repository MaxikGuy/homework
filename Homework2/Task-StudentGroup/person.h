#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

#include "TDate.h"

using namespace std;

struct TPerson {
	string name;		// ���
	string surname;		// �������
	string patronymic;	// ��������
	TDate date_of_birth;
	string phone_number;

	TPerson();
	TPerson(string _surname, string _name, string _patronymic, string _date_of_birthStr, string _phone_number);
	TPerson(const TPerson& p);

	friend istream& operator>>(istream& in, TPerson& p) {
		in >> p.surname >> p.name >> p.patronymic >> p.date_of_birth >> p.phone_number;
		return in;
	}
	friend ostream& operator<<(ostream& out, const TPerson& p) {
		out << p.surname << ' ' << p.name << ' ' << p.patronymic << ", " << p.date_of_birth << ", " << p.phone_number << ' ';
		return out;
	}
	
	void Set();

	string GetDate() const;
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

	bool operator==(const TPerson& p) const;
	bool operator!=(const TPerson& p) const;

};

#endif // !PERSON_H