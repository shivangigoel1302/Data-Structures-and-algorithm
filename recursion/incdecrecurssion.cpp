#include<iostream>
using namespace std;
void printnum(int a)
{
    if(a==0)
    {
        return;
    }
    //cout<<a<<" ";
    printnum(a-1);
    cout<<a<<" ";
}


int main()
{
    int n;
    cin>>n;
    printnum(n);
    return 0;
}
