#include<iostream>
using namespace std;
class node
{
    public:
        node*right;
        node*left;
        int data;
        node(int d)
        {
            data=d;
            right=NULL;
            left=NULL;
        }
};
node*createtree()
{
    int data;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    node*root=new node(data);
    root->left=createtree();
    root->right=createtree();
    return root;
}
void midlevel(node*slow,node*fast)
{
    if(slow==NULL &&fast==NULL)
    {
        return;
    }
    if(fast->right==NULL&&fast->left==NULL||fast->right->right==NULL&&fast->left->left==NULL)
    {
        cout<<slow->data<<" ";
        return;
    }
    midlevel(slow->left,fast->left->left);
    midlevel(slow->right,fast->right->right);
}
int main()
{
    node*root=createtree();
    midlevel(root,root);
}
