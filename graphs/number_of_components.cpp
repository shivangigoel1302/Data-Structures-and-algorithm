#include <iostream>
#include<set>
#include<map>
#include<vector>
#include<list>
using namespace std;
template<typename T>
class graph{
  map<T,list<T>>adjlist;
  public:
  void addEdge(T u , T v , bool bidir =  true){
      adjlist[u].push_back(v);
      if( bidir ){
          adjlist[v].push_back(u);
      }
  }
  void dfsHelper(T src, set<int >&visited){
       visited.insert( src );
       for( auto nbr : adjlist[src]){
           if(visited.find( nbr ) == visited.end()){
               dfsHelper( nbr, visited);
           }
       }
  }
  void dfs( T src){
      set< int > visited;
      dfsHelper(src, visited);
      int componentCount = 1;
      vector< int >component;
      component.push_back(src);
      for( auto node : adjlist){
          if(visited.find(node.first) == visited.end()){
              componentCount++;
              component.push_back(node.first);
              dfsHelper(node.first , visited);
          }
      }
      cout<<"number of components are "<<componentCount<<endl;
      for(int i = 0; i < component.size() ; i++){
          cout<<component[i]<<" ";
      }
  }
};
int main() {
    graph<int>g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(1, 4);
    g.addEdge(5, 7);
    g.addEdge(6, 8);
    g.addEdge(8, 9);
    g.dfs(1);

}
