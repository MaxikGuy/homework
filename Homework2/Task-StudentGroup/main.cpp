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

			cout << "1. ����� �������� �� ��������." << endl;
			cout << "2. �������� �������� � ������." << endl;
			cout << "3. ������� �������� �� ������." << endl;
			cout << "0. �����.\n" << endl;

			
			do {
				cin >> ans;
			} while (ans < 0 || ans > 3);

			if (ans == 1) {
				system("cls");
				cout << "1. ����� �� �����." << endl;
				cout << "2. ����� �� �������." << endl;
				cout << "3. ����� �� ��������." << endl;
				cout << "4. ����� �� ���� ��������." << endl;
				cout << "5. ����� �� ������ ��������.\n" << endl;

				int find_ans;
				do {
					cin >> find_ans;
				} while (find_ans <= 0 || find_ans > 5);

				string find_str;
				if (find_ans == 1) {
					cout << "������� ��� ��������: ";
					cin >> find_str;
					TArr res = group.FindByName(find_str);
					if (res.count) {
						for (int i = 0; i < res.count; i++)
							cout << res[i] << ". " << group[res[i]] << endl;
					}
					else {
						cout << "�������� � ������ \"" << find_str << "\" � ������ ���." << endl;
					}
				}
				if (find_ans == 2) {
					cout << "������� ������� ��������: ";
					cin >> find_str;
					TArr res = group.FindBySurname(find_str);
					if (res.count) {
						for (int i = 0; i < res.count; i++)
							cout << res[i] << ". " << group[res[i]] << endl;
					}
					else {
						cout << "�������� � �������� \"" << find_str << "\" � ������ ���." << endl;
					}
				}
				if (find_ans == 3) {
					cout << "������� �������� ��������: ";
					cin >> find_str;
					TArr res = group.FindByPatronymic(find_str);
					if (res.count) {
						for (int i = 0; i < res.count; i++)
							cout << res[i] << ". " << group[res[i]] << endl;
					}
					else {
						cout << "�������� � ��������� \"" << find_str << "\" � ������ ���." << endl;
					}
				}
				if (find_ans == 4) {
					cout << "������� ���� �������� �������� � ������� ��.��.����: ";
					cin >> find_str;
					TArr res = group.FindByDate(find_str);
					if (res.count) {
						for (int i = 0; i < res.count; i++)
							cout << res[i] << ". " << group[res[i]] << endl;
					}
					else {
						cout << "�������� � ����� �������� \"" << find_str << "\" � ������ ���." << endl;
					}
				}
				if (find_ans == 5) {
					cout << "������� ����� �������� ��������: ";
					cin >> find_str;
					int res = group.FindByPhone(find_str);
					if (res != -1)
						cout << res << ". " << group[res] << endl;
					else
						cout << "�������� � ������� �������� \"" << find_str << "\" � ������ ���." << endl;
					
				}
				cout << "\n������� ����� ������� ��� �����������." << endl;
				cin >> stp;
			}
			if (ans == 2) {
				system("cls");
				cout << "������� ������ �������� � �������" << endl;
				cout << "������� ��� �������� ��.��.���� �������\n" << endl;
				student.Set();

				int confirm = 0;
				system("cls");
				cout << "� ������ ����� �������� �������" << endl;
				cout << group.GetCount() << ". " << student << endl;
				cout << "�������� ��������� � ������? (1/0)" << endl;
				cin >> confirm;
				if (confirm) {
					group.AddStudent(student);
					cout << "���������� �������� � ������ ���������." << endl;
					cout << "\n������� ����� ������� ��� �����������." << endl;
					cin >> stp;
				}
			}
			if (ans == 3) {
				system("cls");
				cout << "������� ����� ���������� �������� ��������." << endl;
				int del_ind;
				do {
					cin >> del_ind;
				} while (del_ind < 0 || del_ind >= group.GetCount());

				int confirm = 0;
				cout << "�� ������ ����� ������ �������:" << endl;
				cout << del_ind << ". " << group[del_ind] << endl;
				cout << "������� �������� �� ������? (1/0)" << endl;
				cin >> confirm;
				if (confirm) {
					group.DeleteStudent(del_ind);
					cout << "�������� �������� �� ������ ���������." << endl;
					cout << "\n������� ����� ������� ��� �����������." << endl;
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