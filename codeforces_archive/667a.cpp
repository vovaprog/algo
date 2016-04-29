#include <bits/stdc++.h>

using namespace std;

typedef long long int int64;

const double PI = 3.141592653589793;

int main()
{
    int dInt,hInt,drinkInt,rainH;
    
    cin >> dInt >> hInt >> drinkInt >> rainH;
    
    double d = dInt;
    double h = hInt;
    double vDrink = drinkInt;    
    
    double r = d / 2.0;
    
    double s = PI * (r * r);
    
    double vRain = ((double)rainH) * s;
    
    if(vRain >= vDrink)
    {
        cout <<"NO\n";
        return 0;
    }
    
    double vol = h * s;
    
    double dif = vDrink - vRain;
    
    double result = vol / dif;
    
    cout << "YES\n" <<
        std::setprecision(std::numeric_limits< double >::max_digits10)
        << result <<endl;
    
    return 0;
}
