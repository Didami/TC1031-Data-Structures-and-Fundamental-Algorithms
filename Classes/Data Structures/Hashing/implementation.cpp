#include <iostream>
#include <list>
#include <functional>
#include <string>

using namespace std;

template <typename T>
class Hashing {
    private:
    int buckets;
    list<T> *table;

    public:
    Hashing() {
        buckets = 0;
        table = nullptr;
    }

    Hashing(int buckets) {
        this->buckets = buckets;
        table = new list<T>[this->buckets];
    }

    void insert(T key) {
        int index = hash<T>()(key) % buckets;
        table[index].push_back(key);
    }

    void print() {
        for (int i = 0; i < buckets; i++) {
            cout << "Bucket [" << i << "]: ";
            for (auto j: table[i])
                cout << j << "->";
            cout << "NULL" << endl;
        }
    }

    ~Hashing() {
        delete [] table;
    }
};

int main() {
    Hashing<string> h(10);
    h.insert("Mexico");
    h.insert("USA");
    h.insert("Panama");
    h.insert("Canada");
    h.print();
    return 0;
}