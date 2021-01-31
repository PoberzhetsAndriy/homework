#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(0, "");
    double a;
    cout << "Введите число a: ";
    cin >> a;
    double c = log10(a);
    cout << "lg(a) = " << c << endl;
    return 0;
}
