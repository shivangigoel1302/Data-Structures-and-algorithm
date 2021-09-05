#include<iostream>
#include<map>
#include<list>
#include<cmath>
#include<algorithm>
using namespace std;
class edge{
    public:
    int src;
    int dest;
    int weight;
};
bool compare( edge e1, edge e2){
   return e1.weight < e2.weight;
}
int parentNumber(int v, int * parent){
if(parent[v] == v){
    return v;
 }
return parentNumber(parent[v], parent);
}
void kruskal(edge* input, int n, int e){
  sort(input, input + e, compare);
  edge *output = new edge[n-1];
  int *parent = new int[n];
  for(int i=0; i< n; i++){
      parent[i] = i;
  }
  int count = 0;
  int i = 0;
  while( count < n-1){
    edge currentEdge = input[i];
    int sourceParent = parentNumber(input[i].src, parent);
    int destParent = parentNumber(input[i].dest, parent);
    if(sourceParent != destParent){
        output[count] = currentEdge;
        count++;
        parent[sourceParent] = destParent;
    }
    i++;
  }
  for( int k = 0; k < n-1 ; k++){
    cout<<output[k].src<<" "<<output[k].dest<<" "<<output[k].weight<<endl;
  }
}
int main(){
    int n,e;
    cin>>n>>e;
    edge *input = new edge[e];
    for(int i=0; i<e; i++){
        int s, d, w;
        cin>>s>>d>>w;
        input[i].src = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    kruskal(input, n, e);
}
