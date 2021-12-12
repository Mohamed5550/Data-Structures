// You can use this code in any purpose you need without any mention
// Author: Mohamed Hesham
// Email: mohamed.hesham5550@gmail.com

// Implementing LinkedList with struct
// In the below code I will implement 5 methods related to it
// Create, Insert, Remove, Search and Print
// It will be Doubly Linked List 


#include <iostream>
using namespace std;

struct LinkedList {
    int value;
    LinkedList* next = NULL;
    LinkedList* prev = NULL;
};

LinkedList *create() {
    LinkedList *head = new LinkedList;
    return head;
}

LinkedList *insert(LinkedList *&prevItem, int x) {
    LinkedList *temp = new LinkedList;
    temp->value = x;
    temp->prev = prevItem;
    if(prevItem->next) {
        temp->next = prevItem->next;
        prevItem->next->prev = temp;
    }
    prevItem->next = temp;

    return temp;
}

void remove(LinkedList *&item) {
    if(item->next) {
        item->next->prev = item->prev;
    }
    item->prev->next = item->next;

    delete[] item;
}

LinkedList *search(LinkedList *head, int x) {
    LinkedList *it = head;
    while(it->next != NULL) {
        it = it->next;
        if(it->value == x) return it;
    }

    return NULL;
}

void print(LinkedList *head) {
    LinkedList *it = head;
    while(it->next != NULL) {
        it = it->next;
        cout << it->value << endl;
    }
}

int main() {
    
    // creating the list
    LinkedList *myList = create();
    
    // adding some elements to the list
    LinkedList *i = insert(myList, 6);
    LinkedList *j = insert(i, 7);
    LinkedList *k = insert(i, 8);
    LinkedList *l = insert(j, 9);
    
    // search for an element
    if(LinkedList *it = search(myList, 8)) {
        insert(it, 10);
    }

    // removing an element
    remove(j);

    // print all the list elements
    print(myList);
}