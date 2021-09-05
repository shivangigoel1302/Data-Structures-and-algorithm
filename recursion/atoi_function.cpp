
#include <iostream>
using namespace std;


int calcatoi(string s,int i)
{
    if(i<0)
    {
        return 0;
    }
     int ans=s[i]-'0'+10*calcatoi(s,i-1);
    return ans;
}

int main() {
    string s;
    cin>>s;
    int ans= calcatoi(s,s.size()-1);
    cout<<ans;
}
