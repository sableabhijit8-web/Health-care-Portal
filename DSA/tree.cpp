#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
       int data;
       node* left;
       node* right;

node(int d){
    this->data = d;
    this->left = NULL;
    this->right = NULL;
}
};
node*  buildTree(node* root){
    cout<<"enter the data : "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }
    cout<<"enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTravesal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            // purana level pyra travels ho chuka hai
            cout<<endl;
            if(!q.empty()){
                // queue still have some child node
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data <<" ";
            if(temp -> left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}
void inorder(node* root){
    // base case
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
     // base case
    if(root == NULL){
        return;
    }
    
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}
void postorder(node* root){
     // base case
    if(root == NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

    void buildFormLevelOrder(node* &root){
    queue<node*> q;
    cout<<"enter data for root" << endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for:"<<root->data <<endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1 ){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for:"<<root->data <<endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1 ){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }

}


int main(){
    node* root  = NULL;

    // creating  a tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    cout<<"mayala zal na rao"<< endl;
    levelOrderTravesal(root);

    cout<< "inorder element" << endl;
    inorder(root);

    cout<< "preorder element" << endl;
    preorder(root);

    cout<< "postorder element" << endl;
    postorder(root);

    buildFormLevelOrder(root);
}

