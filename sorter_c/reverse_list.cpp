#include <iostream>

using std::cout;
using std::endl;

struct node{
    node *next;
    int value;    
};

node* reverse_list(node *first)
{
    node *cur=first;
    node *prev=nullptr;

    while(cur!=nullptr && cur->next!=nullptr)
    {
        if(cur->next==nullptr)
        {
            return cur;    
        }
        node* temp1=cur->next->next;
        node* temp2=cur->next;
        cur->next->next=cur;
        cur->next=prev;
        if(temp1!=nullptr)
        {
            cur=temp1;
            prev=temp2;
        }
        else
        {
            return temp2;    
        }
    }
    
    return cur;
}

node* reverse_list_rec_internal(node *prev,node *cur)
{    
    node *new_head;
    
    if(cur->next!=nullptr)
    {
        new_head = reverse_list_rec_internal(cur,cur->next);
    }
    else
    {
        new_head=cur;
    }
    
    cur->next=prev;
    
    return new_head;
}

node *reverse_list_rec(node *head)
{
    if(head==nullptr)
    {
        return nullptr;    
    }
    
    return reverse_list_rec_internal(nullptr,head);    
}

void reverseListTest()
{
    node *cur,*prev=nullptr, *head;
    
    for(int i=0;i<10;++i)
    {        
        cur=new node();
        cur->value=i;
        cur->next=nullptr;
        
        if(prev!=nullptr)
        {
            prev->next=cur;    
        }
        prev=cur;
        
        if(i==0)
        {
            head=cur;    
        }
    }
    
    for(cur=head;cur!=nullptr;cur=cur->next)
    {
        cout <<cur->value<<endl;    
    }
    
    cout <<"---------------------"<<endl;
    
    head = reverse_list_rec(head);
        
    for(cur=head;cur!=nullptr;cur=cur->next)
    {
        cout <<cur->value<<endl;    
    }       
}

