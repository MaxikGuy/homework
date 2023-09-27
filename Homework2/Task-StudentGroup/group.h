#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include "person.h"
#include "MyArr.h"

using namespace std;

class TGroup {
private:
	int size;
	int count;
	TPerson* students;

public:
	TGroup(const string& filename = "data.txt");
	TGroup(const TGroup& grp);
	~TGroup();

	void ScanFile(const string& filename = "data.txt");

	TArr FindByName(string name);
	TArr FindBySurname(string surname);
	TArr FindByPatronymic(string patronymic);

	int FindStudent(const TPerson& p);

	TArr FindByDate(string date);
	TArr FindByDay(int day);
	TArr FindByMonth(int month);
	TArr FindByYear(int year);

	int FindByPhone(string phone);

	void AddStudent();
	void AddStudent(const TPerson& p);

	void DeleteStudent(int index);
	void DeleteStudent(const TPerson& p);


	int GetCount() const { return count; }

	TPerson& operator[](int index);

	friend ostream& operator<<(ostream& out, const TGroup& grp) {
		for (int i = 0; i < grp.count; i++)
			out << i << ". " << grp.students[i] << endl;
		return out;
	}

protected:
	void resize(int dsize = 5);
	void ChangeMemorry(int _size);
};

#endif // !GROUP_H