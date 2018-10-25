#include<iostream>
using namespace std;
#define MAX_CAP 3
class Deque{
    int front, rear, size, capacity;

    int *array = NULL;

public:

    Deque(){
        array = new int[MAX_CAP];
        front = 0;
        rear = 0;
        size = 0;
        capacity = MAX_CAP;
    }

    void enqueue(int data){
        if(size == capacity){
            cout<<"Overflow\n";
            return;
        }

        else{
            if(size == 0){
                array[front] = data;
                rear = front;
                size = size+1;
            }
            else{
                rear = (rear+1)%capacity;
                array[rear] = data;
                size = size+1;

            }
        }
    }


    void dequeue(){
        if(size == 0){
            cout<<"Underflow\n";
            return;
        }

        else{
            array[front] = 0;
            front = (front+1)%capacity;
            size = size-1;
        }
    }

    void show(){
        if(size==0){
            return;
        }
        for(int i=front; i<=rear; ++i){
            cout<<array[i]<<" ";

        }
        cout<<endl;
    }


};



int main(){
    Deque q;
    //q.show();
    //q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();
    q.enqueue(3);

    //q.show();
    //q.dequeue();
    q.show();
}
