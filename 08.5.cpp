#include <iostream>
#include <cmath>
using namespace std;

class Circle
{
    public:
        double m_r;
        double m_x;
        double m_y;
     
        int d()
        {
            return m_r*2;
        }
        
        double S()
        {
            return m_r*m_r*3.14;
        }
        double P()
        {
            return m_r*6.28;
        }
        double cros(double r, double x, double y)
        {  
            double l=sqrt((m_x-x)*(m_x-x)-(m_y-y)*(m_y-y));
            if (l < m_r+r && m_r + l >= r && r + l >= m_r){
                return 2;
            }
            else if (l = m_r+r && m_r + l >= r && r + l >= m_r){
                return 1;
            }
            else{
                return 0;
            }
        }
        
};


int main()
{
    Circle C1{3,1,1};
    Circle C2{2,3,1};
    cout<<C1.cros(C2.m_r,C2.m_x,C2.m_y)<<endl;
    return 0;
}
