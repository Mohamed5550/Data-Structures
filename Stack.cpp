// You can use this code in any purpose you need without any mention
// Author: Mohamed Hesham
// Email: mohamed.hesham5550@gmail.com

// Implementing Stack with struct
// In the below code I will implement 5 methods related to it
// Create, Push, Pop, Empty, Size, Front and Back
// It will be Doubly Linked List

#include <iostream>
using namespace std;

struct Node {
    int value = 0;
    Node *next = NULL;
}

struct Stack {
    int size = 0;
    Node *top = NULL;
}

Stack *create() {
    Stack *tmp = new Stack;
    return tmp;
}

void push() {
    Node *tmp = new Node;

}

int main() {

}