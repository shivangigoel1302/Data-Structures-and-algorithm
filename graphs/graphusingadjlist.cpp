#include<iostream>
#include<list>
using namespace std;

class graph
{
    int V;
    list<int> *l;
public:
    graph(int v)
    {
        V=v;
        l=new list<int>[V];
    }
    void addedge(int v,int u,bool bidir=true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
    }
    void printedge()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            for(int vertex: l[i])
            {
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }
};
int main()
{
    graph g(5);
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(4,3);
    g.addedge(0,1);
    g.addedge(1,4);
    g.addedge(1,2);
    g.addedge(2,3);

    g.printedge();
    return 0;
}
