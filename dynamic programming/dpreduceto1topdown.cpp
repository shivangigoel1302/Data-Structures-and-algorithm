#include<iostream>
#include<climits>
using namespace std;
int memo[10000];

int reduceno(int n)
{
    int q1=INT_MAX;
    int q2=INT_MAX;
    int q3=INT_MAX;
    if(memo[n]!=-1)
    {
        return memo[n];
    }
    if(n==1)
    {
        return 0;
    }
    if(n%3==0)
    {
        q1=1+reduceno(n/3);
    }
    if(n%2==0)
    {
        q2=1+reduceno(n/2);
    }
    q3=1+reduceno(n-1);
    memo[n]= min(q1,min(q2,q3));
    return memo[n];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        memo[i]=-1;
    }
    int ans=reduceno(n);
    cout<<ans;
}
