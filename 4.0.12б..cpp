#include <iostream>
#include <string>

using namespace std;

struct Product
{
    int grn,kop;
    string name;

};

int main(){
    int N;
    cout<<"кількість товарів: ";
    cin>>N;
    
    //задаємо масив товарів
    Product products[N];
    cout<<"введіть інформацію про товари"<<endl<<endl;
    for(int k=0;k<N;k++){
        cout<<"назва товару: ";
        cin>>products[k].name;
        cout<<"гривні: ";
        cin>>products[k].grn;
        cout<<"копійки: ";
        cin>>products[k].kop;
        cout<<endl;
    }
    
    if(N==1){
        cout<<"найдорожчий товар: "<<products[0].name;
        return 0;
    }
    
    
    
    //порівнюємо товари
    int maxgrn=products[0].grn;
    int maxkop=products[0].kop;
    for(int k=0;k<N;k++){
       if(products[k].grn>maxgrn){
           maxgrn=products[k].grn;
           maxkop=products[k].kop;
       }
       else if(products[k].grn == maxgrn){
           if(products[k].kop>maxkop){
           maxkop=products[k].kop;
           }
       }
    }
    
    
    //виводимо найдорожчий товар(декілька якщо ціна ідентична)
    cout<<endl<<"найдорожчі товари: ";
    for(int k=0;k<N;k++){
       if (products[k].grn == maxgrn & products[k].kop == maxkop){
           cout<<products[k].name<<" ";
       }
    }
    return 0;
        
}