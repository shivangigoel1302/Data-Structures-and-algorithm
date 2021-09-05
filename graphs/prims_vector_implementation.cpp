#include<bits/stdc++.h>

using namespace std;
void prims(vector<pair<int,int>>adj[], int v){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>key(v+1,INT_MAX);
    vector<bool>ismst(v+1,false);
    vector<int>parent(v,-1);
    parent[0] = 0;
    int src = 0;
    key[0] = 0;
    ismst[0] = true;
    pq.push({0,src});
    while(!pq.empty()){
          int x = pq.top().second;
          pq.pop();
          ismst[x] = true;
          for(auto nbr: adj[x]){
              int child = nbr.first;
              int weight = nbr.second;
              if(ismst[child] == false && weight < key[child]){
                  key[child] = weight;
                  pq.push({weight,child});
                  parent[child] = x;
              }
          }
    }
    for(int i = 1 ; i < v; i++){
        cout<<parent[i]<<" "<<i<<"--"<<key[i]<<endl;
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>>adj[v];
    for(int i = 0 ; i < e; i++){
        int s,d,w;
        cin>>s>>d>>w;
        adj[s].push_back({d,w});
        adj[d].push_back({s,w});
    }
    prims(adj,v);
}
