#include <iostream>

using namespace std;

struct node{
    int value;
    node *next;    
};

node* reverseNeighbors(node *head)
{    
    if(head==nullptr)
    {
        return nullptr;
    }
    if(head->next==nullptr)
    {
        return head;
    }
    
    node *cur=head;
    node *result=head->next;
   
    
    while(cur!=nullptr && cur->next!=nullptr)
    {
        node *next2=cur->next->next;
        cur->next->next=cur;
        
        if(next2!=nullptr)
        {
            cur->next=next2->next;
        }
        else
        {
            cur->next=next2;
        }
        cur=next2;
    }
    
    return result;
}

void printList(node *cur)
{
    cout <<endl<<"====================================="<<endl;
    while(cur!=nullptr)
    {
        cout <<cur->value<<" ";
        cur=cur->next;
    }
    cout <<endl<<"====================================="<<endl;
}

void testReverseNeighbors()
{
    node *head=new node;
    head->value=0;
    node *cur=head;
    
    int i;
    for(i=1;i<10;i++)
    {        
        cur->next=new node();
        cur->next->value=i;
        cur->next->next=nullptr;
        cur=cur->next;
    }
    
    printList(head);
    head=reverseNeighbors(head);
    printList(head);
}
