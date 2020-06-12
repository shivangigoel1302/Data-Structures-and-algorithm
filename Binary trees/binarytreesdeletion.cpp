#include<iostream>
#include<queue>
using namespace std;


class node{
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
node*createtree()
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

node*deleteinBST(node*root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(data<root->data)
    {
        root->left=deleteinBST(root->left,data);
        return root;
    }
    else if(data==root->data)
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL)
        {
            node*temp=root->left;
            delete root;
            return temp;
        }
        if(root->right!=NULL && root->left==NULL)
        {
            node*temp=root->right;
            delete root;
            return temp;
        }
        else
        {
            node*replace=root->right;
            while(replace->left!=NULL)
            {
                replace=replace->left;
            }
            root->data=replace->data;
            root->right=deleteinBST(root->right,replace->data);
            return root;
        }
    }
    else
    {
        root->right=deleteinBST(root->right,data);
        return root;
    }
}
void printin(node*root)
{
    if(root==NULL)
    {
        return;
    }
    printin(root->left);
    cout<<root->data<<",";
    printin(root->right);
    return;
}

int main()
{

    node*root=createtree();
    int s;
    cin>>s;
    bfs(root);
    cout<<endl;

    deleteinBST(root,s);
    bfs(root);
}
