//Insertion and Deletion at beginning, end and any specific position in Doubly linked list. 
#include <iostream>
using namespace std;
// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* head = NULL;
// Create node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
// Insert at beginning
void insertAtStart(int data) {
    Node* newNode = createNode(data);
    if (head != NULL) {
        head->prev = newNode;
        newNode->next = head;
    }
    head = newNode;
}
// Insert at end
void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
// Insert at position
void insertAtPosition(int data, int pos) {
    if (pos == 1) {
        insertAtStart(data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Invalid Position\n";
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete from beginning
void deleteFromStart() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}
// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    if (temp->next == NULL) {
        delete temp;
        head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    delete temp;
}
// Delete from position
void deleteFromPosition(int pos) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    if (pos == 1) {
        deleteFromStart();
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Invalid Position\n";
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    delete temp;
}
// Display forward
void displayForward() {
    Node* temp = head;
    cout << "Forward: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
// Display backward
void displayBackward() {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    cout << "Backward: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}
// Main function with switch-case
int main() {
    int choice, data, pos;
    do {
        cout << "\n===== Doubly Linked List Menu =====\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Start\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                insertAtStart(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                insertAtEnd(data);
                break;
            case 3:
                cout << "Enter data and position: ";
                cin >> data >> pos;
                insertAtPosition(data, pos);
                break;
            case 4:
                deleteFromStart();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deleteFromPosition(pos);
                break;
            case 7:
                displayForward();
                break;
            case 8:
                displayBackward();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 9);
    return 0;
}
