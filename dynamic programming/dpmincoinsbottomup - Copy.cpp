#include<bits/stdc++.h>
using namespace std;
int mincoinsbu(int N,int coins[],int T)
{
    int dp[100]={0};
    //dp[0]=0;
    for(int n=1;n<=N;n++)
    {
        dp[n]=INT_MAX;
        for(int t=0;t<T;t++)
        {
            if(n-coins[t]>=0)
            {
                int subprob=dp[n-coins[t]];
                dp[n]=min(dp[n],subprob+1);
            }
        }
    }
    return dp[N];
}
int main()
{
    int n;
    cin>>n;
    int coins[]={1,7,10};
    int T=sizeof(coins)/sizeof(int);
    cout<<mincoinsbu(n,coins,T);
}
