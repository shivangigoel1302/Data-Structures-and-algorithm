#include<iostream>
#include<map>
#include<list>
using namespace std;
template<typename T>
class graph
{
    map<T,list<T> > adjlist;
public:
    graph()
    {

    }
    void addedge(T u,T v, bool bidir=true)
    {
        adjlist[u].push_back(v);
        if(bidir)
        {
            adjlist[v].push_back(u);
        }
    }
    void printadjlist()
    {
        for(auto i: adjlist)
        {
            cout<<i.first<<"->";
            for(auto entry:i.second)
            {
                cout<<entry<<",";
            }
            cout<<endl;
        }
    }

};
int main()
{
    graph<string>g;
    g.addedge("putin","trump",false);
    g.addedge("putin","modi",false);
    g.addedge("putin","pope",false);
    g.addedge("modi","trump",true);
    g.addedge("modi","yogi",true);
    g.addedge("yogi","prabhu",false);
    g.addedge("prabhu","modi",false);
    g.printadjlist();
}
