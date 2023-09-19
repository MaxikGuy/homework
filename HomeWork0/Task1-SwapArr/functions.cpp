#include <iostream>
#include <stdlib.h>
#include "functions.h"
#include "..\MyArr\MyArr.h"

using namespace std;

void SwapArr(TArr& arr) {
	float tmp;
	for (int i = 0; i < arr.count / 2; i++) {
		tmp = arr[i];
		arr[i] = arr[i + arr.count / 2];
		arr[i + arr.count / 2] = tmp;
	}
}