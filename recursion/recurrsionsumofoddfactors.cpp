#include<iostream>
using namespace std;
int sumofodd(int n,int i)
{
    if(i>n)
    {
        return 0;
    }
    if(n%i==0)
    {
        if(i%2!=0)
        {
            return i+sumofodd(n,i+1);
        }
    }
    return sumofodd(n,i+1);
}
int main()
{
    int n;
    cin>>n;
    cout<<sumofodd(n,1);
}
