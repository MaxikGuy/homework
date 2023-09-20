#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class TPerson {
private:
	string name;		// Имя
	string surname;		// Фамилия
	string patronymic;	// Отчество
	string date_of_birth;
	string phone_number;
public:
	TPerson(string name, string surname, string patronymic, string phone_number, string date_of_birth);
	TPerson(const TPerson& p);

	friend istream& operator>>(istream& in, TPerson& p) {
		in >> p.name >> p.surname >> p.patronymic >> p.phone_number >> p.date_of_birth;
		return in;
	}
	friend ostream& operator<<(ostream& out, const TPerson& p) {
		out << p.name << ' ' << p.surname << ' ' << p.patronymic << ' ' << p.date_of_birth << ' ' << p.phone_number << ' ';
		return out;
	}

	void SetName(string _name);
	void SetSurname(string _surname);
	void SetPatronymic(string _patronymic);
	void SetDate(string _date);
	void SetPhone(string _phone);



};

#endif // !PERSON_H