#include<iostream>
using namespace std;
int nstairs(int n,int k,int dp[])
{
    if(n==0)
    {
        return 1;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int ways=0;
    for(int i=1;i<=k;i++)
    {
        if(n>=0)
        {
           ways+=nstairs(n-i,k,dp);
        }
    }
    return dp[n]=ways;
}
int bottomup(int n,int k)
{
    int dp[100]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
               dp[i]+=dp[i-j];
            }
        }
    }
    return dp[n];
}
int main()
{
    int n,k;
    cin>>n>>k;
    int dp[100]={0};
   // cout<<nstairs(n,k,dp);
   cout<<bottomup(n,k);
}
