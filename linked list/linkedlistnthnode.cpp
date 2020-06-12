#include<iostream>
using namespace std;
class node{
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
    node*n=new node(d);
    n->next=head;
    head=n;
}
int length(node*head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}
void findnth(node*head,int n)
{
    node*temp=head;
    while(n!=1)
    {
        temp=temp->next;
        n--;
    }
    cout<<temp->data;
}
int frequencyofn(node*head,int key)
{
    node*temp=head;
    int ans=0;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            ans++;
        }
        temp=temp->next;
    }
    return ans;
}
void lastnth(node*head,int m)
{
    node*tempo=head;
    int f=length(head)+1-m;
    while(f!=1)
    {
        tempo=tempo->next;
        f--;
    }
    cout<<tempo->data;
}
void print(node*head)
{
    while(head)
    {
        cout<<head->data<<"-->";
        head=head->next;
    }
}
int main()
{
    node*head=NULL;
    node*tail=NULL;
    insertatfront(head,tail,3);
    insertatfront(head,tail,4);
    insertatfront(head,tail,3);
    insertatfront(head,tail,3);
    insertatfront(head,tail,1);
    insertatfront(head,tail,3);
    int n,m,key;
    cin>>n>>m>>key;
    print(head);
    cout<<endl;
    findnth(head,n);
    cout<<endl;
    lastnth(head,m);
    cout<<endl;
    cout<<frequencyofn(head,key);
}
