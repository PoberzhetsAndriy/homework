#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    double k=3;
    double res;
    double n=2;
    for (int i=2;i<=n;i++) {
        res = sqrt(k+sqrt(i*3));
        k=res;
    }
    cout<< res;
}