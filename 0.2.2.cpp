#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a,b;
    cout << "Введите катет a: ";
    cin >> a;
    cout << "Введите катет b: ";
    cin >> b;
    double c = sqrt(a*a+b*b);
    cout << "гіпотенуза с = " << c << endl;
    return 0;
}