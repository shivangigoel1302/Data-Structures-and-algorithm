#include<iostream>
using namespace std;

int odd(int n)
{
    if (n==0)
    {
        return 0;
    }
    else if(n%2==1)
    {
        cout<<n<<endl;;
    }
    odd(n-1);

}
int even (int n)
{
    if(n==0)
    {
        return 0;
    }

    even(n-1);
     if(n%2==0)
    {
        cout<<n<<endl;;
    }
}





int main()
{
    int n;
    cin>>n;
    odd(n);
    even(n);


}
