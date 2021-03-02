
#include <iostream>
#include <cmath>
using namespace std;

double to2(int a) {
    int counter=0;
    long long int n = 0;
    int k,m = 0;
    while(a) {
        k = a % 2;

        a = a / 2;
        n += k * pow(10, m);
        m++;

    }
    return n;

}

double to10(int a){
    int sum=0;
    int i=0;
    while(a>0){
        int k=a%10;
        a = (a-a%10)/10;
        if (k == 1){
            sum+=pow(2,i);
        }
        i++;
    }
    return sum;
}
