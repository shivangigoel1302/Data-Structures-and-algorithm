#include<iostream>
using namespace std;

bool ratinamaze(int sol[][10],char maze[][5],int n,int m,int i,int j)
{
    if(i==n-1 &&j==m-1)
    {
        sol[i][j]=1;
        for(int k=0;k<n;k++)
        {
            for(int p=0;p<m;p++)
            {
                cout<<sol[k][p]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
    sol[i][j]=1;
    if(j+1<m && maze[i][j+1]!='X')
    {
        bool kyarightsebaatbani=ratinamaze(sol,maze,n,m,i,j+1);
        if(kyarightsebaatbani==true)
        {
            return true;
        }
    }
    if(i+1<n&& maze[i+1][j]!='X')
    {
        bool kyaneechesebaatbani=ratinamaze(sol,maze,n,m,i+1,j);
        if(kyaneechesebaatbani==true)
        {
            return true;
        }

    }
    sol[i][j]=0;
    return false;
}
int main()
{
    int n,m;
    char maze[][5]={"00XX","0000","00XX","0000"};
    int sol[10][10]={0};
    ratinamaze(sol,maze,4,4,0,0);

}

