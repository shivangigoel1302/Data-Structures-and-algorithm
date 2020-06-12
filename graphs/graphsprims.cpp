#include<iostream>
#include<list>
using namespace std;
class graph
{
   public:
       int v;
       list< pair<int,int> >adjlist;
       graph(int v)
       {
           this->v=v;
           adjlist=new list<pair<int,int> >[v];
       }
       void addedge(int u,int v,int w)
       {
           adjlist[u].push_back(make_pair(v,w));
           adjlist[v].push_back(make_pair(u,w));
       }
       int findminvertex(int *weight,bool *visited,int v)
       {
           int minvertex=-1;
           for(int i=0;i<v;i++)
           {
             if(!visited[i] &&(minvertex==-1 || weight[i]<weight[minvertex]))
             {
                 minvertex=i;
             }
           }
           return minvertex;
       }
       void prims()
       {
           bool *visited=new bool[v];
           int *parent=new int[v];
           int *weight=new int[v];
           for(int i=0;i<v;i++)
           {
               visited[i]=false;
               weight[i]=INT_MAX;
           }
           parent[0]=-1;
           weight[0]=0;
           for(int i=0;i<v;i++)
           {
               int minvertex=findminvertex(visited,weight,v);
               visited minvertex=true;
               for(auto neighbor:adjlist[minvertex])
               {
                   if(!visited[neighbor.first])
                   {
                       if(weight[neighbor.first]>neighbor.second)
                       {
                           parent[neighbor.first]=minvertex;
                           weight[neighbor.first]=neighbor.second;
                       }
                   }
               }
           }
           for(int i=0;i<v;i++)
           {
               cout<<i<<" "<<parent[i]<<" with weight "<<weight[i]<<endl;
           }
       }
};

int main()
{
    int n,e;
    cin>>n>>e;
    graph g(n);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.addedge(u,v,w);
    }
    g.prims();
}
