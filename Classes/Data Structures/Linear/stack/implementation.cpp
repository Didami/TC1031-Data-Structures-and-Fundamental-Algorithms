#include <iostream>
#include <string>
#define max 100

using namespace std;

template <typename T>
class Stack {
    private:
    T stack_arr[max];
    int top;

    public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == (max-1);
    }

    void push(T value) {
        if (isFull()) {
            cout << "The stack is full." << endl;
            return;
        }

        top++;
        stack_arr[top] = value;
    }

    Stack pop() {
        if (isEmpty())
            cout << "The stack is already empty." << endl;
        else
            top--;

        return *this;
    }

    T get_top() {
        if (isEmpty()) { 
            cout << "The stack is empty." << endl;
            return T();
        }

        return stack_arr[top];
    }

    int size() {
        return top+1;
    }
};

int main() {
    Stack <string> s;
    s.push("José");
    s.push("María");
    s.push("Sarah");

    cout << s.size() << endl;
    s.pop();
    cout << "The Top of the stack is: " << s.get_top() << endl;

    return 0;
}