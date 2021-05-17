#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream F("F.txt");
    int c=0;
    int a;
    while (F>>a)
    {
        if(a/2+a%2==a/2){
            c+=1;
        }
    }
    cout<<c;
    F.close();
    return 0;
}
