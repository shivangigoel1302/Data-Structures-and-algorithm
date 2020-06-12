#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;
template<typename T>
class graph
{
    map<T,list<T,pair<T,int> > >adjlist;
public:
    void addedge(T u,T v,int dist,bool bidir=true)
    {
        adjlist[u].push_back(make_pair(v,dist));
        if(bidir)
        {
            adjlist[v].push_back(make_pair(u,dist));
        }
    }
    void print()
    {
        for(auto i:adjlist)
        {
            cout<<i.first<<"-->";
            for(auto l:i.second)
            {
                cout<"("<<l.first<<"-"<<l.second<<")";
            }
            cout<<endl;
        }
    }
    void dijsktrasssp(T src)
    {
       unordered_map<T,int>dist;
       for(auto i:adjlist)
       {
           dist[i.first]=INT_MAX;
       }
       set<pair<int,T> >s;
       dist[src]=0;
       s.insert(make_pair(0,src));
       while(!s.empty())
       {
           auto p=*s.begin();
           int nodedist=p.first;
           T node=p.second;
           s.erase();
           for(auto neighbor:adjlist[node])
           {
                if(nodedist+neighbor.second<dist[neighbor.first])

                T dest=neighbor.first;
                    auto f=s.find(make_pair(dist[dest],dest));
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }
                    dist[dest]=nodedist+neighbor.second;
                    s.insert(make_pair(dist[dest],dest));
                }
           }
       }
       for(auto d:dist)
       {
           cout<<d.first<<" is located at a distace of "<<d.second<<endl;
       }
    }
};
int main()
{
    /*
    graph<string>india;
    india.addedge("amritsar","delhi",1);
    india.addedge("amritsar","jaipur",4);
    india.addedge("jaipur","delhi",2);
    india.addedge("jaipur","mumbai",8);
    india.addedge("bhopal","agra",2);
    india.addedge("mumbai","bhopal",3);
    india.addedge("agra","delhi",1);
    g.print();
    */

    graph<int>g;
    g.addedge(1,2,1);
    g.addedge(1,3,4);
    g.addedge(2,3,1);
    g.addedge(3,4,2);
    g.addedge(1,4,7);
   g.dijsktrasssp(1);

}
