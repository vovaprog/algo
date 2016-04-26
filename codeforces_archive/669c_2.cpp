#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

struct Request
{
    int type;
    int row,col,x;
};

Request rqs[10010];

int a[110][110]={0};
int nRows, nCols, nRqs;

const int SHIFT_ROW = 1;
const int SHIFT_COL = 2;

int main()
{
    scanf("%d %d %d",&nRows, &nCols, &nRqs);
    
    for(int i = 0; i < nRqs; ++i)
    {
        Request &rq = rqs[i];
        scanf("%d",&rq.type);
        
        switch(rq.type){
        case SHIFT_ROW:
            scanf("%d",&rq.row);
            --rq.row;
            break;
        case SHIFT_COL:
            scanf("%d",&rq.col);
            --rq.col;
            break;
        default:
            scanf("%d%d%d",&rq.row,&rq.col,&rq.x);
            --rq.row;
            --rq.col;
            
            for(int j = i-1;j>=0;--j)
            {
                if(rqs[j].type==SHIFT_ROW && rqs[j].row==rq.row)
                {
                    ++rq.col;
                    if(rq.col>=nCols) rq.col=0;
                }
                else if(rqs[j].type==SHIFT_COL && rqs[j].col==rq.col)
                {
                    ++rq.row;
                    if(rq.row>=nRows) rq.row = 0;
                }
            }
            a[rq.row][rq.col] = rq.x;
        }        
    }
    
    for(int i=0;i<nRows;++i)
    {
        for(int j=0;j<nCols;++j)
        {
            printf("%d ",a[i][j]);       
        }
        printf("\n");
    }    
    
    return 0;
}
