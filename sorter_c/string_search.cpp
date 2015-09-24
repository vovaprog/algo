
bool compare(char *s0,char*s1,int length)
{
    for(int i=0;i<length;i++)
    {
        if(s0[i]!=s1[i]) return false;
    }
    return true;
}

int search(char *s,char *pattern)
{
    vector<int> patternMatches;
    
    int stringLength=strlen(s);
    int patternLength=strlen(pattern);
    
    for(int i=1;i<patternLength;i++)
    {
        if(compare(pattern+i,pattern,patternLength-i))
        {
            patternMatches.push_back(i);
        }        
    }
    
    for(int i=0;i<stringLength;)
    {
        int shiftIndex=-1;
        for(int j=0;j<patternLength;)
        {
            if(s[i]!=pattern[j])
            {
                shift(patternMatches, j, shiftIndex); 
            }
        }
    }    
}

