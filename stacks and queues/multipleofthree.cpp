#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
bool multiple(int arr[], int n){
    queue<int>q0;
    queue<int>q2;
    queue<int>q1;
    int sum = 0;
    sort(arr,arr+n);
    for(int i = 0 ; i < n ; i++){
        sum+=arr[i];
        if(arr[i] %3 == 0){
            q0.push(arr[i]);
        }
        else if(arr[i] %3 == 1){
            q1.push(arr[i]);
        }
        else{
            q2.push(arr[i]);
        }
    }
    if(sum%3 == 1){
           if(!q1.empty()){
               q1.pop();
           }
           else{
               if(!q2.empty()){
                   q2.pop();
               }
               else{
                   return false;
               }
               if(!q2.empty()){
                   q2.pop();
               }
               else{
                   return false;
               }
           }
    }


    if(sum%3 == 2){
           if(!q2.empty()){
               q2.pop();
           }
           else{
               if(!q1.empty()){
                   q1.pop();
               }
               else{
                   return false;
               }
               if(!q1.empty()){
                   q1.pop();
               }
               else{
                   return false;
               }
           }
    }
vector<int>v(n);
int top = 0;
while(!q0.empty()){
    v[top++]= q0.front();
    q0.pop();
}
while(!q1.empty()){
    v[top++] = q1.front();
    q1.pop();
}
    while(!q2.empty()){
        v[top++] = q2.front();
        q2.pop();
    }
    sort(v.begin(),v.end()+top,greater<int>());
    for(int i =0; i< top; i++){
        cout<<v[i]<<" ";
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i = 0 ; i  < n ; i++){
        cin>>arr[i];
    }
    multiple(arr,n);
}
