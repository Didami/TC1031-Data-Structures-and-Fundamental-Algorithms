#include <iostream>

using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node() {
        data = T();
        next = nullptr;
        prev = nullptr;
    }

    Node(T data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>

class DoubleLinkedList {
    private:
    Node<T> *head;

    public:
    DoubleLinkedList() {
        head = nullptr;
    }

    void pushFront(T data) {
        Node<T> *new_node = new Node(data);
        if (head == nullptr)
            head = new_node;
        else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void pushBack(T data) {
        Node<T> *new_node = new Node(data);
        if (head == nullptr)
            pushFront(data);
        else {
            Node<T> *ptr = head;
            while (ptr->next != nullptr)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->prev = ptr;
        }
    }

    void insert(T data, int index) {
        Node<T> *new_node = new Node(data);
        if (head == nullptr)
            pushFront(data);
        else {
            Node<T> *ptr = head;
            for (int i = 0; i < index-1; i++)
                ptr = ptr->next;
            new_node->next = ptr->next;
            new_node->prev = ptr;
            ptr->next->prev = new_node;
            ptr->next = new_node;
        }
    }

    bool find(T data) {
        if (head == nullptr) return false;

        Node<T> *ptr = head;
        while (ptr != nullptr) {
            if (ptr->data == data) return true;
            ptr = ptr->next;
        }

        return false;
    }

    void popFront() {
        if (head == nullptr)
            cout << "Linked List is empty" << endl;
        else {
            Node<T>* old_head = head;
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete old_head;
        }
    }

    void popBack() {
        if (head == nullptr)
            cout << "Linked List is empty" << endl;
        else if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node<T> *ptr = head;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->prev->next = nullptr;
            delete ptr;
        }
    }

    void erase(T data) {
        if (head == nullptr) {
            cout << "Linked List is empty" << endl;
            return;
        }

        Node<T>* ptr = head;
        while (ptr != nullptr && ptr->data != data)
            ptr = ptr->next;

        if (ptr == nullptr) {
            cout << "Data not found" << endl;
            return;
        }

        if (ptr->prev != nullptr)
            ptr->prev->next = ptr->next;
        else
            head = ptr->next;
        
        if (ptr->next != nullptr)
            ptr->next->prev = ptr->prev;
        
        delete ptr;
    }

    void printForward() {
        Node<T> *ptr = head;
        cout << "Head <-> ";
        while (ptr != nullptr) {
            cout << ptr->data << " <-> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }

    void printBackward() {
        if (head == nullptr) {
            cout << "NULL <-> HEAD" << endl;
            return;
        }
        
        Node<T>* ptr = head;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        
        cout << "NULL <-> ";
        while (ptr != nullptr) {
            cout << ptr->data << " <-> ";
            ptr = ptr->prev;
        }
        cout << "HEAD" << endl;
    }
};

int main() {
    DoubleLinkedList<char> l;
    l.pushBack('B');
    l.pushBack('C');
    l.pushBack('D');
    l.pushBack('E');
    l.pushFront('A');
    l.insert('I', 3);
    l.printForward();
    l.printBackward();
    cout << l.find('F') << endl;
    l.popFront();
    l.popFront();
    l.printForward();
    cout << l.find('B') << endl;
    l.popBack();
    l.printForward();
    cout << l.find('D') << endl;
    l.erase('I');
    l.printForward();
    cout << l.find('I') << endl;
    return 0;
}