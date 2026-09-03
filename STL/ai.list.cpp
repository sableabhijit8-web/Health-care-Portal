#include <iostream>
#include <list>
using namespace std;

void explainlist() {
    list<int> ls;

    // insert elements
    ls.push_back(2);       // {2}
    ls.emplace_back(4);    // {2,4}
    ls.push_front(5);      // {5,2,4}
    ls.emplace_front(1);   // {1,5,2,4}

    cout << "List elements:" << endl;
    for (auto it : ls) {
        cout << it << " ";
    }
    cout << endl;

    // pop operations
    ls.pop_back();   // removes 4
    ls.pop_front();  // removes 1

    cout << "After pop operations:" << endl;
    for (auto it : ls) {
        cout << it << " ";
    }
    cout << endl;

    // insert at specific position
    auto itr = ls.begin();
    advance(itr, 1); // move iterator to next position
    ls.insert(itr, 10);

    cout << "After insert:" << endl;
    for (auto it : ls) {
        cout << it << " ";
    }
    cout << endl;

    // erase element
    itr = ls.begin();
    ls.erase(itr); // erase first element

    cout << "After erase:" << endl;
    for (auto it : ls) {
        cout << it << " ";
    }
    cout << endl;

    cout << "Size of list: " << ls.size() << endl;

    // clear list
    ls.clear();
    cout << "Is list empty? " << ls.empty() << endl;
}

int main() {
    explainlist();
    return 0;
}