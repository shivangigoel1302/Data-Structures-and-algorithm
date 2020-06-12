#include<iostream>
using namespace std;


class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data=d;
        next=NULL;
    }

};

void insertatend(node*&head,node*&tail,int d)
{
    if(head==NULL)
    {
        node*n= new node(d);
        head=n;
        tail=n;
        return;
    }
    node *n=new node(d);
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
void createcycle(node*head)
{
    node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head->next->next;
}
bool iscyclic(node*head)
{
    node*slow=head;
    node*fast=head;
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
    node*slow=head;
    node*fast=head;
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
        if(fast==slow)
        {
            prev->next=NULL;
            break;
        }
    }
}

int main()
{
   node*head=NULL;
node*tail=NULL;

    insertatend(head,tail,1);
    insertatend(head,tail,3);
    insertatend(head,tail,10);
    insertatend(head,tail,4);
    insertatend(head,tail,7);
    insertatend(head,tail,6);
    insertatend(head,tail,9);

    print(head);
    cout<<endl;
    createcycle(head);
    if (iscyclic)
    {
        cout<<"yes it is cyclic"<<endl;
        breakcycle(head);
        print(head);
    }
    else
    {
        cout<<"no it is not cyclic"<<endl;
    }


}
