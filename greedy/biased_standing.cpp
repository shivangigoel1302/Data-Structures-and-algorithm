#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int main() {
   int t;
   cin>>t;
   int a[100000]={0};
   while(t>0){
       memset(a,0,sizeof a);
       int n,rank;
       string name;
       cin>>n;
       for(int i=1;i<=n;i++)
       {
           cin>>name>>rank;
           a[rank]++;
       }
       int actualrank=1;
       int sum=0;
       for(int i=1;i<=n;i++)
       {
            while(a[i])
            {
                 sum+=abs(actualrank-i);
                actualrank++;
                a[i]--;
            }
       }
        cout<<sum<<" ";
       t--;
   }

}
