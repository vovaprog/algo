#include <bits/stdc++.h>

using namespace std;

typedef long long int int64;

double v, tPhrase;

struct Point{
    int x;
    double t;
    int index;
    bool operator<(const Point &p) const
    {
        return v * t + x < v * p.t + p.x;
    }
};

vector<Point> ps;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;

    cin >> v >> tPhrase;

    cin >> n;
    
    ps.reserve(n);
    
    for(int i = 0; i < n; ++i)
    {
        Point p;
        p.index = i + 1;
        cin >> p.x >> p.t;
        
        ps.push_back(p);
    }

    auto it = min_element(ps.begin(),ps.end());
    
    Point p = *it;
    
    cout 
        << std::setprecision(std::numeric_limits<double>::max_digits10)
        << (double)((tPhrase + p.t) * v + p.x) << " " << p.index<<endl;
    
    return 0;
}
