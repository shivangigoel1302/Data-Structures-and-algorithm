#include<iostream>
#include<queue>
#include<stack>
using namespace std;
stack<int>s1;
stack<int>s2;
//enque is costly
void push(int x){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

int front(){
    if(s1.empty()){
        cout<<"empty";
        return -1;
    }
    return s1.top();
}

//deque is costly

void insert(int x){
    s1.push(x);
}

int front2(){
   while(s1.size() !=1){
       s2.push(s1.top());
       s1.pop();
   }
   int x = s1.top();
   while(!s2.empty()){
       s1.push(s2.top());
       s2.pop();
   }
   return x;
}
int main(){
    // push(1);
    // push(2);
    // push(3);
  insert(4);
  insert(5);
    cout<<front2();
}
