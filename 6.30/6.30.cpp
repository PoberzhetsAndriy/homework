#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
int fLen(string fname){ //функця підрахунку кількості рядків в файлі
    ifstream N(fname);
    int c = 0;
    for (string line; getline(N, line);) {
        c++;
    }
    return c;
}

int main()
{
    int N1len = fLen("Name1.txt");
    int N2len = fLen("Name2.txt");
    string N1mass[N1len];
    string N2mass[N2len];
    
    //заполняем масив N1mass
	ifstream N1("Name1.txt");
	int i1=0;
    for (string line; getline(N1, line);) {
        N1mass[i1]=line;
        i1++;
        cout<<line<<endl;
    }
    cout<<endl;
    
    //заполняем масив N2mass
    ifstream N2("Name2.txt");
    int i2=0;
    for (string line; getline(N2, line);) {
        N2mass[i2]=line;
        i2++;
        cout<<line<<endl;
    }
    cout<<endl;
    
    //прибавляем к строкам первого масива строки второго
    int j = 0;
    for(int i=0;i<N2len;i++){
        if (j >=N1len){
            j=0;
        }
        N1mass[j]+=N2mass[i];
        j++;
    }
    
    //записываем новый файл
    ofstream N("Name.txt");
    for(int i=0;i<N1len;i++){
        N<<N1mass[i]<<endl;
        cout<<N1mass[i]<<endl;
    }
    N.close();
    return 0;
}