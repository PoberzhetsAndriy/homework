#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int res,i,c,n,k;
    i=0;
    res=0;
    cin>>n;
    while(n>0){
        k=n%10;
        n = (n-n%10)/10;
        c++;
        cout<<k<<endl;
        if (k != 5 && k != 1){
            res+=k*pow(10,i);
            i++;
            cout<<res<<endl;
        }
    }
    cout<<res;

}