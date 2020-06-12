#include<iostream>
using namespace std;
int memo[100];
int maxprofit(int arr[],int totalen)
{
 if(totalen==0)
 {
     return 0;
 }
 if(memo[totalen]!=-1)
 {
     return memo[totalen];
 }
 int best=0;
 for(int len=1;len<=totalen;len++)
 {
     int netprofit =arr[len]+maxprofit(arr,totalen-len);
     best=max(best,netprofit);
 }
 memo[totalen]=best;
 return best;
}

int main()
{
    int priceofeachlen[100];
    int totalen;
    cin>>totalen;
    for(int eachpiece=1;eachpiece<=totalen;eachpiece++)
    {
        cin>>priceofeachlen[eachpiece];
    }
    for(int i=0;i<=totalen;i++)
    {
        memo[i]=-1;
    }
    int ans=maxprofit(priceofeachlen,totalen);
    cout<<ans;
}
