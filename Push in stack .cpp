#include <iostream>
using namespace std;

int main() {
    int stack[5], top = -1, n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        if (top == 4) {
            cout << "Stack Overflow";
            break;
        }

        cout << "Enter value: ";
        cin >> value;

        top++;
        stack[top] = value;
    }

    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }

    return 0;
}
