//Insertion and deletion at beginning, end and any specific position in Single linked list. 
#include <iostream>
using namespace std;
// Node structure
class Node {
public:
    int data;
    Node* next;
};
// Linked List class
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }
    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        head = newNode;
        cout << "Inserted at beginning\n";
    }
    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted at end\n";
    }
    // Insert at position
    void insertAtPosition(int value, int pos) {
        Node* newNode = new Node();
        newNode->data = value;
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted at position " << pos << endl;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Invalid position\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted at position " << pos << endl;
    }
    // Delete from beginning
    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted from beginning\n";
    }
    // Delete from end
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Deleted from end\n";
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
        cout << "Deleted from end\n";
    }
    // Delete at position
    void deleteAtPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (pos == 1) {
            deleteAtBeginning();
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        for (int i = 1; i < pos && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Invalid position\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "Deleted from position " << pos << endl;
    }
    // Display list
    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty\n";
            return;
        }
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function
int main() {
    LinkedList list;
    int choice, value, pos;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                list.insertAtPosition(value, pos);
                break;

            case 4:
                list.deleteAtBeginning();
                break;
            case 5:
                list.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                list.deleteAtPosition(pos);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 8);
    return 0;
}
