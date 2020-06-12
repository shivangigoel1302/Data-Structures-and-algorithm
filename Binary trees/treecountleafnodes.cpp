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
int countleaf(node*root)
{
  if(root==NULL)
  {
      return 0;
  }
  if(root->left==NULL &&root->right==NULL)
  {
      return 1;
  }
  else{
    return countleaf(root->left)+countleaf(root->right);
  }

}
int main()
{
    node*root=buildtree();
    int countans=countleaf(root);
    cout<<countans;
}
