#include <iostream>
#include <cmath>
using namespace std;

double f(double x,int n) {
    double sum = 0;
    for (int i=1;i<=n;i++) {
        cout<<pow(x,i*i)<<endl;
        sum += pow(x,i*i);
    }
    return sum;
}



int main()
{
    cout<< f(2,2)<<endl;
}