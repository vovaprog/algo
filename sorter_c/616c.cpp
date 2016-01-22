#include <stdio.h>

int nRows, nCols;

int** allocateMatrix(int nRows, int nCols)
{
    int **p=new int*[nRows];
    
    for(int i=0;i<nRows;i++)
    {
        p[i] = new int[nCols];
    }
    
    return p;
}

int calc(int **p, int pI, int pJ, int calcNumber)
{
    int result = 1;
    
    if(p[pI][pJ]!=0)
    {
        p[pI][pJ] = calcNumber;        
    }
    
    if(pI>0 && p[pI-1][pJ]!=0 && p[pI-1][pJ]!=calcNumber)
    {
        result += calc(p, pI-1, pJ, calcNumber);
    }

    if(pI<nRows-1 && p[pI+1][pJ]!=0 && p[pI+1][pJ]!=calcNumber)
    {
        result += calc(p, pI+1, pJ, calcNumber);
    }
    
    if(pJ>0 && p[pI][pJ-1]!=0 && p[pI][pJ-1]!=calcNumber)
    {
        result += calc(p, pI, pJ-1, calcNumber);
    }    

    if(pJ<nCols-1 && p[pI][pJ+1]!=0 && p[pI][pJ+1]!=calcNumber)
    {
        result += calc(p, pI, pJ+1, calcNumber);
    }    
    
    return result;
}

int calc2(int **p, int pI, int pJ, int calcNumber, bool firstCall)
{
    int result = 0;
        
    if(firstCall)
    {
        p[pI][pJ] = 1;
    }
    
    for(int j=pJ;j>=0;j--)
    {
        if(p[pI][j]!=0 && p[pI][j]!=calcNumber)
        {
            p[pI][j]=calcNumber;
            result++;
            if(pI>0 && p[pI-1][j]!=0 && p[pI-1][j]!=calcNumber)
            {
                result += calc2(p,pI-1,j,calcNumber, false);
            }
            if(pI<nRows-1 && p[pI+1][j]!=0 && p[pI+1][j]!=calcNumber)
            {
                result += calc2(p,pI+1,j,calcNumber, false);
            }
        }
        else break;            
    }
    for(int j=pJ+1;j<nCols;j++)
    {
        if(p[pI][j]!=0 && p[pI][j]!=calcNumber)
        {
            p[pI][j]=calcNumber;
            result++;
            if(pI>0 && p[pI-1][j]!=0 && p[pI-1][j]!=calcNumber)
            {
                result += calc2(p,pI-1,j,calcNumber, false);
            }
            if(pI<nRows-1 && p[pI+1][j]!=0 && p[pI+1][j]!=calcNumber)
            {
                result += calc2(p,pI+1,j,calcNumber, false);
            }
        }
        else break;
    }    
    
    if(firstCall)
    {
        p[pI][pJ] = 0;
    }    
    
    return result;
}

int countField(int **p, int pI, int pJ, int regionId)
{
    int result = 0;
            
    for(int j=pJ;j>=0;j--)
    {
        if(p[pI][j]!=0 && p[pI][j]!=regionId)
        {
            p[pI][j]=regionId;
            result++;
            if(pI>0 && p[pI-1][j]!=0 && p[pI-1][j]!=regionId)
            {
                result += countField(p,pI-1,j,regionId);
            }
            if(pI<nRows-1 && p[pI+1][j]!=0 && p[pI+1][j]!=regionId)
            {
                result += countField(p,pI+1,j,regionId);
            }
        }
        else break;            
    }
    for(int j=pJ+1;j<nCols;j++)
    {
        if(p[pI][j]!=0 && p[pI][j]!=regionId)
        {
            p[pI][j]=regionId;
            result++;
            if(pI>0 && p[pI-1][j]!=0 && p[pI-1][j]!=regionId)
            {
                result += countField(p,pI-1,j,regionId);
            }
            if(pI<nRows-1 && p[pI+1][j]!=0 && p[pI+1][j]!=regionId)
            {
                result += countField(p,pI+1,j,regionId);
            }
        }
        else break;
    }    
        
    return result;
}



int main_616c()
{    
    scanf("%d %d",&nRows, &nCols);
    int **p=allocateMatrix(nRows,nCols);
    int **p2=allocateMatrix(nRows,nCols);
    
    char rowData[1001];
    
    for(int i=0;i<nRows;i++)
    {
        scanf("%s",rowData);
        
        for(int j=0;j<nCols;j++)
        {
            if(rowData[j]=='*') {p[i][j] = 0;p2[i][j] = 0;}
            else {p[i][j] = 1;p2[i][j] = 1;}
        }
    }
    
    /*int calcNumber = 100;
    
    for(int i=0;i<nRows;i++)
    {             
        for(int j=0;j<nCols;j++)
        {
            if(p[i][j]==0)
            {
                printf("%d", calc2(p, i, j, calcNumber++, true) % 10);
                //printf("%d", calc(p, i, j, calcNumber++) % 10);
            }
            else
            {
                printf(".");
            }            
        }
        
        printf("\n");
    }*/
    
    int regionId = 2000000;
    
    for(int i=0;i<nRows;i++)
    {             
        for(int j=0;j<nCols;j++)
        {
            if(p[i][j]==1)
            {
                int result = countField(p, i, j, regionId);                
                countField(p2, i, j, result);
                                
                regionId+=1;
            }            
        }
    }
    
    for(int i=0;i<nRows;i++)
    {             
        for(int j=0;j<nCols;j++)
        {
            if(p[i][j]==0)
            {
                int output = 1;
                int regId0=0,regId1=0,regId2=0;
                
                if(i>0 && p[i-1][j]>0)
                {
                    regId0 = p[i-1][j];   
                    output+=p2[i-1][j];
                }
                if(i<nRows-1 && p[i+1][j]>0 && 
                    p[i+1][j]!=regId0)
                {
                    regId1 = p[i+1][j];
                    output+=p2[i+1][j];
                }
                if(j>0 && p[i][j-1]>0 &&
                    p[i][j-1]!=regId0 && p[i][j-1]!=regId1) 
                {
                    regId2 = p[i][j-1];
                    output+=p2[i][j-1];
                }
                if(j<nCols-1 && p[i][j+1]>0 &&
                    p[i][j+1]!=regId0 && p[i][j+1]!=regId1 && p[i][j+1]!=regId2)
                {
                    output+=p2[i][j+1];
                }
                printf("%d",output % 10);
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
    
    return 0;
}
