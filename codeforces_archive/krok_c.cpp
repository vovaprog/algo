#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

struct Server{
	int64 host;
	string hostString;
	set<int64> paths;
	int64 totalHash=0;
};

vector<Server> servers;
map<int64,int> serversMap;

map<int64,vector<int>> output;

template<class TMap,class TKey,class TValue>
inline bool tryGetValue(TMap &m, TKey &key, TValue &u)
{
    auto it = m.find(key);
    if(it!=m.end())
    {
        u = it->second;
        return true;
    }
    return false;
}


//=================================================================
//====================== string hash ==============================
//=================================================================

map<int64,string> stringHashes;

int64 calcStringHash(string &s)
{
	const int p = 239017;
	int64 hash = 0, p_pow = 1;
	for (size_t i=0; i<s.length(); ++i)
	{
		//add one, to make 'aaaaa' hash not zero
		//hash += (s[i] - 'a' + 1) * p_pow;
		
		hash += (s[i] + 1) * p_pow;
		p_pow *= p;
	}	
	
	while(true)
	{
		string existingS;
		if(tryGetValue(stringHashes,hash,existingS))
		{
		    if(existingS==s)
		    {
		        break;    
		    }
		    else
		    {
		        ++hash;
		    }
		}
		else
		{
			hashes[hash]=s;
			break;
		}		
	}
	
	return hash;
}

//=================================================================
//====================== string hash ==============================
//=================================================================



//=================================================================
//========================= set hash ==============================
//=================================================================

map<int64,int> setHashes;

inline set<int64>& getSet(int getIndex)
{
    return servers[getIndex].paths;
}

void calcSetHash(set<int64> data, int setIndex)
{
	const int p = 239017;
	int64 hash = 0, p_pow = 1;
	
	for(int64 d : data)
	{
	    //hash += (pathHash - 'a' + 1) * p_pow;
	    hash += (d + 1) * p_pow;
	    p_pow *= p;
	}
	
	while(true)
	{
		int ind;
		if(tryGetValue(setHashes,hash,ind))
		{
		    set<int64>& existingData = getSet(ind);
		    
		    if(existingData==data)
		    {
		        break;
		    }
		    else
		    {
		        ++hash;
		    }		    
		}
		else
		{
			totalHashes[hash]=setIndex;
			break;
		}		
	}	
	
	srv.totalHash = hash;
}

//=================================================================
//========================= set hash ==============================
//=================================================================


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
		host = s.substr(7);
		path = "";		
	}
	else
	{
		host = s.substr(7,pos - 7);
		path = s.substr(pos);
	}	
	
	int64 hostHash = calcStringHash(host);
	int64 pathHash = calcStringHash(path);
	
	int srvIndex;
	
	if(tryGetValue(serversMap,hostHash,srvIndex))
	{
		if(servers[srvIndex].paths.count(pathHash)==0)
		{
			servers[srvIndex].paths.insert(pathHash);			
		}
	}
	else
	{
		servers.emplace_back();
		Server &srv = servers[servers.size()-1];
		srv.hostString = s.substr(0,pos);
		srv.paths.insert(pathHash);
		serversMap[hostHash] = servers.size()-1;
	}
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
        
    int outGroups=0;
        
    for(int i=0;i<servers.size();++i)
    {
        calcSetHash(servers[i].paths, i);
        
    	vector<int> &outV = output[servers[i].totalHash];
    	outV.push_back(i);
    	if(outV.size()==2) outGroups++;
    }
    
    cout <<outGroups<<endl;

    
    for(auto &p : output)
    {
        vector<int> &group = p.second;
        
        if(group.size()>1)
        {
            for(auto &h : group)
            {
                cout << servers[h].hostString<<" ";
            }
            cout << endl;
        }
    }    
    
    return 0;
}
