// You can use this code in any purpose you need without any mention
// Author: Mohamed Hesham
// Email: mohamed.hesham5550@gmail.com

// Implementing Stack with struct
// In the below code I will implement 6 methods related to it
// Create, Push, Pop, Empty, Size, Top

#include <iostream>
using namespace std;

struct Node {
    int value = 0;
    Node *prev = NULL;
};

struct Stack {
    int size = 0;
    Node *top = NULL;
};

Stack *create() {
    Stack *tmp = new Stack;
    return tmp;
}

void push(Stack *stack, int x) {
    Node *tmp = new Node;
    tmp->value = x;
    tmp->prev = stack->top;
    stack->top = tmp;
    stack->size ++;
}

void pop(Stack *stack) {
    Node *tmp = stack->top->prev;
    delete stack->top;
    stack->top = tmp;
    stack->size --;
}

bool empty(Stack *stack) {
    return !stack->size;
}

int size(Stack *stack) {
    return stack->size;
}

int top(Stack *stack) {
    return stack->top->value;
}

int main() {

    // some testing 
    Stack *myStack = create();
    push(myStack, 5);
    push(myStack, 6);
    push(myStack, 7);
    cout << "top: " << top(myStack) << endl;
    pop(myStack);
    cout << "top: " << top(myStack) << endl;
    cout << "size: " << size(myStack) << endl;
    pop(myStack);
    pop(myStack);
    cout << "size: " << size(myStack) << " , empty: " << empty(myStack) << endl;
    push(myStack, 10);
    cout << top(myStack);
}