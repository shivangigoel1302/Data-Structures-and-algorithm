#include<iostream>
#include<list>
using namespace std;
class graph
{
    int V;
    list<int>*l;
public:
    graph(int V)
    {
        this->V=V;
        l=new list<int>[V];
    }
    void addedge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void print()
    {
        for(int i=0;i<V;i++)
        {
            cout<<"vertex"<<i<<"-->";
            for(int nbr:l[i])
            {
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }
};
int main()
{
    graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(2,3);
    g.addedge(1,2);
    g.print();
}
