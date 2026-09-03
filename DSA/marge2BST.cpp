#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Inorder traversal → Sorted array
void inorder(Node* root, vector<int>& arr) {
    if (root == NULL) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Build balanced BST from sorted array
Node* buildBST(vector<int>& arr, int st, int en) {
    if (st > en) return NULL;

    int mid = st + (en - st) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildBST(arr, st, mid - 1);
    root->right = buildBST(arr, mid + 1, en);

    return root;
}

// Merge two sorted arrays
vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
    vector<int> temp;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(b[j++]);
    }

    while (i < a.size()) temp.push_back(a[i++]);
    while (j < b.size()) temp.push_back(b[j++]);

    return temp;
}

// Merge two BSTs
Node* merge2BST(Node* root1, Node* root2) {
    vector<int> arr1, arr2;

    inorder(root1, arr1);
    inorder(root2, arr2);

    vector<int> merged = mergeArrays(arr1, arr2);

    return buildBST(merged, 0, merged.size() - 1);
}

// Insert node in BST
Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

int main() {
    vector<int> arr1 = {8, 2, 11, 10};
    vector<int> arr2 = {5, 3, 0};

    Node* root1 = NULL;
    Node* root2 = NULL;

    // Build BST 1
    for (int x : arr1) root1 = insertBST(root1, x);

    // Build BST 2
    for (int x : arr2) root2 = insertBST(root2, x);

    // Merge both BSTs
    Node* root = merge2BST(root1, root2);

    // Final inorder → sorted merged output
    vector<int> seq;
    inorder(root, seq);

    for (int v : seq)
        cout << v << " ";
    cout << endl;

    return 0;
}
