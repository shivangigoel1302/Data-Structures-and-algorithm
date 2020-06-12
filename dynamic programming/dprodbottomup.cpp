#include<iostream>
using namespace std;

int maxprofit(int arr[],int totalen)
{
    int dp[100]={};
    for(int len=1;len<=totalen;len++)
    {
        int best=0;
        for(int cut=1;cut<=len;cut++)
        {
            best=max(best,arr[cut]+dp[len-cut]);
        }
        dp[len]=best;
    }
    return dp[totalen];
}

int main()
{
    int totalen;
    cin>>totalen;
    int priceofeachlen[100];
    for(int eachpiece=1;eachpiece<=totalen;eachpiece++)
    {
        cin>>priceofeachlen[eachpiece];
    }
    int ans=maxprofit(priceofeachlen,totalen);
    cout<<ans;
}
