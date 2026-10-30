
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node *start = NULL, *ptr, *pptr = NULL;
int val;

// Function to display linked list
void display() {
    ptr = start;

    while (ptr != NULL) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }

    cout << "NULL";
}

// Function to create and insert node at end
void createnode() {
    cout << "Input value to insert: ";
    cin >> val;

    struct node* newnode =
        (struct node*)malloc(sizeof(struct node));

    newnode->data = val;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
    }
    else {
        ptr = start;

        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = newnode;
    }
}

// Function to delete last node using two pointers
void deletelast() {
    if (start == NULL) {
        cout << "List is empty";
    }

    else if (start->next == NULL) {
        ptr = start;
        start = NULL;
        free(ptr);
    }

    else {
        ptr = start;
        pptr = NULL;

        while (ptr->next != NULL) {
            pptr = ptr;
            ptr = ptr->next;
        }

        pptr->next = NULL;
        free(ptr);
    }
}

int main() {
    int n;

    cout << "Number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        createnode();
    }

    cout << "\nExisting linked list is: ";
    display();

    cout << "\nAfter deletion from end: ";
    deletelast();
    display();

    // Free remaining memory
    cout << "\nFree memory\n";

    ptr = start;

    while (ptr != NULL) {
        struct node* nextnode = ptr->next;
        free(ptr);
        ptr = nextnode;
    }

    start = NULL;

    return 0;
}
