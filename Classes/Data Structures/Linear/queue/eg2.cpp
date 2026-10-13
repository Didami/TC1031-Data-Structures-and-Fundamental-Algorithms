#include <iostream>
#include <queue>
#include <time.h>
#include <iomanip>

using namespace std;

class KFC {
    private:
    int order_id;
    string order;
    float price;

    public:
    KFC() {}

    KFC(string order, float price) {
        this->order = order;
        this->price = price;
        order_id = rand() % 500+1;
    }

    void design() {
        cout << "ID  | Order             | Price    " << endl;
    }

    void print() {
        cout  << setw(6) << left << order_id << setw(20) << left << order << setw(5) << left << price << endl;
    }
};

int main() {
    srand(time(0));

    queue<KFC> q;
    KFC order1("Chicken wings", 300);
    q.push(order1);
    KFC order2("Chicken strips", 500);
    q.push(order2);
    KFC order3("Chicken nuggets", 100);
    q.push(order3);

    cout << "The queue size is: " << q.size() << endl;

    KFC temp;
    temp = q.front();
    temp.design();

    while (!q.empty()) {
        q.front().print();
        q.pop();
    }

    return 0;
}