#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include "person.h"

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

	void FindByName(string name);
	void FindBySurname(string surname);
	void FindByPatronymic(string patronymic);

	int FindStudent(const TPerson& p);

	void FindByDate(string date);
	void FindByDay(int day);
	void FindByMonth(int month);
	void FindByYear(int year);

	void AddStudent();
	void AddStudent(const TPerson& p);

	void DeleteStudent(int index);
	void DeleteStudent(const TPerson& p);

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