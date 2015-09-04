
int binarySearch(int *list, int listSize, int key)
{
    int upBound = listSize;
    int lowBound = 0;
    
    int i = (upBound - lowBound) / 2;
    
    while(true)
    {
        if(list[i]==key)
        {
            return i;
        }
        else if(key < list[i])
        {
            if(i==lowBound)
            {
                return -1;
            }
            if(i>0 && key > list[i-1])
            {
                return -1;
            }
            
            upBound = i;
                        
            i = (i - lowBound) / 2;
        }
        else
        {
            if(i==upBound)
            {
                return -1;
            }                        
            if(i<listSize-1 && key < list[i+1])
            {
                return -1;
            }
            
            lowBound = i;
            i = i + (upBound - i) / 2;
        }        
    }    
}

int midPoint(int low, int up)
{
    return low + (up - low) / 2;
}

int binarySearch2(int *list, int listSize, int key)
{
    int lowBound=0, upBound=listSize - 1;
    int i;
    
    while(lowBound<=upBound)
    {
        i = midPoint(lowBound,upBound);
        
        if(list[i]==key)
        {
            return i;
        }
        else if(key>list[i])
        {
            lowBound = i+1;
        }
        else if(key<list[i])
        {
            upBound = i-1;
        }        
    }
    
    return -1;
}


