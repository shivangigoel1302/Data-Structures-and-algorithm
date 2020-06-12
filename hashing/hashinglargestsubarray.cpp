#include<iostream>
#include<unordered_map>
using namespace std;
int lengthofsubarray(int *a,int n)
{
    int len=0;
    int pre=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        pre=pre+a[i];
        if(a[i]==0 &&len==0)
        {
            len=1;
        }
        if(pre==0)
        {
            len=max(len,i+1);
        }
        if(mp.find(pre)!=mp.end())
        {
            len=max(len,i-mp[pre]);
        }
        else
        {
            mp[pre]=i;
        }
    }
    return len;
}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int i=lengthofsubarray(a,n);
    cout<<i<<endl;
}
