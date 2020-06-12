#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
int main()
{
    priority_queue<int,vector<int>, greater<int> >pq;
    int a[100]={5,13,23,4,6,7};
    for(int i=0;i<6;i++)
    {
        pq.push(a[i]);
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}
