/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int strlen(const char* str)
{
    int size = 0;
    while(*str++) ++size;
    return size;
}
int main()
{
    char A[]  = "atgfdhgfg";
    char S = 'f';
    char C = '*';
    int n = strlen(A);
    bool p = false;
    for(int i = 0;i<n;i++){
        char a=A[i];
        
        if(a==S){
            p=true;
        }
        if(p==true){
            a=C;
        }
        A[i]=a;
    }
    cout<<A;
    return 0;
}
