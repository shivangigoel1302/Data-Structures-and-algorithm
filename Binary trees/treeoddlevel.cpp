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
        right=NULL;
        left=NULL;
        data=d;
    }
};
node *createtree()
{
    int data;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    node *root=new node(data);
    cout<<"enter to the left of"<<data<<endl;
    root->left=createtree();
    cout<<"enter to the right of "<<data<<endl;
    root->right=createtree();
    return root;
}
void printodd(node*root,bool isodd=true)
{
    if(root==NULL)
    {
        return;
    }
    if(isodd)
    {
        cout<<root->data<<" ";
    }
    printodd(root->left,!isodd);
    printodd(root->right,!isodd);
}
int main()
{
    node*root=createtree();
    cout<<endl<<endl;
    printodd(root);
}
