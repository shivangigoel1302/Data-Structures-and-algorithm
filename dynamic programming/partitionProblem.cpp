#include <iostream>
using namespace std;
bool part(int a[], int n ){
    int sum = 0;
    for(int i=0 ; i < n ; i++){
        sum+=a[i];
    }
    if(sum%2!=0){
        return false;
    }
    bool dp[n+1][sum/2+1];
    for(int i=0 ; i <= n ; i++){
        dp[i][0] = true;
    }
    for(int i=1; i < sum/2+1 ; i++){
        dp[0][i] = false;
    }
    for(int i = 1 ; i < n+1 ; i++){
        for(int j = 1; j < sum/2 + 1 ; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= a[i-1]){
                dp[i][j] =dp[i][j] || dp[i-1][j-a[i-1]];
            }
        }
    }
    for(int i = 0 ; i < n+1; i++){
        for(int j = 0 ; j < sum/2 +1 ; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][sum/2];
}
int main() {
   int n;
   cin>>n;
   int a[100];
   for(int i = 0 ; i < n ; i++){
       cin>>a[i];
   }
   if(part(a,n)){
       cout<<"YES"<<endl;
   }
   else{
       cout<<"NO"<<endl;
   }
}
