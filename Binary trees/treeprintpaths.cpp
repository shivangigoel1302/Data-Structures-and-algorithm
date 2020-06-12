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
        left=NULL;
        right=NULL;
    }
};
node *buildtree()
{
    int data;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    node*root=new node(data);
    cout<<"enter to the left of"<<data<<endl;
    root->left=buildtree();
    cout<<"enter to the right of"<<data<<endl;
    root->right=buildtree();
    return root;
}

void printpaths(node*root,int i,int a[])
{
    if(root==NULL)
    {
        return;
    }
    a[i]=root->data;
    i++;
    if(root->left==NULL &&root->right==NULL)
    {
        for(int j=0;j<i;j++)
        {
            cout<<a[j]<<" ";
        }
        cout<<endl;
    }
    else
    {
        printpaths(root->left,i,a);
        printpaths(root->right,i,a);
    }
}

int main()
{
    node*root=buildtree();
    int a[100];
    printpaths(root,0,a);
}
