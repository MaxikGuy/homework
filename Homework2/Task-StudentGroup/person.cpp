#include <iostream>
#include <string>
#include "person.h"

TPerson::TPerson() {
	name = "";
	surname = "";
	patronymic = "";
	date_of_birth.SetDateFromString("01.01.1900");
	phone_number = "+79000000000";
}
TPerson::TPerson(string _surname, string _name, string _patronymic, string _date_of_birthStr, string _phone_number) {
	name = _name;
	surname = _surname;
	patronymic = _patronymic;
	date_of_birth.SetDateFromString(_date_of_birthStr);
	phone_number = _phone_number;
}
TPerson::TPerson(const TPerson& p) {
	name = p.name;
	surname = p.surname;
	patronymic = p.patronymic;
	date_of_birth = p.date_of_birth;
	phone_number = p.phone_number;
}


void TPerson::Set() {
	cout << "name = ";
	cin >> name;
	cout << "surname = ";
	cin >> surname;
	cout << "patronymic = ";
	cin >> patronymic;
	cout << "phone_number = ";
	cin >> phone_number;
	cout << "date_of_birth = ";
	cin >> date_of_birth;
}

string TPerson::GetDate() const {
	return date_of_birth.StringDate();
}
int TPerson::GetDay() const {
	return date_of_birth.day;
}
int TPerson::GetMonth() const {
	return date_of_birth.month;
}
int TPerson::GetYear() const {
	return date_of_birth.year;
}

bool TPerson::operator==(const TPerson& p) const {
	return (name == p.name && surname == p.surname && patronymic == p.patronymic && date_of_birth == p.date_of_birth && phone_number == p.phone_number);
}
bool TPerson::operator!=(const TPerson& p) const {
	return !((*this) == p);
}