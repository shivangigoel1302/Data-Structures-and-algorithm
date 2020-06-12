#include<iostream>
#include<unordered_map>
using namespace std;
int ksubarraysum(int a[],int n)
{
    unordered_map<int,int>mp;
    int len=0;
    int pre=0;
    for(int i=0;i<n;i++)
    {
        pre+=a[i];
        if(a[i]==k && len==0)
        {
            len=1;
        }
        if(pre==k)
        {
            len=max(len,i+1);
        }
        if(mp.find(pre-4)!=mp.end())
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
   int ans=ksubarraysum(a,n);
   cout<<ans;
}
