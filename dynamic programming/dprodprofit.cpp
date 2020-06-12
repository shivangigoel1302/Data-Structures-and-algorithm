#include<iostream>
using namespace std;
int maxprofit(int n,int price[],int dp[])
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int best=0;
    for(int i=1;i<=n;i++)
    {
        int profit=price[i]+maxprofit(n-i,price,dp);
        best=max(best,profit);
    }
    return dp[n]=best;
}
int maxprofitbu(int n,int price[])
{
    int dp[100]={0};
    dp[0]=0;
    for(int len=1;len<=n;len++)
    {
        int best=0;
        for(int cut=1;cut<=len;cut++)
        {
            best=max(best,price[cut]+dp[len-cut]);
        }
        dp[len]=best;
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    int price[100];
  int  dp[100]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>price[i];
    }
    //int ans=maxprofit(n,price,dp);
    int ans=maxprofitbu(n,price);
    cout<<ans;
}
