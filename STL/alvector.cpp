// vector हा STL container आहे
// vector dynamic array आहे जो runtime ला grow आणि shrink होऊ शकतो

#include <iostream>
#include <vector>
using namespace std;

// ===============================
// Vector basics
// ===============================
void explainvector() {
    // create vector
    vector<int> v;

    // insert elements
    v.push_back(1);      // {1}
    v.emplace_back(2);  // {1,2}

    cout << "Vector elements:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // vector of pairs
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(3, 4);

    cout << "Vector of pairs:" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].first << " " << vec[i].second << endl;
    }

    // vector with fixed size and same value
    vector<int> v3(5, 100); // {100,100,100,100,100}
    cout << "Vector v3:" << endl;
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;

    // vector with size only (default 0)
    vector<int> v4(5); // {0,0,0,0,0}
    cout << "Vector v4:" << endl;
    for (int i = 0; i < v4.size(); i++) {
        cout << v4[i] << " ";
    }
    cout << endl;

    // copy vector
    vector<int> v5(v3);
    cout << "Copied vector v5:" << endl;
    for (auto x : v5) {
        cout << x << " ";
    }
    cout << endl;
}

// ===============================
// Vector Iterators
// ===============================
void vectoriterator() {
    vector<int> v = {10, 20, 30, 40};

    cout << "Using iterator:" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Using auto iterator:" << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Using range based loop:" << endl;
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;

    // erase single element
    v.erase(v.begin() + 1); // removes 20
    cout << "After erase one element:" << endl;
    for (auto x : v) cout << x << " ";
    cout << endl;

    // erase multiple elements
    v = {10, 20, 30, 40, 50};
    v.erase(v.begin() + 1, v.begin() + 3); // removes 20,30
    cout << "After erase multiple elements:" << endl;
    for (auto x : v) cout << x << " ";
    cout << endl;
}

// ===============================
// Insertion & other operations
// ===============================
void insertion() {
    vector<int> v(2, 50); // {50,50}

    v.insert(v.begin(), 300);       // {300,50,50}
    v.insert(v.begin() + 1, 2, 10); // {300,10,10,50,50}

    cout << "After insertion:" << endl;
    for (auto x : v) cout << x << " ";
    cout << endl;

    cout << "Size of vector: " << v.size() << endl;

    v.pop_back(); // removes last element
    cout << "After pop_back:" << endl;
    for (auto x : v) cout << x << " ";
    cout << endl;

    vector<int> v1 = {10, 20};
    vector<int> v2 = {30, 40};

    v1.swap(v2);
    cout << "After swap v1:" << endl;
    for (auto x : v1) cout << x << " ";
    cout << endl;

    v.clear();
    cout << "Vector empty? " << v.empty() << endl;
}

// ===============================
// Main function
// ===============================
int main() {
    explainvector();
    cout << "------------------" << endl;

    vectoriterator();
    cout << "------------------" << endl;

    insertion();
    return 0;
}