#include <iostream>
#include <stdlib.h>
#include "functions.h"
#include "..\MyArr\MyArr.h"

using namespace std;


TArr Unique(const TArr& arr) {
	int c_uniq = 1;
    for (int i = 1; i < arr.count; i++) {
        int flag = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) c_uniq++;
    }

	TArr tmp(c_uniq);
	int i_tmp = 1;
	tmp[0] = arr[0];

	for (int i = 1; i < arr.count; i++) {
		int flag = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			tmp[i_tmp++] = arr[i];
		}
	}
	return tmp;
}