#include<iostream>
using namespace std;
class stackNode{
    public:
    int data;
    stackNode* next;
    stackNode(int d){
        data = d;
        next = NULL;
    }
};
void push(stackNode* &head, int d){
    if(head == NULL){
        stackNode* s = new stackNode(d);
       // cout<<s->data;
      head = s;
        return ;
    }
    stackNode* s = new stackNode(d);
    s->next = head;
    head = s;
    //cout<<head->data;
    return ;
}
bool isempty(stackNode* head){
    if(head == NULL){
        return true;
    }
    return false;
}

stackNode* peek(stackNode* head){
         if(head) return head;
         return NULL;
}

stackNode* pop(stackNode* &head){
    stackNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}
int main(){
    stackNode* head = NULL;
   push(head,10);
   push(head,30);
   pop(head);
   push(head,40);
   push(head,50);
   cout<<isempty(head)<<" ";
   cout<<peek(head)->data;
}
