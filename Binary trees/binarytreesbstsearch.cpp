#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
    int data;
    node*left;
    node*right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
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
bool searchkey(node*root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==data)
    {
        return true;
    }
    if(data<root->data)
    {
       return searchkey(root->left,data);
    }
    else
    {
        return searchkey(root->right,data);
    }
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
        else{
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
int main()
{
    node*root=createtree();
    bfs(root);
    cout<<endl;
    int key;
    cin>>key;
    if(searchkey(root,key))
    {
        cout<<"it is present";
    }
    else{
        cout<<"not present";
    }
}
