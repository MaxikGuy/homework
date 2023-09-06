#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include <cmath>

using namespace std;


int main()
{
    srand(time(NULL));
    TArr arr;
    cout << arr << endl;
    ChangeToSqrt(arr);
    cout << arr << endl;

    return 0;
}