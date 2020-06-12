#include<iostream>
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
node*insertinbst(node*root,int data)
{
    if(root==NULL)
    {
        node*r=new node(data);
        return r;
    }
    if(root->data<data)
    {
        root->right=insertinbst(root->right,data);
    }
    else{
        root->left=insertinbst(root->left,data);
    }
    return root;
}
node*buildbinarytree()
{
    int data;
    cin>>data;
    node*root=NULL;
    while(data!=-1)
    {
        root=insertinbst(root,data);
        cin>>data;
    }
    return root;
}
int minval(node*root)
{
    if(root->left==NULL)
    {
        return root->data;
    }
    minval(root->left);
}
int main()
{
    node*root=buildbinarytree();
    int ans=minval(root);
    cout<<ans;
}
