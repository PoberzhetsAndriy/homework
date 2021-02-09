#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
  double c = (exp(x)-exp(-x))/(exp(x)+exp(-x));
  return c;
}

double g(double x)
{
   double c = (-exp(x)+exp(-x))*(+exp(x)-exp(-x))/pow((+exp(x)+exp(-x)),2);
   return c;
}
int main()
{   
    double x;
    cout << "введите x:" ;
    cin >> x;
    cout << "th(x): " << f(x) << endl;
    cout << "(th(x))': " << g(x) << endl;
    return 0;
}
