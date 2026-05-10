#include <iostream>
using namespace std;
class LinearQueue {
    int front, rear, size;
    int *arr;
public:
    // Constructor
    LinearQueue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    // Enqueue operation
    void enqueue(int value) 
{
        if (rear == size - 1) 
{
            cout << "Queue Overflow\n";
            return;
   }
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = value;
        cout << "Inserted: " << value << endl;
    }
    // Dequeue operation
    void dequeue() 
{
        if (front == -1 || front > rear) 
{
            cout << "Queue Underflow\n";
            return;
   }
        cout << "Deleted: " << arr[front] << endl;
        front++;
        // Reset queue if empty
        if (front > rear) 
{
            front = rear = -1;
   }
  }
    // Display queue
    void display() 
{
        if (front == -1) 
{
            cout << "Queue is Empty\n";
            return;
 }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
 {
            cout << arr[i] << " ";
   }
        cout << endl;
    }
};
int main() {
    int size, choice, value;
    cout << "Enter size of queue: ";
    cin >> size;
    LinearQueue q(size);
    do {
        cout << "\n--- Queue Operations ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
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
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);
    return 0;  }
