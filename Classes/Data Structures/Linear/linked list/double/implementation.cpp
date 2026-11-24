/*
 Activity 2.1 - Double Linked List
 Description: Implementation of a double linked list with create, read, update and deletion operations.
 Authors: Diego Flores Álvarez (A01788809) & Miguel Tejero de la Fuente (A01788818)
 Delivery date: 16/11/26
*/

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

    /// Inserts a node at the beginning of the list. Time complexity: `O(1)`. Space complexity: `O(1)`.
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

    /// Inserts a node at the end of the list. Time complexity: `O(n)`. Space complexity: `O(1)`.
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

    /// Inserts a node at the given index, from 0 to the list size. Time complexity: `O(n)`. Space complexity: `O(1)`.
    void insert(T data, int index) {
        if (index < 0) {
            cout << "Index does not exist" << endl;
            return;
        }

        if (index == 0) {
            pushFront(data);
            return;
        }

        Node<T> *ptr = head;
        for (int i = 0; i < index - 1 && ptr != nullptr; i++)
            ptr = ptr->next;

        if (ptr == nullptr) {
            cout << "Index does not exist" << endl;
            return;
        }

        if (ptr->next == nullptr) {
            pushBack(data);
            return;
        }

        Node<T> *new_node = new Node(data);
        new_node->next = ptr->next;
        new_node->prev = ptr;
        ptr->next->prev = new_node;
        ptr->next = new_node;
    }

    /// Updates the node's data at the given index. Time complexity: `O(n)`. Space complexity: `O(1)`.
    void update(T data, int index) {
        if (index < 0) {
            cout << "Index does not exist" << endl;
            return;
        }

        Node<T> *ptr = head;
        for (int i = 0; i < index && ptr != nullptr; i++)
            ptr = ptr->next;

        if (ptr == nullptr) {
            cout << "Index does not exist" << endl;
            return;
        }

        ptr->data = data;
    }

    /// Searches for a node and returns whether it exists in the double linked list.
    /// Time complexity: `O(n)`. Space complexity: `O(1)`.
    bool find(T data) {
        if (head == nullptr) return false;

        Node<T> *ptr = head;
        while (ptr != nullptr) {
            if (ptr->data == data) return true;
            ptr = ptr->next;
        }

        return false;
    }

    /// Removes the first node from the list. Time complexity: `O(1)`. Space complexity: `O(1)`.
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

    /// Removes the last node from the list. Time complexity: `O(n)`. Space complexity: `O(1)`.
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

    /// Removes the first node whose value matches the given data. Time complexity: `O(n)`. Space complexity: `O(1)`.
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

    /// Prints the nodes from the beginning to the end of the list. Time complexity: `O(n)`. Space complexity: `O(1)`.
    void printForward() {
        Node<T> *ptr = head;
        cout << "Head <-> ";
        while (ptr != nullptr) {
            cout << ptr->data << " <-> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }

    /// Prints the nodes from the end to the beginning of the list. Time complexity: `O(n)`. Space complexity: `O(1)`.
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
    DoubleLinkedList<char> list;
    int option;
    char value;
    int index;

    do {
        cout << endl << "=== Double Linked List ===" << endl
             << "1. Insert at the beginning" << endl
             << "2. Insert at the end" << endl
             << "3. Insert at a position" << endl
             << "4. Update a position" << endl
             << "5. Search for a value" << endl
             << "6. Remove the first element" << endl
             << "7. Remove the last element" << endl
             << "8. Remove a value" << endl
             << "9. Print from beginning to end" << endl
             << "10. Print from end to beginning" << endl
             << "11. Exit" << endl
             << "Choose an option: ";

        if (!(cin >> option)) {
            cout << "Invalid input. The program will exit." << endl;
            return 1;
        }

        switch (option) {
            case 1:
                cout << "Enter a value: ";
                cin >> value;
                list.pushFront(value);
                break;
            case 2:
                cout << "Enter a value: ";
                cin >> value;
                list.pushBack(value);
                break;
            case 3:
                cout << "Enter a value: ";
                cin >> value;
                cout << "Enter the position: ";
                cin >> index;
                list.insert(value, index);
                break;
            case 4:
                cout << "Enter the new value: ";
                cin >> value;
                cout << "Enter the position to update: ";
                cin >> index;
                list.update(value, index);
                break;
            case 5:
                cout << "Enter the value to search for: ";
                cin >> value;
                if (list.find(value))
                    cout << "Value found." << endl;
                else
                    cout << "Value not found." << endl;
                break;
            case 6:
                list.popFront();
                break;

            case 7:
                list.popBack();
                break;

            case 8:
                cout << "Enter the value to remove: ";
                cin >> value;
                list.erase(value);
                break;
            case 9:
                list.printForward();
                break;
            case 10:
                list.printBackward();
                break;
            case 11:
                cout << "Program ended." << endl;
                break;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    } while (option != 11);

    return 0;
}