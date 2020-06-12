#include<iostream>
#include<list>
#include<cstring>
#include<unordered_map>
using namespace std;
class graph
{
    unordered_map<string,list<pair<string,int> > >l;
public:
    void addedge(string x,string y,bool bidir,int w)
    {
        l[x].push_back(make_pair(y,w));
        if(bidir)
        {
            l[y].push_back(make_pair(x,w));
        }
    }
    void print()
    {
        for(auto p:l)
        {
            string city=p.first;
            list<pair<string,int> > nbrs=p.second;
            cout<<city<<"-->";
            for(auto nbr:nbrs)
            {
                int dist=nbr.second;
                string dest=nbr.first;
                cout<<dest<<" "<<dist<<",";
            }
            cout<<endl;
        }
    }
};
int main()
{
    graph g;
    g.addedge("A","B",true,20);
    g.addedge("B","D",true,40);
    g.addedge("A","C",true,10);
    g.addedge("C","D",true,40);
    g.addedge("A","D",false,50);
    g.print();
}
