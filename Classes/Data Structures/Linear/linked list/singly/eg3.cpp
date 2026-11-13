#include <iostream>
#include <list>

using namespace std;

void separate_grades(list<int> &g, list<int> &p, list<int> &f) {
    list<int>::iterator ptr;
    for (ptr = g.begin(); ptr != g.end(); ptr++) {
        if (*ptr >= 70)
            p.push_back(*ptr);
        else
            f.push_back(*ptr);
    }
}

void print(list<int> &l) {
    list<int>::iterator ptr;
    cout << "Head -> ";
    for (ptr = l.begin(); ptr != l.end(); ptr++)
        cout << *ptr << " -> ";
    cout << "NULL" << endl;
}

int main() {
    list<int> grades = {100, 80, 55, 40, 90, 95, 22, 70, 75, 60};
    list<int> passed_list;
    list<int> failed_list;

    separate_grades(grades, passed_list, failed_list);

    cout << "Grades List: ";
    print(grades);
    cout << "Passed List: ";
    print(passed_list);
    cout << "Failed List: ";
    print(failed_list);

    return 0;
}