#include<iostream>
#include<vector>
using namespace std;
class heap
{
    vector<int>v;

    bool minheap;

    bool compare(int a,int b)
    {
        if(minheap)
        {
            return a<b;
        }
        else
        {
            return a>b;
        }
    }
public:
    heap(bool type=true)
    {
        minheap=type;
    v.push_back(-1);
    }


    void push(int data)
{
    v.push_back(data);
    int index=v.size()-1;
    int parent=index/2;
    while(index>1 && compare(v[index],v[parent]))
    {
        swap(v[index],v[parent]);
        index=parent;
        parent=parent/2;
    }
}
bool empty()
{
    return v.size()==1;
}
int top()
{
    return v[1];
}

};

int main()
{
    heap h(true);
    h.push(10);
    h.push(8);
    h.push(5);
    h.push(2);
    h.push(3);
    h.push(1);
    h.push(7);
    cout<<h.top()<<endl;
}
