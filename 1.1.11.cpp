#include <iostream>
#include <cmath>
using namespace std;


int main()
{   
    double x1,x2,y1,y2,r1,r2;
    cout << "введіть координати першого кола:" <<endl;
    cout << "x1:" ;
    cin >> x1;
    cout << "y1:" ;
    cin >> y1;
    cout << "введіть радіус першого кола:" ;
    cin >> r1;
    
    cout << "введть координати другого кола:" <<endl;
    cout << "x2:" ;
    cin >> x2;
    cout << "y2:" ;
    cin >> y2;
    cout << "введіть радіус другого кола:" ;
    cin >> r2;
    
    double v = sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));//відстань між центрами кіл
    if (v == 0 && r1 == r2) {
        cout << "кола перетинаються";
    } else if (r1 + r2 >= v && r1 + v >= r2 && r2 + v >= r1) {
        cout << "кола перетинаються";
    } else {
        cout << "кола не перетинаються";
    }
    return 0;
}
