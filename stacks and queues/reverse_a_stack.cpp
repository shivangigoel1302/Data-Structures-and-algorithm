#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom(int x,stack<int>&s){
    if(s.empty()){
        s.push(x);
        return;
    }
    else{
        int a = s.top();
        s.pop();
        insert_at_bottom(x,s);
        s.push(a);
    }
}

void reverse(stack<int>&s){
    if(s.size() > 0){
        int x = s.top();
        s.pop();
        reverse(s);

        insert_at_bottom(x,s);
    }
}
int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);


    cout<<endl;
    reverse(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
