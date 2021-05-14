/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Monomial
{
    int c,i;
    char x;
};

int main()
{
    int n;
    cout<<"кількість одночленів: ";
    cin>>n;
    
    //задаємо масив одночленів
    Monomial monomials[n];
    cout<<"введіть коефіцієнти многочленів:"<<endl;
    for(int k=0;k<n;k++){
        cout<<"c"<<k<<" ";
        cin>>monomials[k].c;
        cout<<"i"<<k<<" ";
        cin>>monomials[k].i;
        cout<<"x"<<k<<" ";
        cin>>monomials[k].x;
    }
    
    //виводимо многочлен
    cout<<"многочлен: ";
    for(int k=0;k<n;k++){
        cout<<monomials[k].c<<monomials[k].x<<"^"<<monomials[k].i;
        if(k+1 != n){
            cout<<" + ";
        }
    }
    return 0;
}
