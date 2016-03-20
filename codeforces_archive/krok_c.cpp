#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;
//typedef unsigned long long int u64;

struct Server{
	int64 host;
	string hostString;
	string totalString;
	set<int64> paths;
	int64 totalHash=0;
};

vector<Server> servers;
map<int64,int> serversMap;

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

//hash<string> hasher;

map<int64,string> hashes;

int64 calcHash(string &s)
{
	//const int p = 31;
	const int p = 239017;
	//long long hash = 0, p_pow = 1;
	int64 hash = 0, p_pow = 1;
	for (size_t i=0; i<s.length(); ++i)
	{
		// желательно отнимать 'a' от кода буквы
		// единицу прибавляем, чтобы у строки вида 'aaaaa' хэш был ненулевой
		hash += (s[i] - 'a' + 1) * p_pow;
		//hash += (s[i] + 1) * p_pow;
		p_pow *= p;
	}	
	
	//while(hashes.count(hash)!=0) ++hash;
	
	while(true)
	{
		string oldS;
		if(tryGetValue(hashes,hash,oldS))
		{
			if(oldS!=s) ++hash;
			else
			{
				hashes[hash]=s;
				break;
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
	
	//cout << s << "   "<<host<<"   "<<path<<endl;
	
	int64 hostHash = calcHash(host);
	int64 pathHash = calcHash(path);
	
	int srvIndex;
	
	if(tryGetValue(serversMap,hostHash,srvIndex))
	{
		if(servers[srvIndex].paths.count(pathHash)==0)
		{
			servers[srvIndex].paths.insert(pathHash);
			servers[srvIndex].totalHash += pathHash;			
		}
	}
	else
	{
		servers.emplace_back();
		Server &srv = servers[servers.size()-1];
		srv.hostString = s.substr(0,pos);
		srv.totalString = s;
		srv.paths.insert(pathHash);
		srv.totalHash = pathHash;
		serversMap[hostHash] = servers.size()-1;
	}
}

map<int64,vector<int>> output;

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
    	vector<int> &outV = output[servers[i].totalHash];
    	outV.push_back(i);
    	if(outV.size()==2) outGroups++;
    	//cout << servers[i].totalHash<<"   ";
    }
    //cout <<endl;
    //return 0;
    
    cout <<outGroups<<endl;
    
    /*if(outGroups>40000)
    {
    	set<int> inGroups;
    	
		for(auto &p : output)
		{
			vector<int> &group = p.second;
			
			if(group.size()>1)
			{
				for(auto &h : group)
				{
					inGroups.insert(h);
					//cout << servers[h].hostString<<" ";
					//cout <<h<<" ";
				}
				//cout << endl;
			}
		}
		
		cout <<"inGroups: "<<inGroups.size()<<endl;
		cout <<"servers: "<<servers.size()<<endl;
		
		for(int i=0;i<servers.size();i++)
		{
			if(inGroups.count(i)==0)
			{
				//cout <<servers[i].hostString<<"   ";
				cout <<i<<" ";					
			}			
		}
	}
	else*/
	{
    
		for(auto &p : output)
		{
			vector<int> &group = p.second;
			
			if(group.size()>1)
			{
				for(auto &h : group)
				{
					cout << servers[h].hostString<<" ";
					//cout <<h<<" ";
				}
				cout << endl;
			}
		}
    
    }
    
    return 0;
}
