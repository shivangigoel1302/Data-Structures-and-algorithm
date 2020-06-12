#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;
class graph
{
    list<int>*l;
    int V;
public:
    graph(int V)
    {
        this->V=V;
        l=new list<int>[V];
    }
    void addedge(int x,int y)
    {
        l[x].push_back(y);
    }
    bool istree()
    {
        bool *visited=new bool[V];
        int *parent=new int[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
            parent[i]=i;
        }
        queue<int>q;
        int src=0;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int nbr:l[node])
            {
                if(visited[nbr]==true&&parent[node]!=nbr)
                {
                    return false;
                }
                else if(!visited[nbr])
                {
                    visited[nbr]=true;
                    parent[nbr]=node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }
};
int main()
{
    graph g(4);
    g.addedge(0,1);
    g.addedge(3,2);
    g.addedge(1,2);
    //g.addedge(0,3);
    if(g.istree()){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}
