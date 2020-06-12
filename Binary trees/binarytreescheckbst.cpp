#include<iostream>
#include<climits>
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
node *insertatbst(node*root,int data)
{
    if(root==NULL)
    {
        return NULL;
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
bool checkbst(node*root,int minv=INT_MIN,int maxv=INT_MAX)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>=minv && root->data<=maxv && checkbst(root->left,minv,root->data)&& checkbst(root->right,root->data,maxv))
    {
        return true;
    }
    return false;
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

int main()
{
    node*root=createtree();
    if(checkbst(root))
    {
        cout<<"yes it is";
    }
    else
    {
        cout<<"no it is not";
    }
}
