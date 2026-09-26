#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque
{
private:
    vector<int> arr;

    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k)
    {
        capacity = k;
        arr.resize(k);

        front = 0;
        rear = -1;
        size = 0;
    }

    // Insert element at front
    bool insertFront(int value)
    {
        if (isFull())
        {
            return false;
        }

        // If deque is empty
        if (isEmpty())
        {
            front = 0;
            rear = 0;

            arr[front] = value;
        }
        else
        {
            // Move front backward circularly
            front = (front - 1 + capacity) % capacity;

            arr[front] = value;
        }

        size++;

        return true;
    }

    // Insert element at rear
    bool insertLast(int value)
    {
        if (isFull())
        {
            return false;
        }

        // If deque is empty
        if (isEmpty())
        {
            front = 0;
            rear = 0;

            arr[rear] = value;
        }
        else
        {
            // Move rear forward circularly
            rear = (rear + 1) % capacity;

            arr[rear] = value;
        }

        size++;

        return true;
    }

    // Delete element from front
    bool deleteFront()
    {
        if (isEmpty())
        {
            return false;
        }

        front = (front + 1) % capacity;

        size--;

        return true;
    }

    // Delete element from rear
    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }

        rear = (rear - 1 + capacity) % capacity;

        size--;

        return true;
    }

    // Get front element
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[front];
    }

    // Get rear element
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};

int main()
{
    MyCircularDeque deque(5);

    cout << boolalpha;

    cout << "insertLast(10): "
         << deque.insertLast(10) << endl;

    cout << "insertLast(20): "
         << deque.insertLast(20) << endl;

    cout << "insertLast(30): "
         << deque.insertLast(30) << endl;

    cout << "insertFront(5): "
         << deque.insertFront(5) << endl;

    cout << "insertFront(1): "
         << deque.insertFront(1) << endl;

    cout << "Front: "
         << deque.getFront() << endl;

    cout << "Rear: "
         << deque.getRear() << endl;

    cout << "deleteFront(): "
         << deque.deleteFront() << endl;

    cout << "Front after delete: "
         << deque.getFront() << endl;

    cout << "deleteLast(): "
         << deque.deleteLast() << endl;

    cout << "Rear after delete: "
         << deque.getRear() << endl;

    return 0;
}