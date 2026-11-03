#include <iostream>

using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(T data) {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class LinkedList {
    private:
    Node<T> *head;

    public:
    LinkedList() {
        head = nullptr;
    }

    void pushFront(T data) {
        Node<T> *new_node = new Node(data);
        if (head == nullptr)
            head = new_node;
        else {
            new_node->next = head;
            head = new_node;
        }
    }

    void pushBack(T data) {
        Node<T> *new_node = new Node<T>(data);

        if (head == nullptr)
            head = new_node;
        else {
            Node<T> *ptr = head;
            while (ptr->next != nullptr)
                ptr = ptr->next;
            ptr->next = new_node;
        }
    }

    void insert(T data, int index) {
        Node<T> *new_node = new Node(data);
        if (head == nullptr)
            head = new_node;
        else {
            Node<T> *ptr = head;
            for (int i = 0; i < index-1; i++)
                ptr = ptr->next;
            
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
    }

    bool find(T data) {
        if (head == nullptr) return false;

        Node<T> *ptr = head;
        while (ptr->next != nullptr) {
            if (ptr->data == data) return true;
            ptr = ptr->next;
        }

        return false;
    }

    void popFront() {
        if (head == nullptr)
            cout << "Linked List is empty" << endl;
        else {
            Node<T> *ptr = head;
            head = head->next;
            delete ptr;
        }
    }

    void popBack() {
        if (head == nullptr)
            cout << "Linked List is empty" << endl;
        else {
            Node<T> *ptr = head;
            Node<T> *prev;

            while (ptr->next != nullptr) {
                prev = ptr;
                ptr = ptr->next;
            }

            prev->next = nullptr;
            delete ptr;
        }
    }

    void erase(T data) {
        if (head == nullptr) {
            cout << "Linked List is empty" << endl;
            return;
        }

        Node<T> *ptr = head;
        Node<T> *prev = nullptr;

        while (ptr != nullptr && ptr->data != data) {
            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr == nullptr) {
            cout << "Data not found" << endl;
            return;
        }

        if (prev == nullptr)
            head = head->next;
        else
            prev->next = ptr->next;

        delete ptr;
    }

    void print() {
        Node<T> *ptr = head;
        cout << "Head -> ";
        while (ptr != nullptr) {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList<char> l;
    l.pushBack('B');
    l.pushBack('C');
    l.pushBack('D');
    l.pushBack('E');
    l.pushFront('A');
    l.insert('I', 3);
    l.print();
    l.erase('C');
    l.erase('M');
    l.print();
    l.popBack();
    l.print();
    l.popFront();
    l.print();
    return 0;
}