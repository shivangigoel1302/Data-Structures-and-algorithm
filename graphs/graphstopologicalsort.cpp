#include<iostream>
#include<map>
#include<list>
#include<queue>
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
    void dfshelper(T node,map<T,bool> &visited,list<T> &ordering)
    {
        visited[node]=true;
        for(auto neighbor:adjlist[node])
        {
            if(!visited[neighbor])
            {
                dfshelper(neighbor,visited,ordering);
            }
        }
        ordering.push_front(node);
    }

    void dfstopological()
    {
        map<T,bool>visited;
        list<T>ordering;
        for(auto i:adjlist)
        {
            T node=i.first;
            if(!visited[node])
            {
                dfshelper(node,visited,ordering);
            }
        }
        for(T element:ordering)
        {
            cout<<element<<"-->";
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
    g.dfstopological();

}
