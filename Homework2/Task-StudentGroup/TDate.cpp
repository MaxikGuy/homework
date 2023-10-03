#include <iostream>
#include <chrono>
#include <iomanip> // setfill(), setw()
#include "utility.h"
#include "TDate.h"
using namespace std;

TDate::TDate(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

TDate::TDate(const string& dateStr) {
	SetDateFromString(dateStr);
}

string TDate::StringDate() const {
	string ans = intToString(day, 2, '0') + intToString(month, 2, '0') + intToString(year, 2, '0');
	return ans;
}
ostream& operator<<(ostream& out, const TDate& date) {
	out << setfill('0') << setw(2) << date.day << '.' << setfill('0') << setw(2) << date.month << '.' << date.year;
	return out;
}
istream& operator>>(istream& in, TDate& date) {
	string dateStr;
	in >> dateStr;
	date.SetDateFromString(dateStr);
	return in;
}
const TDate& TDate::operator=(const TDate& date) {
	if (this == &date) return (*this);
	day = date.day;
	month = date.month;
	year = date.year;
	return *this;
}

bool TDate::operator==(const TDate& date) const {
	if (day == date.day && month == date.month && year == date.year)
		return true;
	return false;
}
bool TDate::operator!=(const TDate& date) const {
	return !((*this) == date);
}

void TDate::SetDateFromString(const string& dateStr) {
	if (sscanf_s(dateStr.c_str(), "%d.%d.%d", &day, &month, &year) != 3) {
		throw "Date scanning error";
	}
}