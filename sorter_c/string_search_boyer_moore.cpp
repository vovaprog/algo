#include <iostream>
#include <string.h>

using namespace std;

int searchBoyerMoore(const char *s,const unsigned char *pattern)
{
    int patternLength=strlen((const char*)pattern);
    int stringLength=strlen(s);
    
    int *stopSymbols=new int[256];
    for(int i=0;i<256;i++) stopSymbols[i]=0;    
    
    for(int i=patternLength-2;i>=0;i--)
    {
        if(stopSymbols[pattern[i]]==0)
        {
            stopSymbols[pattern[i]]=patternLength-1-i;
        }
    }
    
    for(int i=0;i<256;i++) 
    {
        if(stopSymbols[i]!=0)
        {
            cout <<"i: "<<i<<"   val: "<<     stopSymbols[i]<<endl;
        }
    }
    
    int m=0;
    int si=patternLength-1;
    
    while(true)
    {
        cout <<"m: "<<m<<"   si: "<<si<<endl;
        
        if(s[m + si]==pattern[si])
        {
            if(si==0)
            {
                delete[] stopSymbols;
                return m;
            }
            
            si--;
        }
        else
        {
            int shift = stopSymbols[ s[m+si] ];
                        
            if(shift==0)
            {
                shift = si + 1;
            }

            cout <<"shift: "<<shift<<endl;            
            
            m += shift;
            si=patternLength-1;            
        }
        
        if(m + si >= stringLength)
        {
            delete[] stopSymbols;
            return -1;
        }        
    }
}

int* prefixFunction(const char *pattern)
{
    int patternLength=strlen(pattern);
    int *function=new int[patternLength];
    
    int j=0;
    function[0]=0;
    
    for(int i=1;i<patternLength;i++)
    {
        while(j>0 && pattern[i]!=pattern[j])
        {
            j=function[j-1];            
        }
        
        if(pattern[i]==pattern[j])
        {        
            j++;
        }
        
        function[i]=j;
    }
    
    return function;
}

void printPrefixFunction(const char *s, int *prefixFun)
{     
    cout <<"[[[[[[[[[[[[ "<<endl;
    
    cout <<s<<endl;
    
    for(int i=0;i<strlen(s);i++)
    {
        cout <<prefixFun[i]<<" ";
    }
    cout <<endl<<" ]]]]]]]]]]]]"<<endl;    
}

void testPrefixFunction()
{
    const char* pattern = "abcdabcabcdabcdab";
    int patternLength=strlen(pattern);
    int* prefixFun;
    
    prefixFun=prefixFunction(pattern);
    
    printPrefixFunction(pattern,prefixFun);
}

void testSearchBoyerMoore()
{
    const char *ss[]={
        "eabce","abc"
        ,"abcabdabcabcd","abcabc"
        ,"bacaabaaaaacc","aaaaa"
        ,"bababcabababc","ababab"
    };
    int ssLength=8;
        
    for(int i=0;i<ssLength;i+=2)
    {
        cout <<"====================================================="<<endl;
        cout<<endl<<ss[i]<<endl<<ss[i+1]<<endl;
        
        int result=searchBoyerMoore(ss[i],(const unsigned char*)ss[i+1]);
                
        cout <<"result: "<<result<<endl;
        cout <<"====================================================="<<endl;
    }
}


