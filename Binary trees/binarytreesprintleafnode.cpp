#include<iostream>
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

node*createtree()
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



void print(node*root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<",";
    }
    if(root->left!=NULL &&root->right==NULL)
    {
        print(root->left);
    }
    if(root->right!=NULL&& root->left==NULL)
    {
        print(root->right);
    }
	if(root->right!=NULL && root->left!=NULL)
	{
		print(root->left);
		print(root->right);
	}
}
int main()
{
    node*root=createtree();
    print(root);
    //printin(root);
}
