#include <iostream>
#include <cmath>
#include <map>
using namespace std;



int main() {
    int N;
    int counter=0;
    cout<<"N: ";
    cin>>N;
    int A[N]={};//массив
    map <int,int> A_count;//массив счёта
    
    //Заполнение масива
    for (int i = 0; i < N; i++) {
        cout << "[" << i << "]" << ": ";
        cin >> A[i];
    }

    //Заполняем массив счёта
    for (int i = 0,c = 0; i < N; ++i,++c){
        A_count.insert ( pair<int,int>(A[i],0) );
    }
    
    for (auto it = A_count.begin(); it != A_count.end(); ++it){ 
        for (int i = 0; i < N; ++i){
            if((*it).first==A[i]){
                (*it).second++;
            }
            
        }
    }
    
    //Ищем максимум в массиве счёта
    int max_el = 0;
    for (auto it = A_count.begin(); it != A_count.end(); ++it){
        if ((*it).second>max_el){
            max_el = (*it).second;
        }
    }
    //cout<<max_el;
    
    
    cout << "Mod list: ";
    //Выводим список на экран:
    for (auto it = A_count.begin(); it != A_count.end(); ++it){
        if ((*it).second == max_el){
            cout << (*it).first << ' ';
        }
    }
    return 0;
}