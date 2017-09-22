#include "random.h"
#include <algorithm>
using namespace std;

/// rand_1
int generate_1() {
    const long long a=3*809+1,c=17*19*23;
    //m=(3^4)*809
    static long long curValue;
    curValue=(a*curValue+c)%RAND_1MAX;
    return curValue;
}

double rand_1() {
    return (double)generate_1()/RAND_1MAX;
}

void srand_1(unsigned int n) {
    n%=RAND_1MAX;
    do { }
    while ((unsigned)generate_1()!=n);
}

/// rand_2

int generate_2() {
    const long long d=3*3*809,a=3*809+1,c=17*19*23;
    //m=(3^4)*809
    static long long curValue;
    curValue=(d*curValue*curValue+a*curValue+c)%RAND_2MAX;
    return curValue;
}

double rand_2() {
    return (double) generate_2()/RAND_2MAX;
}

void srand_2(unsigned int n) {
    n%=RAND_2MAX;
    do { }
    while ((unsigned)generate_2()!=n);
}

/// rand_3
int cV=RAND_3MAX/2;
int pV=RAND_3MAX/3;

int generate_3() {
    int k=cV;
    cV=(cV+pV)%RAND_3MAX;
    pV=k;
    return cV;
}

double rand_3() {
    return (double) generate_3()/RAND_3MAX;
}

void srand_3(unsigned int n) {
    cV=n%RAND_3MAX;
    pV=n%RAND_3MAX;
}

/// rand_4

const long long a=4*2017+1,c=2*17*19*23;
int phi=(1<<15);
long long curValue_4=1;

long long invert(long long k) {
    int pow=phi-1;
    long long rez=1;
    long long pow_k=k;
    while (pow>0) {
        if (pow%2==1) rez=(rez*pow_k)%RAND_4MAX;
        pow_k=(pow_k*pow_k)%RAND_4MAX;
        pow/=2;
    }
    return rez;
}

int generate_4() {
    curValue_4=(a*invert(curValue_4)+c)%RAND_4MAX;
    return curValue_4;
}

double rand_4() {
    return (double) generate_4()/RAND_4MAX;
}

void srand_4(unsigned int n) {
    n%=RAND_4MAX;
    if (n%2==1) curValue_4=n;
}

/// rand_5

double rand_5() {
    double x=rand_2();
    double y=rand_4();
    x-=y;
    while (x<0) ++x;
    return x;
}

void srand_5(unsigned int n) {
    srand_2(n);
}

/// rand_6

const int num=12;

double rand_6() {
    double suma=0;
    for (int i=0; i<num; ++i) suma+= rand_3();
    return suma-6;
}

void srand_6(unsigned int n) {
    srand_3(n);
}

/// rand_7

double rand_7() {
    static int status=0;
    static double last;
    if (status==1) {
        status=0;
        return last;
    }
    double s,v1,v2;
    do {
        double u1=rand_2(),u2=rand_2();
        v1=2*u1-1; v2=2*u2-1;
        s=v1*v1+v2*v2;
    }
    while (s>1);
    double r=sqrt(((-2)*log(s))/s);
    double x1=v1*r,x2=v2*r;
    status=1;
    last=x2;
    return x1;
}

void srand_7(unsigned int n) {
    srand_2(n);
}

/// rand_8

double rand_8() {
    double x,u,v;
    do {
        do {
            u=rand_2();
        }
        while (u==0);
        v=rand_4();
        x=sqrt(8/M_E)*(v-0.5)/u;
    }
    while (x*x>(-4)*log(u));
    return x;
}

void srand_8(unsigned int n) {
    srand_2(n);
}

/// rand_9

const double u=5;

double rand_9() {
    double v;
    do {
        v=rand_2();
    }
    while (v==0);
    return -u*log(v);
}

void srand_9(unsigned int n) {
    srand_2(n);
}

/// rand_10

const double q = 15; //q>1

double rand_10() {
    double u,v,x,y;
    do {
        do {
            u=rand_2();
            y=tan(M_PI*u);
            x=sqrt(2*q-1)*y+q-1;
        }
        while (x<=0);
        v=rand_4();
    }
    while (v>(1+y*y)*pow(M_E, (q-1)*log(x/(q-1))-sqrt(2*q-1)*y));
    return x;
}

void srand_10(unsigned int n) {
    srand_2(n);
}
