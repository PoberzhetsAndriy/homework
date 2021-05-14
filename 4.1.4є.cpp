#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;
 
struct PolM {
    int coef;
    int deg;
    int num;
};


int main()
{
    int polMNum=0;
    const int polsMNum=4;
    PolM polsMLst[polsMNum]={};
    
    PolM pm; 
    
    int n,k;
    
    cout<<"Введіть номер коефіцієнту: ";
    cin>>n;
    cout<<"Введіть новий коефіцієнт: ";
    cin>>k;
    cout<<endl;
    
    const char *FName="f.bin";
    
    //створюємо файл
    PolM a1;
    PolM a2;
    PolM b1;
    PolM b2;
    PolM b3;
    
    a1={1,1,1};
    a2={1,1,1};
    b1={1,1,2};
    b2={1,1,2};
 
    ofstream f1(FName, ios::binary | ios::out);
        f1.write((char*)&a1, sizeof(a1));
        f1.write((char*)&a2, sizeof(a2));
        f1.write((char*)&b1, sizeof(b1));
        f1.write((char*)&b2, sizeof(b2));
    f1.close();
 
    
    //читаємо структури з файлу з заміною коефіцієнту
    cout<<"стартовий файл:"<<endl;
    ifstream f2(FName, ios::binary | ios::in);
        for(int i = 0;i<polsMNum;i++){
            f2.read((char*)&pm, sizeof(a1));
            cout << pm.coef << ' ' << pm.deg << ' ' << pm.num << '\n';
            if (i==n){
                pm.coef=k;
            }
            polsMLst[i]=pm;
        }
    f2.close();
    cout<<endl;
    
    
    //перезаписуємо файл і виводимо його
    cout<<"перезаписаний файл:"<<endl;
    ofstream f3(FName, ios::binary | ios::out);
        for(int i = 0;i<polsMNum;i++){
            f3.write((char*)&polsMLst[i], sizeof(polsMLst[i]));
            cout << polsMLst[i].coef << ' ' << polsMLst[i].deg << ' ' << polsMLst[i].num << '\n';
        }
    f3.close(); 
    
    return 0;
}

