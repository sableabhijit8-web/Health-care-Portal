// it stores everything in sorted order
// and stores only unique elements

#include <iostream>
#include <set>
using namespace std;

void explainset() {
    set<int> st;

    st.insert(1);   // {1}
    st.emplace(2);  // {1,2}
    st.insert(2);   // duplicate ignored
    st.insert(4);   // {1,2,4}
    st.insert(3);   // {1,2,3,4}

    // find & erase element 3
    auto it = st.find(3);
    if (it != st.end()) {
        st.erase(it);
    }

    // find element not present (safe check)
    auto itx = st.find(6);
    if (itx != st.end()) {
        st.erase(itx);
    }

    // count
    int cnt = st.count(1);
    cout << "Count of 1: " << cnt << endl;

    // range erase [2,4)
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2);

    // print set
    for (auto x : st) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    explainset();
    return 0;
}