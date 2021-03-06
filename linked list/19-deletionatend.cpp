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

void deleteatfront(node*&head,node*&tail)
{
    if (head==NULL)
    {
        return;
    }
    else if(head==tail)
    {
        delete head;
        head=NULL;
        tail=NULL;
        return;
    }
    else
    {
            node*temp=head;
            head=head->next;
            delete temp;
    }
}

void deleteatend(node*&head,node*&tail)
{
    if (head==NULL)
    {
        return;
    }
    else if(head==tail)
    {
        delete head;
        head=NULL;
        tail=NULL;
        return;
    }
    else
    {
            node*temp=head;
            while(temp->next!=tail)
            {
                temp=temp->next;
            }
            temp->next=NULL;
            delete tail;
            tail=temp;
    }
}




int main()
{
    node*head=NULL;
    node*tail=NULL;

    insertionatfront(head,tail,11);
    insertionatfront(head,tail,4);
    insertionatfront(head,tail,3);
    insertionatfront(head,tail,2);
    insertionatfront(head,tail,1);


    insertionatend(head,tail,6);
    insertionatend(head,tail,7);
    insertionatend(head,tail,8);
    insertionatend(head,tail,9);
    insertionatend(head,tail,10);

    insertionatpos(head,tail,5,5);

    print (head);


    deleteatfront(head,tail);

    print (head);

    deleteatend(head,tail);

    print(head);

    cout<<endl;
    cout<<"length of linked list"<<length(head)<<endl;


    return 0;
}
