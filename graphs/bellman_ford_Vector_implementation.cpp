#include <bits/stdc++.h>
using namespace std;
void addedge(vector<pair<int,int>>adj[],int u,int v,int w){
    adj[u].push_back({v,w});
}
void bellman(vector<pair<int,int>>adj[],int v){
        vector<int>dist(v,INT_MAX);
        dist[0] = 0;
        for(int i = 0; i < v-1; i++){
            for(int j = 0; j < v; j++){
                for(auto nbr: adj[j]){
                    if(dist[j] != INT_MAX && dist[j] + nbr.second < dist[nbr.first]){
                        dist[nbr.first] = dist[j] + nbr.second;
                    }
                }
            }
        }
         for(int j = 0; j < v; j++){
                for(auto nbr: adj[j]){
                    if(dist[j] != INT_MAX && dist[j] + nbr.second < dist[nbr.first]){
                        cout<<"NEGATIVE WEIGHT EXISTS"<<endl;
                    }
             }
        }
        for(int i = 0 ; i< v; i++){
            cout<<i<<"-> "<<dist[i]<<endl;
        }

}
int main() {
    int v;
    cin>>v;
    vector<pair<int,int>>adj[v];
    addedge(adj,0,1,-1);
    addedge(adj,0,2,4);
    addedge(adj,1,2,3);
    addedge(adj,1,3,2);
    addedge(adj,1,4,2);
    addedge(adj,3,2,5);
    addedge(adj,3,1,1);
    addedge(adj,4,3,-3);
    bellman(adj,v);
}
