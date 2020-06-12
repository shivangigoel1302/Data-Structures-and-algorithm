#include<iostream>
#include<map>
#include<list>
using namespace std;
template<typename T>
class graph
{
    map<T,list<T> >l;
public:
    void addedge(T x,T y)
    {
        l[x].push_back(y);
    }
    void dfshelper(T src,map<T,bool>&visited,list<T>&ordering)
    {
        visited[src]=true;
        for(auto nbr:l[src])
        {
            if(!visited[nbr])
            {
                dfshelper(nbr,visited,ordering);
            }
        }
        ordering.push_front(src);
        return;
    }
    void dfs()
    {
        map<T,bool>visited;
        list<T>ordering;
        for(auto nodepair:l)
        {
            T node=nodepair.first;
            visited[node]=false;
        }
        for(auto nodepair:l)
        {
            T node=nodepair.first;
            if(!visited[node])
            {
                dfshelper(node,visited,ordering);
            }
        }
        for(auto node:ordering)
        {
            cout<<node<<endl;
        }
    }
};
int main()
{
    graph<string>g;
    g.addedge("python","datapreprocessing");
    g.addedge("python","pytorch");
    g.addedge("python","ML");
    g.addedge("datapreprocessing","ML");
    g.addedge("pytorch","DL");
    g.addedge("ML","DL");
    g.addedge("DL","facerecogn");
    g.addedge("dataset","facerecogn");
    g.dfs();
}
