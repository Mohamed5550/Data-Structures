// You can use this code in any purpose you need without any mention
// Author: Mohamed Hesham
// Email: mohamed.hesham5550@gmail.com

// Implementing Binary Search Tree with struct
// In the below code I will implement 6 methods related to it
// Create, Insert, Search, Delete, successor, predecessor, 

#include <iostream>
using namespace std;

int queue[6];
int tail = 0;
int head = -1;

void enqueue (int q[], int x) {
    if(tail == head) cout << "overflow";
    else {
        if(head == -1) head = tail;
        queue[tail] = x;
        tail = (tail + 1) % 6;
    }
}

void dequeue (int q[]) {
    if(head == -1) cout << "underflow";
    else {
        cout << q[head];
        head = (head + 1) % 6;
        if(head == tail) {
            head = -1;
        }
    }
}

int main() {
    enqueue(queue, 1);
    enqueue(queue, 1);
    enqueue(queue, 1);
    enqueue(queue, 1);
    enqueue(queue, 1);
    enqueue(queue, 1);
    enqueue(queue, 1);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    
}