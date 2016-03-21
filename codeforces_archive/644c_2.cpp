#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

unordered_map<string,set<string>> servers;
unordered_map<string,set<string>> output;

void prepare(string &s)
{
	string host, path;
	
	if(s.size()<7)
	{
		return;	
	}
	
	int pos = s.find("/",7);
	
	if(pos == string::npos)
	{
		host = s;
		path = "";		
	}
	else
	{
		host = s.substr(0,pos);
		path = s.substr(pos);
	}	

	servers[host].insert(path);
}


int main()
{
    int n;
    
    cin >> n;
    
    servers.reserve(n);
    
    for(int i = 0; i < n; ++i)
    {
    	string s;
    	
    	cin >>s;
    	prepare(s);
    }
        
    int groupCount=0;
    
    for(auto &p : servers)
    {
        set<string> &paths = p.second;

        string fullPath;
        
        for(const string &path : paths)
        {
            fullPath += path;
            fullPath += "*";
        }        
        
        set<string> &outSet = output[fullPath];
        
        outSet.insert(p.first);
        if(outSet.size()==2)
        {
            ++groupCount;
        }
    }    
    
    cout <<groupCount<<endl;
    
    for(auto &p : output)
    {
        set<string> &srvs = p.second;
        
        if(srvs.size()>1)
        {
            for(const string &srv : srvs)
            {
                cout <<srv<<" ";
            }
            cout <<endl;
        }
    }    
    
    return 0;
}


