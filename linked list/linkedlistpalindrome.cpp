#include<iostream>
using namespace std;
class node
{
public:
    node*next;
    int data;
    node(int d)
    {
        next=NULL;
        data=d;
    }
};
void insertatfront(node*&head,node*&tail,int d)
{
    if(head==NULL)
    {
        node*n=new node(d);
        head=n;
        tail=n;
        return;
    }
    node*n =new node(d);
    n->next=head;
    head=n;
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
void reverselinkedlist(node*&A)
{
    node*prev=NULL;
    node*curr=A;
    while(curr!=NULL)
    {
        node*n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    A=prev;
    //node*temp2=head;
}
node*middle(node*head)
{
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL &&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
void printhead(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}
bool ispalindrome(node*head)
{

    node*mid=middle(head);
    node*A=mid->next;
    mid->next=NULL;
    reverselinkedlist(A);
    printhead(A);
    node*temp1=head;
    node*temp2=A;
    while(temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
        {
            return false;
        }
        else
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return true;

}

int main()
{
    node*head=NULL;
    node*tail=NULL;
    insertatfront(head,tail,0);
    insertatfront(head,tail,1);
    insertatfront(head,tail,2);
    //insertatfront(head,tail,2);
    insertatfront(head,tail,1);
    insertatfront(head,tail,0);
    if(ispalindrome(head))
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }

}
