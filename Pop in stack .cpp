#include <iostream>
using namespace std;

int main() {
    int stack[5] = {10, 20, 30};
    int top = 2;

    if (top == -1) {
        cout << "Stack Underflow";
    } else {
        cout << "Popped element: " << stack[top];
        top--;
    }

    cout << "\nStack elements: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }

    return 0;
}
