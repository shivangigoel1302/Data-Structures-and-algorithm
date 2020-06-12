#include<iostream>
#include<queue>
using namespace std;

class node{
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

void bfslevel(node*root)
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

int count(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}

int sum(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->data +sum(root->left)+sum(root->right);
}

int main()
{
   node*root=createtree();
   bfslevel(root);
  //cout<<count(root)<<endl;
//cout<<sum(root)<<endl;
}
