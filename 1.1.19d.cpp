#include <iostream>
#include <cmath>
using namespace std;

double f(double tl,double tr,double al,double ar,double x) {
    if (x <= tl) {
        double c = tl + al*(x - tl);
        return c;
    }else if(tl < x && x < tr){
        double c = 0;
        return c;
    }else{
        double c = tr + ar*(x - tr);
        return c;
    }

}

double g(double tl,double tr,double al,double ar,double x) {
    if (x <= tl) {
        double c = al;
        return c;
    }else if(tl < x && x < tr){
        double c = 0;
        return c;
    }else{
        double c = ar;
        return c;
    }

}
int main()
{
    double x,tl,tr,al,ar;

    cout << "введите tl:" ;
    cin >> tl;
    cout << "введите tr:" ;
    cin >> tr;
    cout << "введите al:" ;
    cin >> al;
    cout << "введите ar:" ;
    cin >> ar;
    cout << "введите x:" ;
    cin >> x;
    cout << "sReLu(x,tl,tr,al,ar): " << f(tl,tr,al,ar,x) << endl;
    cout << "(sReLu(x,tl,tr,al,ar))': " << g(tl,tr,al,ar,x) << endl;
    return 0;
}