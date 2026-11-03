#include <iostream>
#include <list>

using namespace std;

int main() {
    // Declare list and add elements
    list<int> l;
    l.push_front(5);
    l.push_back(10);
    l.push_back(15);
    l.push_back(20);
    l.push_front(3);

    // Declare iterator ptr at beginning of the list
    list<int>::iterator ptr = l.begin();

    // Insert an element
    // -50 at 2
    advance(ptr, 2);
    l.insert(ptr, -50);

    // Replace an element
    *ptr = 25000;

    cout << "Head -> ";
    for (ptr = l.begin(); ptr != l.end(); ptr++)
        cout << *ptr << " -> ";
    cout << "NULL" << endl;

    // Accessing an element
    cout << "Front -> " << l.front() << endl;
    cout << "Back -> " << l.back() << endl;
    cout << "The data of the fourth node is: " << *next(l.begin(), 3) << endl;

    // Find a node
    list<int>::iterator ptr2 = find(l.begin(), l.end(), 15);
    if (ptr2 != l.end())
        cout << "The node is found: " << *ptr2 << endl;
    else
        cout << "The node is not found." << endl;
    
    return 0;
}