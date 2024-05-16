#include<iostream>
using namespace std;

class Node{
 public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* CreateNode(){
    cout << "Enter the Value for Node: " << endl;
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    // Step1: Create Node 
    Node* root = new Node(data);

    // Step2: Create Left SubTree 
    cout << "Left of Node: " << root->val << endl;
    root->left = CreateNode();

    //Step3: Create Right SubTree
    cout << "Right of Node: " << root->val << endl; 
    root->right = CreateNode();

    return root; 
}

void preOrderTraversal(Node* root){
    //Base Case
    if(root == NULL) return;        

    //N L R

    //N
    cout << root->val << " ";
    
    //L
    preOrderTraversal(root->left);
    //R
    preOrderTraversal(root->right);

}

void InOrderTraversal(Node* root){
    //Base Case
    if(root == NULL) return;        

    //L N R

    //L
    InOrderTraversal(root->left);

    //N
    cout << root->val << " ";
    
    //R
    InOrderTraversal(root->right);

}

void postOrderTraversal(Node* root){
    //Base Case
    if(root == NULL) return;        

    //L R N
    
    //L
    postOrderTraversal(root->left);
    //R
    postOrderTraversal(root->right);
    //N
    cout << root->val << " ";

}


int main() {

Node* root = CreateNode();
cout << "Printing PreOrder  Traversal: " << endl;
    preOrderTraversal(root);

cout << "InOrder Traversal: " << endl;
    InOrderTraversal(root);

cout << "PostOrder Traversal: " << endl;
    postOrderTraversal(root);

   return 0;
}
