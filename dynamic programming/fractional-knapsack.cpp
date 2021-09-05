#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
bool compare(pair<int,int>a, pair<int,int>b){
    double r1= a.first/a.second;
    double r2 = a.first/a.second;
    return r1>r2;
}
int fractionalKnapsack(vector<pair<int,int>>container, int n,int w){
   sort(container.begin(),container.end(),compare);
   int currweight=0;
   double finalvalue=0;
   for (int i = 0 ; i < n ; i++){
       if(currweight + container[i].second <= w){
            currweight += container[i].second;
            finalvalue += container[i].first;
       }
       else{
           int remain = w - currweight;
           finalvalue += (double(remain)/container[i].second )*container[i].first ;
       }
   }
   return finalvalue;
}
int main(){
    int n,w;
    cin>>n>>w;
    vector<pair<int,int>>container;
    for(int i = 0 ; i < n ; i++){
        int v, W;
        cin>>v>>W;
        container.push_back({v,W});
    }
    cout<<fractionalKnapsack(container,n,w);
}
