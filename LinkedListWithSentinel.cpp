// You can use this code in any purpose you need without any mention
// Author: Mohamed Hesham
// Email: mohamed.hesham5550@gmail.com

// Implementing LinkedList with struct
// In the below code I will implement 5 methods related to it
// Create, Insert, Remove, Search and Print
// It will be Circular, Doubly Linked List with a Sentinel

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next = NULL;
    Node* prev = NULL;
};

struct LinkedList {
    Node *sin = new Node;
};

LinkedList* create() {
    LinkedList* temp = new LinkedList;
    temp->sin->next = temp->sin;
    temp->sin->prev = temp->sin;
    return temp;
}

Node* insert(Node* &prev, int x) {
    Node* temp = new Node;
    temp->value = x;
    temp->prev = prev;
    temp->next = prev->next;
    prev->next->prev = temp;
    prev->next = temp;

    return temp;
}

void remove(Node* &item) {
    item->next->prev = item->prev;
    item->prev->next = item->next;
    delete[] item;
}

Node* search(LinkedList* list, int x) {
    Node* it = list->sin;
    while(it->next != list->sin) {
        it = it->next;
        if(it->value == x) return it;
    }

    return NULL;
}

void print(LinkedList* list) {
    Node* it = list->sin;
    while(it->next != list->sin) {
        it = it->next;
        cout << it->value << " ";
    }
    cout << endl;
}

int main() {

    // some testing
    
    // creating the list
    LinkedList *myList = create();
    
    // adding some elements to the list
    Node *i = insert(myList->sin, 6);
    print(myList);
    Node *j = insert(i, 7);
    print(myList);
    Node *k = insert(i, 8);
    print(myList);
    Node *l = insert(j, 9);
    // search for an element
    if(Node *it = search(myList, 8)) {
        insert(it, 10);
    }

    // removing an element
    remove(j);

    // print all the list elements
    print(myList);

}