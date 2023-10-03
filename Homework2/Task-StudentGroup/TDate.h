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

	TDate(int d = 0, int m = 0, int y = 0);
	TDate(const string& dateStr);

	string StringDate() const;

	friend ostream& operator<<(ostream& out, const TDate& date);
	friend istream& operator>>(istream& in, TDate& date);
	
	const TDate& operator=(const TDate& date);

	bool operator==(const TDate& date) const;
	bool operator!=(const TDate& date) const;

	void SetDateFromString(const string& dateStr);
};

#endif // !_DATENTIME_H