#include <iostream>
#include <clocale>
#include "group.h"
#include "person.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	
	TGroup test;
	TPerson me("��������", "������", "��������", "04.02.2004", "+79307046086");
	

	cout << test << endl;

	//string name = "������";
	//test.FindByName(name);

	test.AddStudent(me);
	cout << test << endl;

	test.DeleteStudent(0);
	cout << test << endl;

	return 0;
}