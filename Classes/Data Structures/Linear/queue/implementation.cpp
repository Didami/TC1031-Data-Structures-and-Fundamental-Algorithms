#include <iostream>
#define max 100

using namespace std;

template <typename T>
class Queue {
    private:
    T queue_arr[max];
    int front;
    int rear;

    public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return rear == max-1;
    }

    void enqueue(T value) {
        if (isFull()) {
            cout << "The queue is full." << endl;
            return;
        }

        if (isEmpty())
            front = 0;

        rear++;
        queue_arr[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "The queue is empty." << endl;
            return;
        }

        front++;
    }

    T Front() {
        if (isEmpty())
            return T();
        return queue_arr[front];
    }

    T Rear() {
        if (isEmpty())
            return T();
        return queue_arr[rear];
    }

    int size() {
        if (isEmpty())
            return 0;
        return rear - front + 1;
    }
};

int main() {
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(100);

    // q.dequeue();

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;
    cout << "Size: " << q.size() << endl;

    while (!q.isEmpty()) {
        cout << q.Front() << " ";
        q.dequeue();
    }

    return 0;
}