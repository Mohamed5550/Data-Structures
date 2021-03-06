// You can use this code in any purpose you need without any mention
// Author: Mohamed Hesham
// Email: mohamed.hesham5550@gmail.com

// Implementing Queue with struct
// In the below code I will implement 7 methods related to it
// Create, Push, Pop, Empty, Size, Front and Back

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next = NULL;
};

struct Queue {
    int size = 0;
    Node *front = NULL;
    Node *back = NULL;
};

Queue *create() {
    Queue *tmp = new Queue;
    return tmp;
}

void push(Queue *queue, int x) {
    Node *tmp = new Node;
    tmp->value = x;
    if(queue->back) {
        queue->back->next = tmp;
    }
    queue->back = tmp;
    if(queue->front == NULL) {
        queue->front = queue->back;
    }
    queue->size ++;
}

void pop(Queue *queue) {
    Node *tmp = queue->front->next;
    if(queue->front == queue->back) {
        queue->back = NULL;
    }
    delete queue->front;
    queue->front = tmp;
    queue->size --;
}

bool empty(Queue *queue) {
    return !queue->size;
}

int size(Queue *queue) {
    return queue->size;
}

int front(Queue *queue) {
    return queue->front->value;
}

int back(Queue *queue) {
    return queue->back->value;
}

int main() {

    // some testing
    Queue *myQueue = create();
    push(myQueue, 5);
    push(myQueue, 6);
    push(myQueue, 7);
    push(myQueue, 8);
    cout << size(myQueue) << " " << empty(myQueue) << endl;
    pop(myQueue);
    pop(myQueue);
    push(myQueue, 12);
    cout << front(myQueue) << " " << back(myQueue) << endl;
    pop(myQueue);
    pop(myQueue);
    pop(myQueue);
    cout << size(myQueue) << " " << empty(myQueue) << endl;
}