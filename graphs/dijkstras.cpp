#include<iostream>
#include<map>
#include<list>
#include<set>
#include<climits>
using namespace std;
template<typename T>
class graph{
  map<T,list<pair<T,int>>>m;
  public:
      void addedge(T u, T v, int w,bool bidir = true){
        m[u].push_back(make_pair(v,w));
        if(bidir){
            m[v].push_back(make_pair(u,w));
        }
      }
      void dijkstras(T src){
         set<pair<int,T>>s;
         map<T,int>dist;
         for(auto i: m){
            dist[i.first] = INT_MAX;
         }
         dist[src] = 0;
         s.insert({0,src});
         while(!s.empty()){
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            for( auto child : m[node] ){
                if(nodeDist + child.second < dist[child.first]){
                    T dest = child.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f != s.end()){
                        s.erase(f);
                    }
                    dist[dest] = nodeDist + child.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
         }
         for(auto d: dist){
            cout<<d.first<<" "<<d.second<<endl;
         }
      }
};
int main(){
graph<int>g;
g.addedge(1,2,5);
g.addedge(1,3,2);
g.addedge(2,3,-10);
//g.addedge(3,4,2);
//g.addedge(1,4,7);
g.dijkstras(1);
}

