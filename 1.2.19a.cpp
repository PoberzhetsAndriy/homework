#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    double x;
    cout<<'x'<<endl;
    cin>>x;
    double k;
    cout<<'k'<<endl;
    cin>>k;
    double r=x/k;
    for (int i=1;i<k;i++) {
        r = r*x;
    }
    cout<<"x^k/k: ";
    cout<<r;
}