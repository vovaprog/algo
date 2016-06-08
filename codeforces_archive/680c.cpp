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

int divs[200];
bool isDiv[200];

void createDivs()
{
    for(int i = 0; i <=100; ++i)
    {
        divs[i] = i;
        isDiv[i]=true;
    }

    for(int i=2;i<=100;++i)
    {
        if(isDiv[i])
        {
            for(int j=i+1;j<=100;j++)
            {                
                if(isDiv[j] && divs[j] % divs[i] == 0)
                {
                    isDiv[j] = false;    
                }
            }
        }        
    }
    
    /*int count = 0;
    
    for(int i=2;i<=100;++i)
    {
        if(isDiv[i])
        {
            cout << divs[i] <<" ";
            ++count;
        }
    }
    
    cout << "\ncount: "<<count <<endl;*/    
}

int main()
{
    createDivs();
    
    //string ans;
    char ans[100];
    int countYes = 0;
    int numberYes = 0;
    
    vector<int> numbersYes;
    
    for(int i=2;i<=50;++i)
    {
        if(isDiv[i])
        {
            printf("%d\n", divs[i]);fflush(stdout);
            //cout << divs[i] << endl << flush;
            
            //cin >> ans;
            scanf("%s",ans);
            if(strcmp(ans,"yes")==0)
            //if(ans == "yes")
            {
                ++countYes;
                numberYes = divs[i];
                numbersYes.push_back(divs[i]);
            }
        }
        
        if(countYes>1)
        {
            break;    
        }
    }
    
    if(countYes>1)
    {
        //cout << "composite" <<endl<<flush;
        printf("composite\n");fflush(stdout);
        return 0;
    }

    if(numberYes * numberYes<=100)
    {
        printf("%d\n", (numberYes * numberYes));fflush(stdout);
        scanf("%s",ans);
        if(strcmp(ans,"yes")==0)
        {
            printf("composite\n");fflush(stdout);    
        }
        else
        {
            printf("prime\n");fflush(stdout);    
        }
    }
    else
    {
        printf("prime\n");fflush(stdout);
    }
    //cout <<"prime" <<endl<<flush;
    
    
    return 0;
}
