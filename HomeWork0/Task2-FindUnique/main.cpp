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

    int min = 1;
    int max = 5;

    TArr arr(min, max);
    cout << arr << endl;
    cout << Unique(arr);
    

    return 0;
}