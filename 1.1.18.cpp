#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    double x,y,z,h,r;
    cout << "введіть координати точки:" <<endl;
    cout << "x:" ;
    cin >> x;
    cout << "y:" ;
    cin >> y;
    cout << "z" ;
    cin >> z;

    cout << "введть параметри циліндра:" <<endl;
    cout << "r:" ;
    cin >> r;
    cout << "h:" ;
    cin >> h;

    double v = sqrt(pow(x,2) + pow(y,2));//відстань до  осі
    if (v < r && z >= 0 && z <= h ) {
        cout << "точка належить циліндру";

    } else {
        cout << "точка не належить циліндру";
    }
    return 0;
}