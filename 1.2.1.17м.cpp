#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    double k;
    cout<<"k:";
    cin>>k;

    double x;
    cout<<"x:";
    cin>>x;

    double a_0 = 1;
    double j = 1;

    double S=0;
    for (int i=1;i<=k;i++) {
        S+=a_0;
        double a_k = a_0 * 1/(2*i) * pow(x,i);
        if(i>2) {
            a_k = a_k * pow(-1, i);
            a_k = a_k * j;
            j+=2;
        }
        a_0 = a_k;

    }
    cout<< S <<endl;
}