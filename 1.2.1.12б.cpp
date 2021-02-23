#include <iostream>
#include <cmath>
using namespace std;

long double fact(int N)
{
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}

int main()
{
    int n;
    cin>>n;
    double u;
    cin>>u;
    double v;
    cin>>v;

    double S=0;
    double a = u;
    double b = v;

    for (int k=1;k<=n;k++) {
        a=2*b+a;
        b=2*pow(a,2)+b;
        S+=a*b/fact(k+1);
    }

    cout<<S<<endl;
}