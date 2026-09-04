#include <iostream>
#include <vector>

using namespace std;

void print(vector <char> & vec) {
    for (char x: vec) {
        cout << x << " ";
        cout << endl;
    }
}

vector <char> read(int size) {
    vector <char> n;
    char item;
    for (int i = 0; i < size; i++) {
        cout << "Enter the element at index " << i << ": "; 
        cin >> item;
        n.push_back(item);
    }

    return n;
}

int main() {
    vector <char> c = {'A', 'B', 'C', 'D'}; // size: 4
    c.push_back('E'); // increases capacity to 4 * 2 = 8

    cout << "Vector's size is: " << c.size() << endl;
    cout << "Vector's capacity is: " << c.capacity() << endl;

    cout << c.front() << endl;

    return 0;
}