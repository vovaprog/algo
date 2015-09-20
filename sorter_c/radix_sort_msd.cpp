#include <iostream>

using namespace std;

void printList(int *list,int listSize);

inline bool oneBit(int value,int bitNumber)
{
    //cout <<"bitNumber "<<bitNumber<<endl;
    
    int result = value & (1 << bitNumber);
    
    //cout <<"---- result "<<result<<"   value "<<value<<endl;
    
    return ((value & (1 << bitNumber))!=0);
}

inline void putToZero(int index,int zeroBorder)
{
    //cout <<"putToZero "<<index<<"  zeroBorder "<<zeroBorder<<endl;
}

inline void putToOne(int *list, int index,int oneBorder)
{
    if(index!=oneBorder)
    {
        int temp=list[index];
        list[index]=list[oneBorder];
        list[oneBorder]=temp;
    }
    
    //cout <<"putToOne "<<index<<"  oneBorder "<<oneBorder<<endl;
}

//static int listSizeTemp;

void radixSortMsdRec(int *list, int startIndex, int endIndex,int bit)
{
    //cout <<"<<< start"<<startIndex<<"  end "<<endIndex<<"   bit"<<bit<<"   bitvalue "<<(1<<bit)<<" >>>"<<endl;
    //printList(list,listSizeTemp);
    
    int zeroBorder=startIndex;
    int oneBorder=endIndex-1;
    
    for(int i=startIndex;i<endIndex;i++)
    {                
        if(oneBit(list[i],bit))
        {
            putToOne(list, i, oneBorder);
            oneBorder-=1;
            i-=1;
        }
        else            
        {
            putToZero(i,zeroBorder);
            zeroBorder+=1;
        }        
        
        //printList(list+startIndex,endIndex-startIndex);
        
        if(zeroBorder>oneBorder)
        {
            if(bit>0 && endIndex-startIndex>2)
            {
                if(zeroBorder>startIndex)
                {
                    //cout <<"+1 start zero border: "<<zeroBorder<<"   one border: "<<oneBorder<<endl;
                    radixSortMsdRec(list,startIndex,zeroBorder,bit-1);
                }
                if(zeroBorder<endIndex)
                {
                    //cout <<"+2 start zero border: "<<zeroBorder<<"   one border: "<<oneBorder<<endl;
                    radixSortMsdRec(list,zeroBorder,endIndex,bit-1);
                }                
            }
            
            return;
        }
    }    
}


void radixSortMsd(int *list, int listSize,int maxBit)
{
    //listSizeTemp = listSize;
    radixSortMsdRec(list,0,listSize,maxBit);    
}
