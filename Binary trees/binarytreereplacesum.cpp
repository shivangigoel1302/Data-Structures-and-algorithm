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
        right=NULL;
        left=NULL;
    }
};

node* createtree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node*root=new node(d);
    root->left=createtree();
    root->right=createtree();
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
            cout<<f->data<<" , ";
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
}

int replacesum(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }
   int ls=replacesum(root->left);
   int rs=replacesum(root->right);
    int temp=root->data;
    root->data=ls+rs;
    return temp + root->data;
}

int main()
{
    node*root=createtree();
    bfs(root);
    cout<<endl;
    cout<<endl;
    replacesum(root);
    bfs(root);
}
