#include <bits/stdc++.h>

using namespace std;

typedef long long int int64;

char s[1100][50]={0};
int rs[1100]={0};
bool visited[1100]={0};
int len;

int compare(int i, int q)
{
    int errCount = 0;
    
    for(int j=0;j<len;++j)
    {
        if(s[i][j]!=s[q][j])
        {
            ++errCount;    
        }
        if(errCount>1)
        {
            return 2;    
        }
    }
    return errCount;
}

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
    {
        scanf("%s", s[i]);
    }

    len = strlen(s[0]);
    
    bool allOnes = true;
    
    for(int i=1;i<n;++i)
    {
        int result = compare(0, i);
        
        rs[i] = result;
        
        if(result>1)
        {
            allOnes = false;    
        }
    }
    
    if(allOnes)
    {
        printf("%s\n",s[0]);
        return 0;
    }
       
    visited[0] = true;
    
    for(int i=1;i<n;++i)
    {
        if(rs[i]==1)
        {
            allOnes = true;
            
            for(int q = 1; q<n; ++q)
            {
                if(q!=i && !visited[q])
                {
                    int result = compare(i, q);
                    
                    if(rs[q]==1) rs[q] = result;
                    
                    if(result>1)
                    {
                        allOnes = false;    
                    }
                }
            }
            
            if(allOnes)
            {
                printf("%s\n",s[i]);
                return 0;
            }
            
            visited[i] = true;
        }
    }    
    
    return 0;
}
