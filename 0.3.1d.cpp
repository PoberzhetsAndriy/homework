#include <iostream>
#include <cmath>
using namespace std;
double f(double x){
    double a = x*x*x;
    double b = a*x*x;
    return a+a*x*x+x;
}

int main()
{
    double x;
    cout << "Введите x: ";
    cin >> x;
    cout << "x^5+x^3+x = " << f(x) << endl;
    return 0;
}