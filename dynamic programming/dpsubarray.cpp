#include<iostream>
using namespace std;
int maxsubarray(int a[],int n)
{
    int dp[100]={0};
    dp[0]=a[0]>0?a[0]:0;
    int maxtillnow=dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=dp[i-1]+a[i];
        if(dp[i]<0)
        {
            dp[i]=0;
        }
        maxtillnow=max(dp[i],maxtillnow);
    }
    return maxtillnow;
}
int maxsum(int a[],int n)
{
    int currsum=0;
    int maxsum=0;
    for(int i=0;i<n;i++)
    {
        currsum+=a[i];
        if(currsum<0)
        {
            currsum=0;
        }
        maxsum=max(currsum,maxsum);
    }
    return maxsum;
}
int main()
{
    int a[]={-3,2,5,-1,6,3,-2,7,-5,2};
    int n=sizeof(a)/sizeof(int);
    //cout<<maxsubarray(a,n);
    cout<<maxsum(a,n);
}
