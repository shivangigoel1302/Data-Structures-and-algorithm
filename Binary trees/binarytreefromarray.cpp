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

node* buildtreefromarray(int *a,int s,int e)
{

    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    node*root=new node(a[mid]);
    root->left=buildtreefromarray(a,s,mid-1);
    root->right=buildtreefromarray(a,mid+1,e);
    return root;
}

int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    node*root=buildtreefromarray(a,0,n-1);
    bfs(root);
}
