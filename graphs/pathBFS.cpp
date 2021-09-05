#include <iostream>
#include<queue>
#include<list>
#include<set>
#include<map>
using namespace std;
template<typename T>
class graph{
  map<T, list< T > >adjlist;
  public:
  void addEdge(T u, T v , bool bidir = true){
      adjlist[u].push_back(v);
      if( bidir ){
          adjlist[v].push_back(u);
      }
  }
  vector<T> pathv;
  void path(T dest, vector<T>parent){
     if(dest == parent[dest]){

         return;
     }
     pathv.push_back(parent[dest]);
     return path( parent[dest], parent);
  }
  void bfs(T src, T dest){
      queue< int >q;
      set< int >visited;
      vector< T > parent(8);
      for(int i=1;i<8;i++){
       parent[i] = i;
      }
      parent[ src ] = src;
      q.push(src);
      visited.insert(src);
      while( !q.empty() ){
          T node = q.front();
          q.pop();

          for( auto nbr : adjlist[node]){
              if(visited.find(nbr) == visited.end()){
                  q.push(nbr);
                  visited.insert(nbr);
                  parent[ nbr ] = node;
                  if(nbr == dest){
                      pathv.push_back(dest);
                  path(dest, parent);
                  break;
              }
              }
          }
      }
      if(pathv.size() == 0){
          cout<<"NO PATH FOUND"<<endl;
      }
      else{
          for(auto n : pathv){
              cout<<n<<"--";
          }
      }
  }
};
int main() {
    graph<int>g;
 g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(3,4);
    g.addEdge(3,7);
    g.addEdge(4,5);
    g.addEdge(4,6);
    g.addEdge(4,7);
    g.addEdge(3,2);
    g.bfs(3,5);
}
