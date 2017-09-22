#include "gist.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void gist (double* arr, int n, double left, double step, int length, int precision1, int precision2) {
    vector < int > mas(length,0);
    for (int i=0; i<n; ++i)
    if (arr[i]>=left){
        int j=0;
        while (left+(j+1)*step<arr[i] && j<length) ++j;
        if (j<length) ++mas[j];
    }
    for (int i=0; i<length; ++i) {
        cout.precision(precision1);
        cout << "[";
        cout.width(precision1+3);
        cout << left+i*step << ";";
        cout.width(precision1+3);
        cout << left+(i+1)*(step) << "]  -  ";
        cout.precision(precision2);
        cout << (double) mas[i]/n << endl;
    }
}
