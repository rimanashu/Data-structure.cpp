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
    c.data = 30;

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    int key;
    cout << "Enter value: ";
    cin >> key;

    Node* temp = &a;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found";
            return 0;
        }
        temp = temp->next;
    }

    cout << "Not Found";
    return 0;
}
