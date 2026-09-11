using namespace std;

#include <iostream>
#include <cmath>

int main() 
{
    int n,x,y,xM,yM,xm,ym,perimetro;
    cin >> n;
    xm = ym = pow(10,8)+1;
    xM = yM = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (x > xM){
            xM = x;
        }
        if (y > yM){
            yM = y;
        }
        if (x < xm){
            xm = x;
        }
        if (y < ym){
            ym = y;
        }
    }
    perimetro=2*(abs(xM-xm)+2+abs(yM-ym)+2);
    cout << perimetro;
    return 0;
}