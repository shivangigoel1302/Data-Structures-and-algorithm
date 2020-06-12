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

node* mid(node*head)
{
    if(head==NULL)
    {
        return NULL;
    }
    node *slow=head;
    node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node* merge(node* headA,node* headB)
{
	if(!headA)
	{
		return headB;
	}

	if(!headB)
	{
		return headA;
	}

	node* newhead=NULL;
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


node* mergeSort(node* head)
{
	if(head->next==NULL || head== NULL)
	{
		return head;
	}

	node* middle=mid(head);
	node* A=head;
	node* B=middle->next;
	middle->next=NULL;

	A=mergeSort(A);
	B=mergeSort(B);
	node* newHead=merge(A,B);
	return newHead;

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
    node*newhead=mergeSort(head);
    print(newhead);


}
