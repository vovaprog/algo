#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

struct User{
    int score;
    char *name;
};

multimap<int,User,greater<int>> regUsers[10010];

int main()
{
    int nUsers, nRegions;
    
    scanf("%d %d",&nUsers, &nRegions);
    
    for(int i = 0; i < nUsers; ++i)
    {
        int region;        
        User u;
        u.name = new char[16];
        
        scanf("%s %d %d", u.name, &region, &u.score);
        --region;
        
        regUsers[region].insert(make_pair(u.score,u));
    }
    
    for(int i=0;i<nRegions;++i)
    {
        multimap<int,User,greater<int>> &m = regUsers[i];
        
        auto it = m.begin();
        
        User &u1 = (*it).second;
        ++it;
        User &u2 = (*it).second;
        ++it;
        
        bool question = false;
        
        if(it!=m.end())
        {
        	User &u3 = (*it).second;
        	if(u3.score==u2.score)
        	{
                printf("?\n");
                question = true;
            }
        }        
        if(!question)
        {
            printf("%s %s\n",u1.name,u2.name);
        }
    }
    
    return 0;
}


