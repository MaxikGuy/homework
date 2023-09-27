#include <iostream>
#include <clocale>
#include <string>
#include "group.h"
#include "person.h"
#include "MyArr.h"
#include "windows.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		TGroup group;
		TPerson student;

		int ans = 1;
		int stp;

		while (ans) {
			system("cls");
			cout << group << endl;

			cout << "1. Найти студента по признаку." << endl;
			cout << "2. Добавить студента в группу." << endl;
			cout << "3. Удалить студента из группы." << endl;
			cout << "0. Выход.\n" << endl;

			
			do {
				cin >> ans;
			} while (ans < 0 || ans > 3);

			if (ans == 1) {
				system("cls");
				cout << "1. Найти по имени." << endl;
				cout << "2. Найти по фамилии." << endl;
				cout << "3. Найти по отчеству." << endl;
				cout << "4. Найти по дате рождения." << endl;
				cout << "5. Найти по номеру телефона.\n" << endl;

				int find_ans;
				do {
					cin >> find_ans;
				} while (find_ans <= 0 || find_ans > 5);

				string find_str;
				if (find_ans == 1) {
					cout << "Введите имя студента: ";
					cin >> find_str;
					TArr res = group.FindByName(find_str);
					if (res.count) {
						for (int i = 0; i < res.count; i++)
							cout << res[i] << ". " << group[res[i]] << endl;
					}
					else {
						cout << "Студента с именем \"" << find_str << "\" в группе нет." << endl;
					}
				}
				if (find_ans == 2) {
					cout << "Введите фамилию студента: ";
					cin >> find_str;
					TArr res = group.FindBySurname(find_str);
					if (res.count) {
						for (int i = 0; i < res.count; i++)
							cout << res[i] << ". " << group[res[i]] << endl;
					}
					else {
						cout << "Студента с фамилией \"" << find_str << "\" в группе нет." << endl;
					}
				}
				if (find_ans == 3) {
					cout << "Введите отчество студента: ";
					cin >> find_str;
					TArr res = group.FindByPatronymic(find_str);
					if (res.count) {
						for (int i = 0; i < res.count; i++)
							cout << res[i] << ". " << group[res[i]] << endl;
					}
					else {
						cout << "Студента с отчеством \"" << find_str << "\" в группе нет." << endl;
					}
				}
				if (find_ans == 4) {
					cout << "Введите дату рождения студента в формате ДД.ММ.ГГГГ: ";
					cin >> find_str;
					TArr res = group.FindByDate(find_str);
					if (res.count) {
						for (int i = 0; i < res.count; i++)
							cout << res[i] << ". " << group[res[i]] << endl;
					}
					else {
						cout << "Студента с датой рождения \"" << find_str << "\" в группе нет." << endl;
					}
				}
				if (find_ans == 5) {
					cout << "Введите номер телефона студента: ";
					cin >> find_str;
					int res = group.FindByPhone(find_str);
					if (res != -1)
						cout << res << ". " << group[res] << endl;
					else
						cout << "Студента с номером телефона \"" << find_str << "\" в группе нет." << endl;
					
				}
				cout << "\nНажмите любую клавишу для продолжения." << endl;
				cin >> stp;
			}
			if (ans == 2) {
				system("cls");
				cout << "Введите данные студента в формате" << endl;
				cout << "ФАМИЛИЯ ИМЯ ОТЧЕСТВО ДД.ММ.ГГГГ ТЕЛЕФОН\n" << endl;
				student.Set();

				int confirm = 0;
				system("cls");
				cout << "В группу будет добавлен студент" << endl;
				cout << group.GetCount() << ". " << student << endl;
				cout << "Добавить студдента в группу? (1/0)" << endl;
				cin >> confirm;
				if (confirm) {
					group.AddStudent(student);
					cout << "Добавление студента в группу завершено." << endl;
					cout << "\nНажмите любую клавишу для продолжения." << endl;
					cin >> stp;
				}
			}
			if (ans == 3) {
				system("cls");
				cout << "Введите номер удаляемого студента студента." << endl;
				int del_ind;
				do {
					cin >> del_ind;
				} while (del_ind < 0 || del_ind >= group.GetCount());

				int confirm = 0;
				cout << "Из группы будет удален студент:" << endl;
				cout << del_ind << ". " << group[del_ind] << endl;
				cout << "Удалить студента из группы? (1/0)" << endl;
				cin >> confirm;
				if (confirm) {
					group.DeleteStudent(del_ind);
					cout << "Удаление студента из группы завершено." << endl;
					cout << "\nНажмите любую клавишу для продолжения." << endl;
					cin >> stp;
				}

			}

		}

	}
	catch (string exp) {
		cout << exp << endl;
	}

	return 0;
}