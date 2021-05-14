#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

string txt="";
string str;

int a;

struct Date {
    int day;
    int month;
    int year;
};
int main(){
    //зчитуємо файл в масив
    ifstream f("f.txt",ios::in);
    f>>str;
    for(char ch : str)
    {
        if(isdigit(ch)){
            txt+=ch;
        }
        else{
            txt+=' ';
        }
    }
    f.close();
    
    stringstream ss;
    ss<<txt;
    int Lst[txt.length()/2];
    int i=0;
    int c=0;
    while(ss>>a){
        Lst[i]=a;
        i++;
        c++;
    }
    
    //утворюємо масив структур
    Date dates[c];
    int k=0;
    for(int i=0;i<c;i+=3){
        dates[k]={Lst[i],Lst[i+1],Lst[i+2]};
        k+=1;
    }
    //знаходимо максимум
    Date maxdate=dates[0];
    for(int i=1;i<k;i++){
        if(dates[i].year>maxdate.year){
            maxdate=dates[i];
        }
        else if(dates[i].year==maxdate.year){
            if(dates[i].month>maxdate.month){
                maxdate=dates[i];
            }
            else if(dates[i].month==maxdate.month){
                if(dates[i].day>maxdate.day){
                    maxdate=dates[i];
                }
            }
        }
    }
    
    
    //знаходимо мінімум
    Date mindate=dates[0];
    for(int i=1;i<k;i++){
        if(dates[i].year<maxdate.year){
            mindate=dates[i];
        }
        else if(dates[i].year==maxdate.year){
            if(dates[i].month<maxdate.month){
                maxdate=dates[i];
            }
            else if(dates[i].month==maxdate.month){
                if(dates[i].day<maxdate.day){
                    maxdate=dates[i];
                }
            }
        }
    }
    
    //зводимо до стандартного вигляду
    string maxd=to_string(maxdate.day);
    string maxm=to_string(maxdate.month);
    string mind=to_string(mindate.day);
    string minm=to_string(mindate.month);
    if(maxd.length()<2){
        maxd='0'+maxd;
    }
    if(maxm.length()<2){
        maxm='0'+maxm;
    }
    if(mind.length()<2){
        mind='0'+mind;
    }
    if(minm.length()<2){
        minm='0'+minm;
    }
    cout<<"найсвіжіша дата: "<<'('<<maxd<<'/'<<maxm<<'/'<<maxdate.year<<"),"<<endl;
    cout<<"найстарша дата: "<<'('<<mind<<'/'<<minm<<'/'<<mindate.year<<"),"<<endl;
    
    ofstream f1("f1.txt",ios::out);
    f1<<'('<<maxd<<'/'<<maxm<<'/'<<maxdate.year<<"),"<<'('<<mind<<'/'<<minm<<'/'<<mindate.year<<"),";
    
    return 0;
}