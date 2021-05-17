#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
 
struct Pas {
    int amount;
    int weigth;
    int num;
};


int main()
{
    const int pasNum=4;
    Pas pasLst[pasNum];
    
    const char *FName1="structs.bin";
    const char *FName2="pasnames.txt";
    
    Pas structsLst[pasNum];
    string pasnamesLst[pasNum];
    
    
    //створюємо файл з данними про пасажирів
    Pas Vasia;
    Pas Petia;
    Pas Katia;
    Pas Marina;
    
    Vasia={2,1,0};
    Petia={6,4,1};
    Katia={2,2,2};
    Marina={3,3,3};
 
    ofstream f1(FName1, ios::binary | ios::out);
        f1.write((char*)&Vasia, sizeof(Vasia));
        f1.write((char*)&Petia, sizeof(Petia));
        f1.write((char*)&Katia, sizeof(Katia));
        f1.write((char*)&Marina, sizeof(Marina));
    f1.close();
    
    //читаємо файл з іменами пасажирів
    string txt;
    ifstream f2(FName2, ios::in);
    for(int i=0;i<pasNum;i++){
        f2>>txt;
        pasnamesLst[i]=txt;
    }
    f2.close();
    
    Pas pas;
    int sum=0;
    //читаємо структури з файлу, щитаємо загальну кількість речей
    ifstream f3(FName1, ios::binary | ios::in);
        for(int i = 0;i<pasNum;i++){
            f3.read((char*)&pas, sizeof(Vasia));
            cout<< pasnamesLst[i] <<": " << pas.amount << ' ' << pas.weigth << ' ' << pas.num <<endl;
            structsLst[i]=pas;
            sum+=pas.amount;
        }
    f3.close();
    cout<<endl;
    
    //знаходемо пасажирів у яких більше ніж дві речі
    cout<<"пасажири у яких більше ніж 2 речі: "<<endl;
    for(int i = 0;i<pasNum;i++){
        if(structsLst[i].amount>2){
            cout<<pasnamesLst[i]<<endl;
        }
    }

    //знаходемо пасажирів у яких речей більше їх середньої кількості
    cout<<"пасажири у яких речей більше їх середньої кількості: "<<endl;
    for(int i = 0;i<pasNum;i++){
        if(structsLst[i].amount>(sum/pasNum)){
            cout<<pasnamesLst[i]<<endl;
        }
    }
    
    //знаходемо пасажирів у яких однакова кількість речей і різниця в вазі багажу не перевищує 1
    cout<<"пасажири у яких однакова кількість речей і різниця в вазі багажу не перевищує 1: "<<endl;
    for(int i = 0;i<pasNum;i++){
        for(int j = 0;j<pasNum;j++){
            if (j!=i && structsLst[i].amount == structsLst[j].amount && abs(structsLst[j].weigth-structsLst[i].weigth)<=1){
                cout<<pasnamesLst[i]<<endl;
            }
        }
    }
    return 0;
}

