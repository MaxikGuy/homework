#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <clocale>
#include "functions.h"


using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    TArr arr;
    cout << arr << endl;
    SwapArr(arr);
    cout << arr << endl;

    return 0;
}