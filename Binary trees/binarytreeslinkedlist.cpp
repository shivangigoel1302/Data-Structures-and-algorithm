#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node*right;
    node*left;
    node(int d)
    {
        data=d;
        right=NULL;
        left=NULL;
    }
};

node* insertatbst(node*root,int data)
{
    if(root==NULL)
    {
        return new node(data);
    }
    if(data<=root->data)
    {
        root->left=insertatbst(root->left,data);
    }
    else
    {
        root->right=insertatbst(root->right,data);
    }
    return root;
}
void bfs(node*root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node*f=q.front();
        if(f==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<f->data<<",";
            q.pop();
            if(f->left)
            {
                q.push(f->left);
            }
            if(f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}

class linkedlist
{
    public:
    node*head;
    node*tail;
};
linkedlist flatten(node*root)
{
    linkedlist l;
    if(root==NULL)
    {
        l.head=l.tail=NULL;
        return l;
    }
    if(root->right==NULL&&root->left==NULL)
    {
        l.head=l.tail=root;
        return l;
    }
    if(root->left!=NULL && root->right==NULL)
    {
        linkedlist leftLL=flatten(root->left);
        leftLL.tail->right=root;
        l.head=leftLL.head;
        l.tail=root;
        return l;
    }
    if(root->left==NULL&&root->right!=NULL)
    {
        linkedlist rightLL=flatten(root->right);
        root->right=rightLL.head;
        l.tail=rightLL.tail;
        l.head=root;
        return l;
    }
    linkedlist leftLL=flatten(root->left);
linkedlist rightLL=flatten(root->right);
    leftLL.tail->right=root;
    root->right=rightLL.head;
    l.head=leftLL.head;
    l.tail=rightLL.tail;
    return l;
}

node *createtree()
{
    int d;
    cin>>d;
    node*root=NULL;
    while(d!=-1)
    {
        root=insertatbst(root,d);
        cin>>d;
    }
    return root;
}
int main()
{
    node*root=createtree();
    bfs(root);
    cout<<endl;
    linkedlist l=flatten(root);
    node*temp=l.head;
    while(temp!=NULL)
    {
        cout<<temp->data<<",";
        temp=temp->right;
    }

}
