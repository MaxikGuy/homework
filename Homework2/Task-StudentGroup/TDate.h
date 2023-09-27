#ifndef _DATENTIME_H
#define _DATENTIME_H
#include <iostream>
#include <chrono>
#include <iomanip> // setfill(), setw()
#include "utility.h"
using namespace std;

struct TDate {
	int day;
	int month;
	int year;

	TDate(int d = 0, int m = 0, int y = 0) {
		day = d;
		month = m;
		year = y;
	}

	TDate(const string& dateStr) {
		SetDateFromString(dateStr);
	}

	string StringDate() const {
		string ans = intToString(day, 2, '0') + intToString(month, 2, '0') + intToString(year, 2, '0');
		return ans;
	}
	friend ostream& operator<<(ostream& out, const TDate& date) {
		out << setfill('0') << setw(2) << date.day << '.' << setfill('0') << setw(2) << date.month << '.' << date.year;
		return out;
	}
	friend istream& operator>>(istream& in, TDate& date) {
		string dateStr;
		in >> dateStr;
		date.SetDateFromString(dateStr);
		return in;
	}
	const TDate& operator=(const TDate& date) {
		if (this == &date) return (*this);
		day = date.day;
		month = date.month;
		year = date.year;
		return *this;
	}

	bool operator==(const TDate& date) const {
		if (day == date.day && month == date.month && year == date.year)
			return true;
		return false;
	}
	bool operator!=(const TDate& date) const {
		return !((*this) == date);
	}

	void SetDateFromString(const string& dateStr) {
		if (sscanf_s(dateStr.c_str(), "%d.%d.%d", &day, &month, &year) != 3) {
			throw "Date scanning error";
		}
	}
};

#endif // !_DATENTIME_H