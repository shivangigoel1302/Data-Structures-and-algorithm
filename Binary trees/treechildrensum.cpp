#include<iostream>
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
node*buildtree()
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
bool checksum(node *root)
{
    int leftdata=0;
    int rightdata=0;
    if(root==NULL||root->left==NULL &&root->right==NULL)
    {
        return true;
    }
    else
    {
        if(root->left!=NULL)
        {
            leftdata=root->left->data;
        }
        if(root->right!=NULL)
        {
            rightdata=root->right->data;
        }
        if(rightdata+leftdata==root->data && checksum(root->left)==true &&checksum(root->right)==true)
        {
            return true;
        }
        else{
            return false;
        }
    }

}
int main()
{
   node*root=buildtree();
   if(checksum(root))
   {
       cout<<"yes";
   }
   else{
    cout<<"no";
   }
}
