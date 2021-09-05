#include <bits/stdc++.h>
using namespace std;

void warshall(int graph[][4]){
    int dist[4][4];
    int v = 4;
    for(int i = 0 ;  i< v; i++){
        for(int j = 0 ; j < v ;j++){
            dist[i][j] = graph[i][j];
        }
    }
    for(int k = 0 ; k < v; k++){
        for(int i = 0 ; i < v; i++){
            for(int j = 0; j < v; j++){
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i = 0 ; i < v; i++){
        for(int j = 0 ;j < v; j++){
            if(dist[i][j] == INT_MAX){
                cout<<"INF"<<" ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main() {

    int graph[4][4] = { {0, 5, INT_MAX, 10},
                        {INT_MAX, 0, 3, INT_MAX},
                        {INT_MAX, INT_MAX, 0, 1},
                        {INT_MAX, INT_MAX, INT_MAX, 0}
                    };
    warshall(graph);
}
