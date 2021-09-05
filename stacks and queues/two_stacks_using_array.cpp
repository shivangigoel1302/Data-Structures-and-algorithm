#include<iostream>
#define MAX 1000
using namespace std;

class twostack{
   int top1;
   int top2;
   public:
   int arr[MAX];
    twostack(){
        top1= -1;
        top2 = MAX;
    }
   bool push1(int x){
       if(top1 >= top2){
           cout<<"no space";
           return false;
       }
       arr[++top1] = x;
       return true;
   }

   bool push2(int x){
       if(top1 >= top2){
           cout<<"no space";
           return false;
       }
       arr[--top2] = x;
       return true;
   }

   int pop1(){
       if(top1 < 0){
           cout<<"underflow";
           return -1;
       }
       int x = arr[top1];
       top1--;
       return x;
   }

   int pop2(){
       if(top2 >= MAX){
           cout<<"underflow";
           return -1;
       }
       int x = arr[top2];
       top2++;
       return x;
   }

   int peek1(){
       if(top1 < 0){
           cout<<"underflow";
           return -1;
       }
       return arr[top1];
   }


   int peek2(){
       if(top2 >= MAX){
           cout<<"underflow";
           return -1;
       }
       return arr[top2];
   }


};

int main(){
   twostack s;
   s.push1(30);
   s.push2(40);
   s.push1(45);
   s.push2(66);
   s.pop2();
   cout<<s.peek2();
}
