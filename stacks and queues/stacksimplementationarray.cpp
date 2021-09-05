#include<iostream>
#define MAX 1000
using namespace std;

class stackArray{
   int top;
   public:
       int a[MAX];
       stackArray()
       {
           top = -1;
       }
    //    bool push(int x);
    //    int pop();
    //    int peek();
    //    bool isempty();

       bool push(int x)
{
    if(top >= MAX-1){
        cout<<"stack is full";
        return false;
    }
    else{
        a[++top] = x;
        cout<<"added";
        return true;
    }
}
int pop(){
  if(top < 0){
    cout<<"already empty";
    return -1;
  }
  else{
    cout<<a[top]<<" is popped"<<endl;
    top--;
  }
}
int peek(){
  if(top < 0){
    cout<<"empty";
    return -1;
  }
  else{
    int x = a[top];
    return x;
  }
}
bool isempty(){
  return top < 0;
}
};

int main(){
   stackArray s;
   s.push(5);
   s.push(10);
   cout<<s.peek();
   return 0;
}
