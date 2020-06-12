#include<iostream>
#include<map>
#include<list>
#include<climits>
#include<queue>
using namespace std;
template<typename T>
class graph
{
   map<T,list<T> >adjlist;
   public:
       void addedge(T u,T v,bool bidir=true)
       {
           adjlist[u].push_back(v);
           if(bidir)
           {
               adjlist[v].push_back(u);
           }
       }
       void sssp(T src)
       {
           queue<T>q;
           map<T,int>dist;
           map<T,T>parent;
           q.push(src);
           for(auto i:adjlist)
           {
               dist[i.first]=INT_MAX;
           }
           dist[src]=0;
           parent[src]=src;

           while(!q.empty())
           {
               T node=q.front();
               cout<<node<<" ";
               q.pop();
               for(int neighbor:adjlist[node])
               {
                   if(dist[neighbor]==INT_MAX)
                   {
                       q.push(neighbor);
                       dist[neighbor]=dist[node]+1;
                       parent[neighbor]=node;
                   }
               }
           }
           cout<<endl;
           for(auto i:adjlist)
           {
               T node=i.first;
               cout<<"dist of"<<node<<" from "<<src<<" is "<<dist[node]<<endl;
           }

       }
};
int main()
{
    graph<int>g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(0,4);
    g.addedge(2,4);
    g.addedge(2,3);
    g.addedge(3,5);
    g.addedge(3,4);
    g.sssp(0);
}
