// You can use this code in any purpose you need without any mention
// Author: Mohamed Hesham
// Email: mohamed.hesham5550@gmail.com

// Implementing LinkedList with struct
// In the below code I will implement 5 methods related to it
// Create, Insert, Remove, Search and Print
// It will be Doubly Linked List 


#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next = NULL;
    Node* prev = NULL;
};

struct LinkedList {
    Node* head = NULL;
};

LinkedList *create() {
    LinkedList *temp = new LinkedList;
    return temp;
}

Node *insert(Node *&prevItem, int x) {
    Node *temp = new Node;
    temp->value = x;
    temp->prev = prevItem;
    if(prevItem != NULL) {
        temp->next = prevItem->next;
        if(prevItem->next) {
            prevItem->next->prev = temp;
        }
        prevItem->next = temp;
    } else {
        // it is the head        
        prevItem = temp;
    }

    return temp;
}

void remove(Node *&item) {
    if(item->next) {
        item->next->prev = item->prev;
    }
    Node* temp1 = item->next;
    Node* temp2 = item->prev;
    delete[] item;
    if(temp2 != NULL) {
        temp2->next = temp1;
    } else {
        temp2 = temp1;
    }

}

Node *search(LinkedList *list, int x) {
    Node *it = list->head;
    if(it == NULL) return NULL;
    while(it->next != NULL) {
        it = it->next;
        if(it->value == x) return it;
    }

    return NULL;
}

void print(LinkedList *list) {
    Node *it = list->head;
    if(!it) return;
    while(it != NULL) {
        cout << it->value << " ";
        it = it->next;
    }
    cout << endl;
}

int main() {

    // some testing
    
    // creating the list
    LinkedList *myList = create();
    
    // adding some elements to the list
    Node *i = insert(myList->head, 6);
    Node *j = insert(i, 7);
    Node *k = insert(i, 8);
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