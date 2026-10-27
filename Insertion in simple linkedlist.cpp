#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node a, b, c;
    a.data = 10;
    b.data = 20;
    a.next = &b;
    b.next = NULL;

    c.data = 30;
    c.next = NULL;
    b.next = &c;

    Node* temp = &a;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
