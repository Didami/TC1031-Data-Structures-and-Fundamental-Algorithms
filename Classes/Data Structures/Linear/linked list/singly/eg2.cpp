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

    // Replace element at index 2 (from 10 to 25000)
    advance(ptr, 2);
    *ptr = 25000;

    cout << "Head -> ";
    for (ptr = l.begin(); ptr != l.end(); ptr++)
        cout << *ptr << " -> ";
    cout << "NULL" << endl;
    return 0;
}