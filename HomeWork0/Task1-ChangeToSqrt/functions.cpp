#include "functions.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "..\MyArr\MyArr.h"

using namespace std;


void ChangeToSqrt(TArr_f& arr, float MoreThan) {
	for (int i = 0; i < arr.count; i++) {
		if (arr[i] >= MoreThan)
			arr[i] = sqrt(arr[i]);
	}
}

