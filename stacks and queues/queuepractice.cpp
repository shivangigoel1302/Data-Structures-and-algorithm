#include<iostream>
#include<queue>
using namespace std;
void reverse(queue<int>&q)
{
    if(q.empty())
    {
        return;
    }
    int firstelement=q.front();
    q.pop();
    reverse(q);
    q.push(firstelement);
}
void print(queue<int>q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main()
{
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    print(q);
    cout<<endl<<endl;
    reverse(q);
    print(q);
}
