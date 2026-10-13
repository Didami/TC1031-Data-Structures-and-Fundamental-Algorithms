#include <iostream>
#include <queue>

using namespace std;

void print(queue<int> &q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(25);
    q.push(20);

    cout << q.size() << endl;
    cout << "Front: " << q.front() << endl;
    cout << "Rear: " << q.back() << endl;

    print(q);
}