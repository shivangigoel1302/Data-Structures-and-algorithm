#include<iostream>
#include<map>
#include<list>
#include<climits>
#include<queue>
using namespace std;
template<typename T>
class graph
{
    map<T,list<T> >l;
public:
    void addedge(int x,int y)
    {
        l[x].push_back(y);
    }
    void bfs(int src,int dest)
    {
        queue<T>q;
        map<int,int>dist;
        map<T,T>parent;
        for(auto nodepair:l)
        {
            T node=nodepair.first;
            dist[node]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        parent[src]=src;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            for(int nbr:l[node])
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr]=dist[node]+1;
                    parent[nbr]=node;
                }
            }
        }
       cout<<dist[dest]<<endl;
       T temp=dest;
       while(temp!=src)
       {
           cout<<temp<<"<--";
           temp=parent[temp];
       }
       cout<<src<<endl;

    }
};
using namespace std;
int main()
{
    int board[50];
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;
    graph<int>g;
    for(int i=0;i<36;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int j=i+dice;
            j+=board[j];
            if(j<=36)
            {
                g.addedge(i,j);
            }
        }
    }
    g.addedge(36,36);
   g.bfs(0,36);
}
