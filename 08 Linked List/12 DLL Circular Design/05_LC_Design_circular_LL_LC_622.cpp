#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue
{
private:

    vector<int> arr;

    int front;
    int rear;
    int size;
    int capacity;

public:
    // Constructor
    MyCircularQueue(int k)
    {
        capacity = k;
        arr.resize(k);

        front = 0;
        rear = -1;
        size = 0;
    }

    // Insert element
    bool enQueue(int value)
    {
        // Queue full
        if (isFull())
        {
            return false;
        }

        // Move rear circularly
        rear = (rear + 1) % capacity;

        // Insert value
        arr[rear] = value;

        size++;

        return true;
    }

    // Remove element
    bool deQueue()
    {
        // Queue empty
        if (isEmpty())
        {
            return false;
        }

        // Move front circularly
        front = (front + 1) % capacity;

        size--;

        return true;
    }

    // Return front element
    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[front];
    }

    // Return rear element
    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[rear];
    }

    // Check empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Check full
    bool isFull()
    {
        return size == capacity;
    }
};

int main()
{
    MyCircularQueue q(5);

    cout << boolalpha;

    cout << "enQueue(10): " << q.enQueue(10) << endl;
    cout << "enQueue(20): " << q.enQueue(20) << endl;
    cout << "enQueue(30): " << q.enQueue(30) << endl;
    cout << "enQueue(40): " << q.enQueue(40) << endl;
    cout << "enQueue(50): " << q.enQueue(50) << endl;

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    cout << "isFull: " << q.isFull() << endl;

    cout << "deQueue(): " << q.deQueue() << endl;
    cout << "deQueue(): " << q.deQueue() << endl;

    cout << "Front after deletion: " << q.Front() << endl;
    cout << "Rear after deletion: " << q.Rear() << endl;

    // Circular insertion
    cout << "enQueue(60): " << q.enQueue(60) << endl;
    cout << "enQueue(70): " << q.enQueue(70) << endl;

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    return 0;
}