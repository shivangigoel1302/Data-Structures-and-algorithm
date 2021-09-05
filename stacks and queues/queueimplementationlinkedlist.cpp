#include <iostream>
using namespace std;

class qnode{
    public:
    int data;
    qnode* next ;
    qnode(int d){
        data = d;
        next = NULL;
    }
};
class queue{
    public:
    qnode* rear;
    qnode*front;
    queue(){
        rear = NULL;
        front = NULL;
    }
    void enqueue(int x){
        qnode* temp = new qnode(x);
        if(rear == NULL){
            rear = temp;
            front = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
        return;
    }

    void dequeue(){
        if(front == NULL){
            return;
        }
        qnode* temp = front;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        delete temp;
    }
};
int main() {
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data;
}
