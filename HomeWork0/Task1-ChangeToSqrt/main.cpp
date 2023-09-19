#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include <cmath>
#include <clocale>
#include "..\MyArr\MyArr.h"

using namespace std;


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");

    int min = 5;
    int max = 20;

    TArr_f arr(min, max);
    cout << arr << endl;
    ChangeToSqrt(arr);
    cout << arr << endl;

    return 0;
}