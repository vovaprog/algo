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

inline int shiftRow(int row)
{
    int temp = a[row][nCols-1];
    for(int i=nCols-2;i>=0;--i)
    {
        a[row][i+1] = a[row][i];        
    }
    a[row][0] = temp;
}

inline int shiftCol(int col)
{
    int temp = a[nRows-1][col];
    for(int i=nRows-2;i>=0;--i)
    {
        a[i+1][col] = a[i][col];    
    }
    a[0][col] = temp;
}

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
        }        
    }
    
    for(int i=nRqs-1;i>=0;--i)
    {
        Request &rq = rqs[i];
        switch(rq.type){
        case SHIFT_ROW:
            shiftRow(rq.row);
            break;
        case SHIFT_COL:
            shiftCol(rq.col);
            break;
        default:
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
