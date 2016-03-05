#include <bits/stdc++.h>

using namespace std;

#define INF 2000000000

#define debug(args...) //printf(args);
#define debug2(fmt,args...) //printf(fmt,args);printf("   (%s)\n",#args);

int a[100000];
//int d[100000];
//set<int> gt[100000];
//set<int> lt[100000];
set<int> cts[100001];

int main()
{
    int n;
    
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("0");
        return 0;
    }
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    vector<int> d(n+1);
    d[0] = -INF;
    for (int i=1; i<=n; ++i)
        d[i] = INF;
     
    for (int i=0; i<n; i++) {
        int j = int (upper_bound (d.begin(), d.end(), a[i]) - d.begin());
        //if (d[j-1] < a[i] && a[i] < d[j])
            //d[j] = a[i];
        debug2("%d %d",d[j-1],a[i]);    
        if((j==1 || cts[j-1].count(a[i]-1)!=0) && a[i]<d[j])
        {
            debug2("!! %d",j, d[j-1]);
            d[j]=a[i];
            cts[j].insert(a[i]);
        }
    }      
    
    int count = n;
    
    for(int i=n;i>=1;--i)
    {
        if(d[i]!=INF && d[i]!=-INF)
        {
            debug2("d[%d]=%d",i,d[i]);
            
            count -= i;
            break;             
        }
    }
    
    printf("%d",count);
    
    return 0;
}
