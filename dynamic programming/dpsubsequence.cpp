#include<iostream>
using namespace std;
int list(int arr[],int n)
{
    int dp[100];
    for(int i=0;i<=n;i++)
    {
        dp[i]=1;
    }
    int best=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]<arr[j])
            {
                int curlen=1+dp[j];
                dp[i]=max(curlen,dp[i]);
            }
        }
        best=max(best,dp[i]);
    }
    return best;
}
int main()
{
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=list(arr,n);
    cout<<ans;
}
