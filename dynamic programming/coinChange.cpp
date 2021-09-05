#include<iostream>
using namespace std;
int ways(int v[], int n,int value){
    int dp[n+1][value+1];
    for(int i = 0 ; i < n+1; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i < value+1 ; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i < n+1 ; i++){
        for(int j = 1 ; j < value+1 ; j++){
            dp[i][j] = dp[i-1][j];
            if(v[i-1] <= j){
                dp[i][j] += dp[i][j- v[i-1]];
            }
        }
    }
    return dp[n][value];
}
int main(){
    int value,n;
    cin>>n>>value;
    int v[100];
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }
    cout<<ways(v,n,value);
}
