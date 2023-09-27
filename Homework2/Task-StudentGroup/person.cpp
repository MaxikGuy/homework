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
/*
void TPerson::Set(string _surname, string _name, string _patronymic, string _date_of_birthStr, string _phone_number) {
	name = _name;
	surname = _surname;
	patronymic = _patronymic;
	date_of_birth.SetDateFromString(_date_of_birthStr);
	phone_number = _phone_number;
}
void TPerson::SetName(string _name) {
	name = _name;
}
void TPerson::SetSurname(string _surname){
	surname = _surname;
}
void TPerson::SetPatronymic(string _patronymic) {
	patronymic = _patronymic;
}
void TPerson::SetDate(string _dateStr) {
	date_of_birth.SetDateFromString(_dateStr);
}
void TPerson::SetPhone(string _phone_number) {
	phone_number = _phone_number;
}


string TPerson::GetName() {
	return name;
}
string TPerson::GetSurname() {
	return surname;
}
string TPerson::GetPatronymic() {
	return patronymic;
}

string TPerson::GetPhone() {
	return phone_number;
}*/

string TPerson::GetDate() {
	return date_of_birth.StringDate();
}
int TPerson::GetDay() {
	return date_of_birth.day;
}
int TPerson::GetMonth() {
	return date_of_birth.month;
}
int TPerson::GetYear() {
	return date_of_birth.year;
}

bool TPerson::operator==(const TPerson& p) const {
	return (name == p.name && surname == p.surname && patronymic == p.patronymic && date_of_birth == p.date_of_birth && phone_number == p.phone_number);
}
bool TPerson::operator!=(const TPerson& p) const {
	return !((*this) == p);
}