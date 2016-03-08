#include <bits/stdc++.h>

using namespace std;

#define debug(args...) //printf(args);
#define debug2(fmt,args...) //printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

vector<int> edges[100000];
int colors[100000] = {0};

int allOnes[100000] = {0};
int allTwos[100000] = {0};

vector<int> parts[4];

int walkTree(int cur, int parent,int color,int &countOnes, int &countTwos)
{
	if(colors[cur]==0)
	{
		if(color==1) countOnes++;
		else countTwos++;

		colors[cur] = color;

		int newColor = 3-color;

		for(auto v : edges[cur])
		{
			if(v!=parent)
			{
				walkTree(v, cur, newColor, countOnes, countTwos);
			}
		}
	}
	else if(colors[cur]!=color)
	{
		printf("0 1");
		exit(0);
	}
}


int main()
{
	int vertCount, edgeCount;

	scanf("%d %d",&vertCount,&edgeCount);

	if(edgeCount==0)
	{
		cout <<"3 "<<(int64)vertCount*((int64)vertCount-1)*((int64)vertCount-2)/6;
		return 0;
	}

	for(int i = 0; i < edgeCount; ++i)
	{
		int v0,v1;
		scanf("%d %d",&v0,&v1);
		--v0;
		--v1;
		edges[v0].push_back(v1);
		edges[v1].push_back(v0);
	}

	for(int i=0;i<vertCount;i++)
	{
		if(colors[i]==0)
		{
			int countOnes=0, countTwos=0;

			walkTree(i,-1,1,countOnes, countTwos);

			allOnes[i]=countOnes;
			allTwos[i]=countTwos;
			if(countOnes + countTwos>=3)
			{
				parts[3].push_back(i);
			}
			else
			{
				parts[countOnes + countTwos].push_back(i);
			}
		}
	}

	if(parts[3].size()>0)
	{
		int64 result = 0;

		for(auto q : parts[3])
		{
			result += (int64)allOnes[q] * ((int64)allOnes[q]-1)/2;
			result += (int64)allTwos[q] * ((int64)allTwos[q]-1)/2;
		}

		cout <<"1 "<<result;
	}
	else
	{
		cout <<"2 "<<(int64)parts[2].size() * ((int64)vertCount - 2);
	}

	return 0;
}
