#include <iostream>
#include <string>
using namespace std;

struct Passenger {
int seat;
string name;
int age;
char gender;
Passenger* next;
};

int seats[30] = {0};
Passenger* head = NULL;

// Book Ticket
void book() {
int i;
for (i = 0; i < 30; i++)
if (seats[i] == 0) break;

if (i == 30) {  
    cout << "No seats available\n";  
    return;  
}  

Passenger* p = new Passenger;  

cout << "Enter name, age and gender: ";  
cin >> p->name >> p->age >> p->gender;  

p->seat = i + 1;  
p->next = head;  
head = p;  
seats[i] = 1;  

cout << "Ticket booked! Seat: " << i + 1 << "\n";

}

// Cancel Ticket
void cancel() {
int n;
cout << "Enter seat number: ";
cin >> n;

if (n < 1 || n > 30 || seats[n - 1] == 0) {  
    cout << "Invalid seat\n";  
    return;  
}  

Passenger *p = head, *prev = NULL;  

while (p != NULL && p->seat != n) {  
    prev = p;  
    p = p->next;  
}  

if (prev == NULL)  
    head = p->next;  
else  
    prev->next = p->next;  

delete p;  
seats[n - 1] = 0;  

cout << "Ticket cancelled\n";

}

// Show Seat Status
void status() {
for (int i = 0; i < 30; i++)
cout << "Seat " << i + 1 << ": "
<< (seats[i] ? "Booked" : "Available") << "\n";
}

// Show Passengers
void passengers() {
Passenger* p = head;

while (p != NULL) {  
    cout << p->seat << " " << p->name << " "  
         << p->age << " " << p->gender << "\n";  
    p = p->next;  
}

}

// Main Function
int main() {
int ch;

do {  
    cout << "\n1.Book Ticket\n2.Cancel Ticket\n";  
    cout << "3.Train Status\n4.Passenger List\n5.Exit\n";  
    cout << "Enter choice: ";  
    cin >> ch;  

    switch (ch) {  
        case 1: book(); break;  
        case 2: cancel(); break;  
        case 3: status(); break;  
        case 4: passengers(); break;  
        case 5: cout << "Exit\n"; break;  
        default: cout << "Invalid choice\n";  
    }  
} while (ch != 5);  

while (head != NULL) {  
    Passenger* p = head;  
    head = head->next;  
    delete p;  
}  

return 0;

}
