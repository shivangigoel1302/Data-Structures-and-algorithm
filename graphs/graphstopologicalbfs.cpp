#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;

template<typename T>
class graph
{
    map<T,list<T> >adjlist;
public:
    graph()
    {

    }
    void addedge(T u,T v,bool bidir=true)
    {
        adjlist[u].push_back(v);
        if(bidir)
        {
            adjlist[v].push_back(u);
        }
    }
    void topologicalbfs()
    {
        queue<T>q;
        map<T,bool>visited;
        map<T,int>indegree;
        for(auto i:adjlist)
        {
            T node=i.first;
            visited[node]=false;
            indegree[node]=0;
        }
        for(auto i:adjlist)
        {
            T u=i.first;
            for(auto v:adjlist[u])
            {
                indegree[v]++;
            }
        }
        for(auto i:adjlist)
        {
            T node=i.first;
            if(indegree[node]==0)
            {
                q.push(node);
            }
        }
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            cout<<node<<"-->";
            for(auto neighbor:adjlist[node])
            {
                indegree[neighbor]--;
                if(indegree[neighbor]==0)
                {
                    q.push(neighbor);
                }
            }
        }
    }
};
int main()
{
    graph<string>g;
    g.addedge("english","programming logic",false);
    g.addedge("maths","programming logic",false);
    g.addedge("programming logic","html",false);
    g.addedge("programming logic","python",false);
    g.addedge("programming logic","java",false);
    g.addedge("programming logic","JS",false);
    g.addedge("python","web dev",false);
    g.addedge("html","css",false);
    g.addedge("css","JS",false);
    g.addedge("JS","web dev",false);
    g.addedge("java","web dev",false);
    g.addedge("python","web dev",false);
    g.dfstopologicalbfs();

}
