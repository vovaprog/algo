#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

struct User{
    int score;
    char *name;
    
    bool operator>(const User &u2) const
    {
        return score>u2.score;
    }    
};

multiset<User,greater<User>> regUsers[10010];

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
        
        regUsers[region].insert(u);
    }
    
    for(int i=0;i<nRegions;++i)
    {
        multiset<User,greater<User>> &s = regUsers[i];
        
        auto it = s.begin();
        
        const User &u1 = *it;
        ++it;
        const User &u2 = *it;
        ++it;
        
        bool question = false;
        
        if(it!=s.end())
        {
        	const User &u3 = *it;
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


