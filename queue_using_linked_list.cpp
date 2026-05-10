#include <iostream>
using namespace std;
// Node structure
class Node {
public:
    int data;
    Node* next;
};
// Queue class
class Queue 
{
    Node *front, *rear;
public:
    Queue() {
        front = rear = NULL;
    }
    // Enqueue (Insertion)
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Inserted: " << value << endl;
    }

    // Dequeue (Deletion)
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        cout << "Deleted: " << temp->data << endl;
        front = front->next;
        // If queue becomes empty
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }
    // Display queue
    void display() {
        if (front == NULL) {
            cout << "Queue is Empty\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;   // IMPORTANT: move pointer
        }
        cout << endl;
    }
};
// Main function
int main() {
    Queue q;
    int choice = 0, value;
    while (true) 
    {   // controlled infinite loop with break
        cout << "\n--- Queue Operations ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
           case 4:
                cout << "Exiting program...\n";
                return 0;   // clean exit (prevents infinite loop)
            default:
                cout << "Invalid choice\n";
        } 
    }
}
