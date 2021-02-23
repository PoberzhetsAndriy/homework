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


    double S=0;
    double a1 = 0;
    double a2 = 1;

    for (int k=1;k<=n;k++) {
        double ak=a1+a2*fact(k);
        a2=ak;
        a1=a2;
        S+=ak;
    }


    cout<<S<<endl;
}