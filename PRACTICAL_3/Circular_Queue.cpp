

#include <iostream>
using namespace std;

class Circular_Queue {
public:
    static const int SIZE = 5;
    int queue[SIZE];

    int front;
    int rear;

    Circular_Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int val) {
        if ((rear + 1) % SIZE == front) {
            cout << "The Queue is full!" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        queue[rear] = val;
    }

    void dequeue() {
        if (front == -1) {
            cout << "The Queue is Empty" << endl;
            return;
        }

        int val = queue[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (front == -1) {
            cout << "The Queue is Empty" << endl;
            return;
        }

        cout << "Queue : ";

        int i = front;

        while (true) {
            cout << queue[i] << " ";

            if (i == rear) {
                break;
            }

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

int main() {

    Circular_Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    queue.display();

    queue.dequeue();
    queue.dequeue();

    queue.display();

    return 0;
}
