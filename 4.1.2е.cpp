#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int isfib(int num){
    bool fib = false;
    int f1,f2,fn;
    f1=0;
    f2=1;
    fn=0;
    while(fn<=num){
        fn=f1+f2;
        f1=f2;
        f2=fn;
        if(fn==num){
            fib = true;
        }
    }
    return fib;
}

int main()
{
    ifstream F("F.txt");
    string txt="";
    string line;
    int a;
    while (F>>a)
    {
        cout<<a<<endl;
        if(isfib(a)==1){
            txt+=to_string(a)+" ";
        }
    }
    cout<<txt;

    F.close();     // закрываем файл
    ofstream G("G.txt");
    G<<txt;
	G.close();
	return 0;
}
