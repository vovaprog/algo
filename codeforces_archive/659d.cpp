#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

int direction(int x1, int y1, int x0, int y0)
{
    if(x1==x0)
    {
        if(y0>y1) return UP;
        else return DOWN;
    }
    else
    {
        if(x0>x1) return RIGHT;
        else return LEFT;
    }
}

bool isLeftTurn(int x2,int y2, int x1, int y1, int x0, int y0)
{
    int directionOld = direction(x2,y2,x1,y1);
    int directionNew = direction(x1,y1,x0,y0);
    
    if(directionOld==UP && directionNew==LEFT ||
        directionOld == RIGHT && directionNew==UP ||
        directionOld == LEFT && directionNew==DOWN ||
        directionOld == DOWN && directionNew==RIGHT)
    {
        return true;
    }    
    return false;
}

int main()
{
    int n;
    
    scanf("%d",&n);
    
    int result=0;
    
    int x0=0,y0=0,x1=0,y1=0,x2=0,y2=0;
    
    for(int i = 0; i < n+1; ++i)
    {
        scanf("%d %d",&x0, &y0);
        
        if(i>1)
        {
            if(isLeftTurn(x2,y2,x1,y1,x0,y0))
            {
                ++result;
            }            
        }
        
        x2=x1;
        y2=y1;
        x1=x0;
        y1=y0;        
    }
    
    printf("%d\n",result);
    
    
    return 0;
}

