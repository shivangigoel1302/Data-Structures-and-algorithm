#include <iostream>
using namespace std;
int knapsack(int w , int weight[] , int value[], int n){
    if(n==0 || w==0){
        return 0;
    }
    if(weight[n] > w){
        return knapsack(w, weight, value, n-1);
    }
    return max(value[n] + knapsack(w-weight[n],weight, value, n-1), knapsack(w,weight, value, n-1) );
}
int main() {
    int n,w;
    cin>>n>>w;
    int weight[100];
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    int value[100];
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    cout<<knapsack(w,weight, value , n);
}
