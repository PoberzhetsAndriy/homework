#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long double a;
    cout << "Введите число a: ";
    cin >> a;
    double c = a*a*a*a*a*a*a*a;
    cout.setf(ios::fixed);
    cout.precision(4); 
    cout << "a^8 = " << c << endl;
    return 0;
}