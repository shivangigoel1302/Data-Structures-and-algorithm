#include<iostream>
using namespace std;
class node{
    public:
	int data;
	node*next;
	node(int d)
	{
		data=d;
	next=NULL;
	}
};

void insertatfront(node*&head,int data)
{
	if(head==NULL)
	{
		node*n=new node(data);
		head=n;
		return;
	}
	node*n=new node(data);
	n->next=head;
	head=n;
}

void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

void buildlist(node*&head,int n)
{
    int data;

int i=1;
	while(i<=n)
	{
	    cin>>data;
		insertatfront(head,data);
		i++;
	}
}
void reverseLL(node*&head)
{
	node*curr=head;
	node*prev=NULL;
	while(curr)
	{
		node*n=curr->next;
		curr->next=prev;
		prev=curr;
		curr=n;
	}
	head=prev;
}

int main() {
    int n;
    cin>>n;

	node*head=NULL;
	node*tail=NULL;

    buildlist(head,n);
    print(head);
    cout<<endl;
	reverseLL(head);
    print(head);
	return 0;
}
