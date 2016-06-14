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

char command[100];

const int INSERT = 1;
const int REMOVE_MIN = 2;
const int GET_MIN = 3;

struct Operation{
    int cmd;
    int val;
    
    Operation(int argCmd, int argVal):cmd(argCmd), val(argVal){}
};

vector<Operation> ops;

int main()
{
    int n, v;

    std::priority_queue<int, std::vector<int>,std::greater<int> > q;
    
    scanf("%d",&n);

    ops.reserve(1000100);    
    
    for(int i = 0; i < n; ++i)
    {
        scanf("%s",command);
        
        if(strcmp(command,"insert")==0)
        {
            scanf("%d",&v);
            
            q.push(v);
            
            ops.emplace_back(INSERT,v);
        }
        else if(strcmp(command, "removeMin")==0)
        {
            if(q.size()>0)
            {
                q.pop();    
            }
            else
            {
                ops.emplace_back(INSERT,1);
            }
            ops.emplace_back(REMOVE_MIN,0);
        }
        else
        {
            scanf("%d", &v);
            
            int top = q.top();
            
            while(true)
            {
                if(q.size()==0)
                {
                    break;    
                }
                if(q.top()>=v)
                {
                    break;    
                }

                ops.emplace_back(REMOVE_MIN, 0);
                
                q.pop();
            }

            if(q.size()==0 || q.top()!=v)
            {   
                ops.emplace_back(INSERT, v);
                
                q.push(v);
            }
                        
            ops.emplace_back(GET_MIN, v);
        }
    }

    printf("%d\n",ops.size());
    
    for(auto &op : ops)
    {
        switch(op.cmd){
        case INSERT:
            printf("insert %d\n", op.val);
            break;
        case GET_MIN:
            printf("getMin %d\n", op.val);
            break;
        case REMOVE_MIN:
            printf("removeMin\n");
            break;
        };
    }
    
    return 0;
}
