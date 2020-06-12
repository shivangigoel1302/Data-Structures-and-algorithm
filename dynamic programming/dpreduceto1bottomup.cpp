#include<iostream>
#include<climits>
using namespace std;
int reduceno(int n)
{
    int dp[10000];
    dp[0]=0; dp[3]=1;
    dp[1]=0; dp[2]=1;
    for(int currnum=4;currnum<=n;currnum++)
    {
        int q1=INT_MAX;
        int q2=INT_MAX;
        int q3=INT_MAX;
        if(currnum%3==0)
        {
            q1=1+dp[currnum/3];
        }
        if(currnum%2==0)
        {
            q2=1+dp[currnum/2];
        }
        q3=1+dp[currnum-1];
        dp[currnum]=min(q1,min(q2,q3));
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int ans=reduceno(n);
    cout<<ans;
}
