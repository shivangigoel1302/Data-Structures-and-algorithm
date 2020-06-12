#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;
int main()
{
    unordered_map<string,vector<string> > phonebook;
    phonebook("rahul").push_back("910");
    phonebook("rahul").push_back("920");
    phonebook("jakal").push_back("310");
    phonebook("kajal").push_back("340");
    phonebook("kajal").push_back("320");
    for(auto p:phonebook)
    {
        cout<<"name" <<p.first<<"->";
        for(auto n:p.second)
        {
            cout<<n<<",";
        }
        cout<<endl;
    }
