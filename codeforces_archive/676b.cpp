#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

//=====================================================================
#define debug3(args...) { vector<string> v = splitArgNames(#args); debugPrint(v.begin(), args); }
vector<string> splitArgNames(const string& s) 
{ vector<string> v; stringstream ss(s); for (string x; getline(ss, x, ',');) { v.emplace_back(x); } return move(v); }
void debugPrint(vector<string>::iterator it) { cout <<"\n"; }
template<typename T, typename... Args>
void debugPrint(vector<string>::iterator it, T head, Args... args) 
{ cout << *it <<" = "<< head << "     "; debugPrint(++it, args...); }
//=====================================================================

typedef long long int int64;

struct Node
{
    int needed=0;
    int add=0;
    int cur=0;
    Node *left=nullptr, *right=nullptr;
};

Node nodes[100100];
int allocNode = 0;

Node* createNode(int needed, int add)
{
    Node *nd = new Node;
    nd->needed = needed;
    nd->add = add;
    return nd;
}

void buildTree(int nLevs)
{
    Node *b1 = createNode(1, 1);
    
    b1->left = createNode(2, 1);
    b1->right = createNode(2, 1);
    
    
    b2 = b1 ->left;
    b2->left = createNode(4, 1);
    b2->right = createNode(4, 2);
    
    
    
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int nLevs, t;

    cin >> nLevs;

    buildTree(nLevs);
    
    for(int i=0;i<t;i++)
    {
        addCup();            
    }
    
    result = countResult();
    
    cout <<result;
    
    return 0;
}
