// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Windows.h" // För att GetTickCount() skall fungera..
#include <algorithm>
#include <iostream>

using namespace std;

void mergeSort(float * arr, int size) {
    float * temparr = new float[size];

    int LE, RE, L, R, CLU, ARR;

    for (int intervallSize = 2; intervallSize <= size; intervallSize *= 2) {
        ARR = 0;
        for (CLU = 0; CLU < size; CLU += intervallSize) {
            L = CLU;
            R = CLU + (intervallSize / 2);
            RE = CLU + intervallSize;
            LE = CLU + (intervallSize / 2);

            while (L < LE && R < RE) {
                if (arr[L] < arr[R]) {
                    temparr[ARR] = arr[L];
                    ARR++;
                    L++;
                }
                else {
                    temparr[ARR] = arr[R];
                    ARR++;
                    R++;
                }
            }

            if (L != LE) {
                while (L < LE) {
                    temparr[ARR] = arr[L];
                    ARR++;
                    L++;
                }
            }
            else if (R != RE) {
                while (R < RE) {
                    temparr[ARR] = arr[R];
                    ARR++;
                    R++;
                }
            }

            /*for (int i = CLU; i < (CLU + intervallSize); ++i)
                arr[i] = temparr[i];*/
        }

        for (int i = 0; i < size; i++) {
            arr[i] = temparr[i];
        }
    }
}


int _tmain(int argc, _TCHAR* argv[])
{
    const int size = 1048576;
    float * arr = new float[size];

    for (int i = 0; i < size; i++)
        arr[i] = (float) rand() / RAND_MAX;

    int ticks = GetTickCount();
    mergeSort((arr), size);
    ticks = GetTickCount() - ticks;

    cout << "Ms: " << ticks << endl;
    system("pause");
    return 0;
}

