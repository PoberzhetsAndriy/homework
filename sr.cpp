#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int L;
    int l;
    cout <<"L: ";
    cin >> L;
    vector<int> arrey1;
    
    
    for(int i = 0; i < L; i++){
        cin >> l;
        arrey1.push_back(l);
    }
    
    for(int i = 0; i < arrey1.size(); i++){
        cout << arrey1[i] <<" ";
    }
    cout<<endl<<endl;
    
    vector<int> arrey2;
    
    for(int i = 0; i < arrey1.size(); i++){
        if (i<L/2 && arrey1[i] % 2 != 0)
        {
            arrey2.push_back(arrey1[i]);
            arrey2.push_back(-1);
        }
        else if (i>=L/2 && arrey1[i] % 2 == 0)
        {
            arrey2.push_back(-2);
            arrey2.push_back(arrey1[i]);
        }
        else
        {
            arrey2.push_back(arrey1[i]);
        }
    }
    
    for(int i = 0; i < arrey2.size(); i++){
        cout << arrey2[i] <<" ";
    }
    return 0;
}
