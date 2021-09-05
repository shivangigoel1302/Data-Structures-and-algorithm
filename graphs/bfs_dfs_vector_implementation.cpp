#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void bfs(vector<int>adj[],int v){
    vector<bool>visited(v,false);
    int src = 0;
    queue<int>q;
    q.push(src);
    cout<<src<<" ";
    visited[src] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto nbr: adj[x]){
            if(!visited[nbr]){
                cout<<nbr<<" ";
                visited[nbr] = true;
                q.push(nbr);
            }
        }
        cout<<endl;
    }
    return;
}
void dfshelper(vector<bool>&visited,int src,vector<int>adj[]){
    cout<<src<<" ";
    visited[src] = true;
    for(auto nbr: adj[src]){
        if(!visited[src]){
            dfshelper(visited,nbr,adj);
        }
    }
    return;
}
void dfs(vector<int>adj[], int v){
   vector<bool>visited(v,false);
   for(int i = 0 ; i < v; i++){
       if(!visited[i]){
           dfshelper(visited,i,adj);
       }
   }
   return;
}
int main() {
    int v;
    cin>>v;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,4,1);
    addEdge(adj,2,4);
    addEdge(adj,3,1);
    dfs(adj,v);
}
