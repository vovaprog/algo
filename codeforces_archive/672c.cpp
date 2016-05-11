#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);
#define debug3(arg) cout << #arg << " = " << arg << "\n";

typedef long long int int64;

struct Point{
    int x,y;
};

Point a, b, t;
Point bots[100010];

inline double dist(const Point &p1, const Point &p2)
{
    debug2("(%d, %d)   (%d, %d)", p1.x, p1.y, p2.x, p2.y);
    
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    
    return sqrt( x*x + y*y);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);

    int nBots;

    cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
    cin >> nBots;
    
    for(int i = 0; i < nBots; ++i)
    {
        cin >> bots[i].x >> bots[i].y;        
    }
    
   /* for(int i=0;i<nBots;++i)
    {
        double tDist = dist(bots[i], t);
        aDist = dist(a, bots[i]) + tDists[i];
        bDist = dist(b, bots[i]) + tDists[i];
        tDist *= 2.0;
                
        difA[i] = tDist - aDist;
        difB[i] = tDist - bDist;
    }
    
    double maxA;
    double maxB;
    double maxT;
    
    for(int i=0;i<nBots;++i)
    {
        if(difA[i] > maxA)
        {
            maxA=difA[i];
            maxAIndex = i;
        }
    }

    for(int i=0;i<nBots;++i)
    {
        if(difA[i] > maxA)
        {
            maxA=difA[i];
            maxAIndex = i;
        }
    }
    
    
    
    
        if(difB[i] > maxB)
        {
            maxB=difB[i];
            maxBIndex = i;
        }       
        if(ts[i]>maxT)
        {
            maxT = ts[i];
            maxTIndex = i;
        }
    */
    
    
    
    
    double minDistA = 0.0;
    int minDistAIndex = -1;
    
    for(int i=0;i<nBots;++i)
    {
        double distT = dist(bots[i],t);
        
        double distA = (distT + distT) - (dist(a, bots[i]) + distT);
        
        if(distA > minDistA)
        {
            minDistA = distA;
            minDistAIndex = i;
        }
    }

    bool useB = false;
    double minDistB = 0.0;
    int minDistBIndex = -1;
        
    if(nBots > 1)
    {                
        for(int i=0;i<nBots;++i)
        {
            double distT = dist(bots[i],t);
            
            double distB = (distT + distT) - (dist(b, bots[i]) + distT);
            
            if(distB > minDistB && i != minDistAIndex)
            {
                minDistB = distB;
                minDistBIndex = i;
            }
        }    
        
        if(minDistB > minDistA)
        {
            swap(a,b);
            swap(minDistA, minDistB);
            swap(minDistAIndex, minDistBIndex);        
        }
        
        double distT = dist(t, bots[minDistBIndex]);
        
        if(dist(b, bots[minDistBIndex]) + distT < distT + distT)
        {
            useB = true;
        }        
    }        
    
    
    cout <<"-------------\n";
    
    debug3(minDistAIndex);
    debug3(minDistBIndex);
    
    double result = 0.0;
    
    result += dist(a, bots[minDistAIndex]); //minDistA;
    result += dist(bots[minDistAIndex], t);
    
    if(useB)
    {        
        result += dist(b, bots[minDistBIndex]);
        result += dist(bots[minDistBIndex], t);
    }
    
    int i = 0;
    
    cout <<"-----------\n";
    
    for(int i=0;i<nBots;++i)
    {
        if(useB)
        {
            if(i!=minDistAIndex && i!=minDistBIndex)
            {
                result += dist(t, bots[i]) * 2;
            }
        }
        else
        {
            if(i!=minDistAIndex)
            {
                result += dist(t, bots[i]) * 2;
            }            
        }
    }    
    
    cout << std::setprecision(std::numeric_limits< double >::max_digits10) << result <<endl;

    return 0;
}
