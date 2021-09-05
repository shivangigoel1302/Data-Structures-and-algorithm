#include<bits/stdc++.h>

using namespace std;
void dijkstra(vector<pair<int,int>>adj[], int v,int src){
    vector<int>dist(v,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[src] = 0;
    pq.push({0,src});
    vector<bool>visited(v,false);
    visited[src] = true;
    while(!pq.empty()){
        int x = pq.top().second;
        visited[x] = true;
        pq.pop();
        for(auto nbr: adj[x]){
            int child = nbr.first;
            int val = nbr.second;
            if(visited[child] == false && val + dist[x] < dist[child]){
                dist[child] = val + dist[x];
                pq.push({dist[child],child});
            }
        }
    }
    for(int i = 1; i < v; i++){
        cout<<i<<" "<<dist[i]<<endl;
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
    dijkstra(adj,v,0);
}
