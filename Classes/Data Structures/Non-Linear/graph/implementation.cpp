#include <iostream>
#include <map>
#include <list>

using namespace std;

template <typename T>
class Graph {
    private:
    map<T, list<T>> mygraph;

    public:
    Graph() {}

    void add_vertex(T v) {
        mygraph[v] = {};
    }

    void add_edge(T v1, T v2) {
        mygraph[v1].push_back(v2);
        mygraph[v2].push_back(v1);
    }

    void print() {
        for (auto &pair : mygraph){
            cout << pair.first << ": ";
            for (T neighbor: pair.second)
                cout << neighbor << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph<int> g;
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);

    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);

    g.print();
}