#include <iostream>
#include <string.h>

using namespace std;

bool compare(const char *s0,const char*s1,int length)
{
    for(int i=0;i<length;i++)
    {
        if(s0[i]!=s1[i]) return false;
    }
    return true;
}

int search(const char *s,const char *pattern)
{
    int stringLength=strlen(s);
    int patternLength=strlen(pattern);
    
    int shift=0;
    
    for(int i=1;i<patternLength;i++)
    {
        if(compare(pattern+i,pattern,patternLength-i))
        {
            shift=i;
            break;
        }        
    }
    
    cout <<"shift: "<<shift<<endl;
    
    int si=0,pi=0;    
    
    while(true)
    {        
        if(s[si]==pattern[pi])
        {
            cout <<"(="<<si<<","<<pi<<")";
            si++;
            pi++;            
        }
        else
        {
            if(pi==0)
            {
                si++;
            }
            else
            {
                if(shift>0 && shift<pi)
                {
                    pi-=shift;
                    cout <<"(s"<<pi<<")";
                }
                else
                {
                    pi=0;
                    cout <<"(0)";
                }
            }
        }
        
        if(pi==patternLength)
        {
            return si-patternLength;
        }
        if(si==stringLength)
        {
            return -1;
        }        
    }    
}


int search2(const char *s,const char *pattern)
{
    int stringLength=strlen(s);
    int patternLength=strlen(pattern);
    
    int *patternIndexRules=new int[patternLength];    
    int matchIndex=-1;
    
    patternIndexRules[0]=0;
    
    for(int i=1;i<patternLength;i++)
    {
        if(matchIndex<0)
        {
            if(compare(pattern+i,pattern,patternLength-i))
            {
                matchIndex=i;
            }
            patternIndexRules[i]=0;
        }
        else
        {
            patternIndexRules[i]=i-matchIndex;
        }
    }

    int si=0,pi=0;    
    
    while(true)
    {        
        if(s[si]==pattern[pi])
        {            
            si++;
            pi++;            
        }
        else
        {            
            if(pi==0)
            {
                si++;
            }            
            pi = patternIndexRules[pi];
        }
        
        if(pi==patternLength)
        {
            delete[] patternIndexRules;
            return si-patternLength;
        }
        if(si==stringLength)
        {
            delete[] patternIndexRules;
            return -1;
        }        
    }    
}

int* prefixFunction(const char *pattern);
void printPrefixFunction(const char *s, int *prefixFun);

int search3(const char *s,const char *pattern)
{
    int stringLength=strlen(s);
    int patternLength=strlen(pattern);
    
    int *patternIndexRules=prefixFunction(pattern); 
    printPrefixFunction(s,patternIndexRules);

    return -1;
    
    int si=0,pi=0;    
    
    while(true)
    {        
        cout <<"si: "<<si<<" ";
        cout <<"pi: "<<pi<<" ";
        
        if(s[si]==pattern[pi])
        {            
            si++;
            pi++;            
            
            if(pi==patternLength)
            {
                delete[] patternIndexRules;
                return si-patternLength;
            }            
        }
        else
        {            
            if(pi==0)
            {
                si++;
            }            
            else
            {
                pi = patternIndexRules[pi]-1;
            }
        }
        
        if(si==stringLength)
        {
            delete[] patternIndexRules;
            return -1;
        }        
    }    
}

int searchBack(const char *s,const char *pattern)
{
    int stringLength=strlen(s);
    int patternLength=strlen(pattern);
    
    int shift=patternLength;
    
    for(int i=1;i<patternLength;i++)
    {
        if(compare(pattern+i,pattern,patternLength-i))
        {
            shift=i;
            break;
        }        
    }
 
    int si=patternLength-1,pi=patternLength-1;
    
    while(true)
    {
        if(s[si]==pattern[pi])
        {
            cout <<"(="<<si<<","<<pi<<")";
            si--;
            pi--;
        }
        else
        {
            cout <<"(0 "<<si<<","<<pi<<")";
            
            if(pi==patternLength-1)
            {
                si++;
            }
            else
            {
                si+=(patternLength-1-pi) + shift;
                pi=patternLength-1;
            }

            cout <<"(0> "<<si<<","<<pi<<")";
        }
        if(pi<0)
        {
            return si+1;
        }
        if(si>=stringLength)
        {
            return -1;
        }
    }
}

void testSearch()
{
    const char *ss[]={
        "eabce","abc"
        ,"abcabdabcabcd","abcabc"
        ,"bacaabaaaaacc","aaaaa"
        ,"bababcabababc","ababab"
    };
    int ssLength=8;
    
    //const char *s="abcabdabcabcd";
    //const char *pattern="abcabc";
    //const char *s="bacaabaaaaacc";
    //const char *pattern="aaaaa";
    //const char *s="bababcabababc";
    //const char *pattern="ababab";
    
    for(int i=0;i<ssLength;i+=2)
    {
        int result=search2(ss[i],ss[i+1]);
        
        cout<<endl<<ss[i]<<endl<<ss[i+1]<<endl;
        cout <<"result: "<<result<<endl;
    }
}

