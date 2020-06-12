#include<iostream>
#include<unordered_set>
#include"hashtable.h"
using namespace std;
bool subarraysumzero(int a[],int n)
{
   unordered_set<int>m;
    int pre=0;
    for(int i=0;i<n;i++)
    {
        pre=pre+a[i];
        if(pre==0 || m.count(pre)==1)
        {
            return true;
        }
        m.insert(pre);
    }
    return false;
}
int main()
{

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(subarraysumzero(a,n))
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
}
