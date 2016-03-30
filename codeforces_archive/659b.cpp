#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

struct User{
    int score;
    char *name;
    bool operator<(const User &u2) const
    {
        return score<u2.score;
    }
};

priority_queue<User> regUsers[10010];

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
        
        regUsers[region].push(u);
    }
    
    for(int i=0;i<nRegions;++i)
    {
        priority_queue<User> &q = regUsers[i];
        
        User u1 = q.top();q.pop();
        User u2 = q.top();q.pop();
        
        bool question = false;
        
        if(q.size()>0)
        {
            User u3 = q.top();
            if(u3.score == u2.score)
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


