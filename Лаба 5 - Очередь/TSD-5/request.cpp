#include "request.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

inline double Rand1();
inline int nrand(int n);
double Random();

Request::Request() {
    this->Generate();
}

double Request::AddTime() {
    return this->rAddTime;
}

double Request::ProcessingTime() {
    return this->rProcessingTime;
}

int Request::incProcessingsCount() {
    return ++(this->rProcessingsCount);
}

inline void Request::Generate() {
    this->rAddTime = Rand1() * (MaxAddTime - MinAddTime) + MinAddTime;
    this->rProcessingTime = Rand1()*
            (MaxProcessingTime - MinProcessingTime) + MinProcessingTime;
    this->rProcessingsCount = 0;
}

inline double Rand1() {
    double result = (double) rand() / (RAND_MAX + 1);
    return result;
}

inline int nrand(int n)
{
    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);

    return r;
}

double Random()
{
    static const unsigned int A = 1686629717;
    static const unsigned int C = 907633385;
    static unsigned int n = GetTickCount();

    return ((double)(n = A*n+C))/0xFFFFFFFF;
}
