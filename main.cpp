#include "random.h"
#include "gist.h"
#include <iostream>
#include <ctime>
using namespace std;

void fillfRand(double (*fRand[])()) {
    fRand[0]=rand_1;
    fRand[1]=rand_2;
    fRand[2]=rand_3;
    fRand[3]=rand_4;
    fRand[4]=rand_5;
    fRand[5]=rand_6;
    fRand[6]=rand_7;
    fRand[7]=rand_8;
    fRand[8]=rand_9;
    fRand[9]=rand_10;
}

void fillfSRand(void (*fSRand[])(unsigned int)) {
    fSRand[0]=srand_1;
    fSRand[1]=srand_2;
    fSRand[2]=srand_3;
    fSRand[3]=srand_4;
    fSRand[4]=srand_5;
    fSRand[5]=srand_6;
    fSRand[6]=srand_7;
    fSRand[7]=srand_8;
    fSRand[8]=srand_9;
    fSRand[9]=srand_10;
}

const int count=10000;
const double left_1=0;
const double left_2=-3;
const double left_3=0;
const double length_1=10;
const double length_2=10;
const double length_3=20;
const double step_1=0.1;
const double step_2=0.6;
const double step_3=5;
const int precision_1=1;
const int precision_2=1;
const int precision_3=0;
const int ansPrecision=4;

int main()
{
    cout << fixed;
    double (*fRand[10])();
    void (*fSRand[10])(unsigned int);
    double left[10];
    double length[10];
    double step[10];
    int precision[10];

    fillfRand(fRand);
    fillfSRand(fSRand);
    for (int i=0; i<5; ++i) {
        left[i]=left_1;
        length[i]=length_1;
        step[i]=step_1;
        precision[i]=precision_1;
    }
    for (int i=5; i<8; ++i) {
        left[i]=left_2;
        length[i]=length_2;
        step[i]=step_2;
        precision[i]=precision_2;
    }
    for (int i=8; i<10; ++i) {
        left[i]=left_3;
        length[i]=length_3;
        step[i]=step_3;
        precision[i]=precision_3;
    }

    int par;
    cin >> par;
    if (par<1 || par>10) return 1;
    --par;
    double arr[count];
    fSRand[par](time(nullptr));
    for (int i=0; i<count; ++i) arr[i]=fRand[par]();
    gist(arr, count, left[par], step[par], length[par], precision[par], ansPrecision);
}
