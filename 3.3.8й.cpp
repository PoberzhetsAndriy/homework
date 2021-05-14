#include <iostream>
using namespace std;

int main() 
{ 
    int M ;
    int N ; 
    int i, j;
    int k;

    int** matrix;
    int** n_matrix;


    cout << "M: ";
    cin >> M;
    cout << "N: ";
    cin >> N;
    cout<< endl;

    matrix = new int*[M]; 
    n_matrix = new int*[M]; 

    for (i = 0; i < M; i++){
        matrix[i] = new int[N];
        n_matrix[i] = new int[N-1];
    }

    for (i = 0; i < M; i++)
    { 
        for (j = 0; j < N; j++) 
        { 
            cout <<"[" << i << "][" << j << "] : "; 
            cin >> matrix[i][j]; 
        }
    }


    cout << endl;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++) 
        { 
            cout<< matrix[i][j]; 
            cout<< " " ;

        } 
        cout<< endl;
    }


    cout << "k: ";
    cin>>k;

    //Створюємо нову матрицю яка не містить k-го рядка
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++) 
        { 
            if (k>i){
                n_matrix[i][j] = matrix[i][j]; 
            }
            if(k<i){
                n_matrix[i-1][j] = matrix[i][j];
            }
        } 

        cout<< endl;
    }

    //Записуємо нову матрицю в matrix
    delete[] matrix;
    matrix = new int*[M]; 
    for (i = 0; i < M; i++){
        matrix[i] = new int[N-1];
    }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++) 
        { 
           matrix[i][j] = n_matrix[i][j];
        } 
    }

    //Виводимо змінену матрицю
    for (i = 0; i < M-1; i++)
    {
        for (j = 0; j < N; j++) 
        { 
            cout<< matrix[i][j]<< " " ;
        } 
        cout<< endl;
    }
}
