#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <clocale>
#include "functions.h"
#include "..\MyArr\MyArr.h"


using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int min = 0;
    int max = 20;
    int n;

    cout << "Введите четное кол-во элементов: ";
    do {
        cin >> n;
    } while (n % 2 != 0);

    TArr arr(n);
    arr.FillRand(min, max);
    cout << arr << endl;
    SwapArr(arr);
    cout << arr << endl;

    return 0;
}