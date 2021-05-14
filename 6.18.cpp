#include <iostream>
#include<string>
#include <sstream>
using namespace std;


int main()
{
    stringstream ss;
    string line="She ate an Apple. This is a Dog";
    ss<<line;
    
    int i = 0;
    int c = 0;

    string txt="";
    string word="";
    string prev="";
    while(ss>>word){
        if(prev == "a" || prev == "the" || prev == "an"){
            word[0]=tolower(word[0]);
        }
        txt+=word+' ';
        prev=word;
        i++;
    }
    cout << txt;
    return 0;
}
