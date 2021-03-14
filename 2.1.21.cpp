#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int n,m;
    cout<<"n: ";
    cin>>n;
    cout<<"m: ";
    cin>>m;
    int A[n][m]={};
    int A_max=0;
    cout<<"заполнение матрицы: "<<endl;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int a;
            cout<<"["<<i<<"]"<<"["<<j<<"]: ";
            cin>>A[i][j];
        }
    }
    
    //вывод матрицы и максимум матрицы
    cout<<"вывод матрицы: ";
    for(int i=0;i<n;i++) {
        cout<<endl;
        for(int j=0;j<m;j++) {
            cout<<A[i][j]<<" ";
            
            if(A[i][j]>A_max){
                A_max=A[i][j];
            }
        }
    }
    cout<<endl;
    cout<<endl;
    
    int k;
    for(int i=0;i<n;i++) {
        int max=0;
        int min=A_max;
        //максимум в ряду
        for(int j=0;j<m;j++) {
            if(A[i][j]>max){
                max=A[i][j];
                k=j;
            }
        }
        
        //находим минимум в столбце максимума
        int j=k;
        for(int i=0;i<n;i++) {
            if(A[i][j]<min){
            min=A[i][j];
            }
        }
        if(min == max){
            cout<<min<<" ";
        }
    }
    return 0;    
}