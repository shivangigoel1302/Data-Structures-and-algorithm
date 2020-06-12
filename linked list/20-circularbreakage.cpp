#include<iostream>
using namespace std;
class node
{
   public:
       int data;
            node*next;
            node(int d)
            {
                data=d;
                next=NULL;
            }
};

void insertionatfront(node*&head,node*&tail,int d)
{
    if(head==NULL)
    {
        node* n=new node(d);
        head=n;
        tail=n;
        return;
    }

    node* n=new node(d);
    n->next=head;
    head=n;
}


void insertionatend(node*&head,node*&tail,int d)
{
    if(head==NULL)
    {
        node* n=new node(d);
        head=n;
        tail=n;
        return;
    }

    node* n=new node(d);
    tail->next=n;
    tail=n;
}

void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int length(node*head)
{
    int count=0;
    while(head)
    {
        count++;
        head=head->next;

    }
    return count;
}

void insertionatpos(node*&head,node*&tail,int pos,int d)
{
    if(pos==0)
    {
        insertionatfront(head,tail,d);
        return;
    }
    else if(pos>=length(head))
    {
        insertionatend(head,tail,d);
        return;
    }
    else
    {
        int p=1;
        node* temp=head;
        while(p<pos)
        {
            temp=temp->next;
            p++;
        }

        node*n=new node(d);
        n->next=temp->next;
        temp->next=n;

    }
}


node*merge(node* headA,node* headB)
{
    if(!headA)
    {
        return headB;
    }

    if(!headB)
    {
        return headA;
    }
    node*newhead=NULL;
    if(headA->data<=headB->data)
    {
        newhead=headA;
        newhead->next=merge(headA->next,headB);
    }
    else
    {
        newhead=headB;
        newhead->next=merge(headA,headB->next);
    }
    return newhead;
}
node *mid(node*head)
{
    if(head==NULL)
    {
        return NULL;
    }
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node* mergesort(node*head)
{
    if(head->next==NULL || head==NULL)
    {
        return head;
    }

    node* middle=mid(head);
    node*A=head;
    node* B=middle->next;
    middle->next=NULL;

    A=mergesort(A);
    B=mergesort(B);
    node*newhead=merge(A,B);
    return newhead;
}

void createcycle(node*head)
{
    node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head->next->next;
}


bool iscyclic(node* head)
{
    node* slow=head;
    node* fast=head;

    while(fast)
    {
        fast=fast->next;
        if(fast)
        {
            fast=fast->next;
            slow=slow->next;

            if(fast==slow)
            {
                return true;
            }
        }
    }
    return false;
}

void breakcycle(node*head)
{
    node* fast=head;
    node * slow=head;

    while(fast)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            break;
        }
    }
    node* prev=head;
    while(prev->next!=fast)
    {
        prev=prev->next;
    }
    slow=head;
    while(fast)
    {
        fast=fast->next;
        slow=slow->next;
        prev=prev->next;
        if(slow==fast)
        {
            prev->next=NULL;
            break;
        }
    }
}

int main()
{

    node*headA=NULL;
    node*tailA=NULL;

    node*headB=NULL;
    node*tailB=NULL;

    insertionatend(headA,tailA,27);
    insertionatend(headA,tailA,30);
    insertionatend(headA,tailA,67);
    insertionatend(headA,tailA,127);

    //tailA->next=headA->next->next;

    insertionatend(headB,tailB,2);
     insertionatend(headB,tailB,25);
      insertionatend(headB,tailB,120);
       insertionatend(headB,tailB,200);

       cout<<"LL A"<<endl;
       print(headA);

       //cout<<"LL B"<<endl;
      // print(headB);

       cout<<"after merge"<<endl;
       node*newhead=merge(headA,headB);
       print(newhead);

     createcycle(headA);
       if(iscyclic(headA))
       {
           cout<<"yes"<<endl;
           breakcycle(headA);
           print(headA);

       }
       else
       {
           cout<<"no"<<endl;
       }

         return 0;
}
