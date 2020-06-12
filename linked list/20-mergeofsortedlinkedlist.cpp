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

    insertionatend(headB,tailB,2);
     insertionatend(headB,tailB,25);
      insertionatend(headB,tailB,120);
       insertionatend(headB,tailB,200);

       cout<<"LL A"<<endl;
       print(headA);

       cout<<"LL B"<<endl;
       print(headB);

       cout<<"after merge"<<endl;
       node*newhead=merge(headA,headB);
       print(newhead);










    //node*head=NULL;
    //node*tail=NULL;

    //insertionatfront(head,tail,11);
    //insertionatfront(head,tail,4);
    //insertionatfront(head,tail,3);
    //insertionatfront(head,tail,2);
    //insertionatfront(head,tail,1);


    //insertionatend(head,tail,6);
    //insertionatend(head,tail,7);
    //insertionatend(head,tail,8);
    //insertionatend(head,tail,9);
    //insertionatend(head,tail,10);

    //insertionatpos(head,tail,5,5);

    //print (head);





    //cout<<endl;
    //cout<<"length of linked list"<<length(head)<<endl;


    return 0;
}
