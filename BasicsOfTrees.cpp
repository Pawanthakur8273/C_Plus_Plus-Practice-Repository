#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }

};
Node* CreateTree(){
  cout << "Enter the Value for Node: " << endl;
  int data;
  cin >> data;
  
  if(data == -1){
    return NULL;
  }

  Node* root = new Node(data);
  root->left = CreateTree();
  root->right = CreateTree();
  return root;
}
void preOrderrTraversal(Node* root){
  
  if(root == NULL){
    return;
  }
  
  // NLR
  cout << root->data << " ";
  preOrderrTraversal(root->left);
  preOrderrTraversal(root->right);
}
void InOrderrTraversal(Node* root){
  
  if(root == NULL){
    return;
  }
  
  // LNR
  InOrderrTraversal(root->left);
  cout << root->data << " ";
  InOrderrTraversal(root->right);
}
void PostOrderrTraversal(Node* root){
  
  if(root == NULL){
    return;
  }
  
  // LRN
  PostOrderrTraversal(root->left);
  PostOrderrTraversal(root->right);
  cout << root->data << " ";
}
void LevelOrderTraversal(Node* root){
  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    Node* front = q.front();
    q.pop();
    if(front == NULL){
      cout << endl;
      if(!q.empty()){
        q.push(NULL);
      }
    }
    else{
      cout << front->data <<" ";
      if(front->left != NULL){
        q.push(front->left);
      }
       if(front->right != NULL){
        q.push(front->right);
      }
    }
  }

}
int MaxDepth(Node* root){
  if(root == NULL){
    return 0;
  }
  int leftHeight = MaxDepth(root->left);
  int rightHeight = MaxDepth(root->right);
  int Height = max(leftHeight, rightHeight) + 1;
  return Height;
}
int Diameter(Node* root){
  if(root == NULL){
    return 0;
  }
  int option1 = Diameter(root->left);
  int option2 = Diameter(root->right);
  int option3 = MaxDepth(root->left) + MaxDepth(root->right);
  int MaxDia = max(option1, max(option2,option3));
  return MaxDia;
}
bool isBalanced(Node* root){
  if(root == NULL){
    return true;
  }

  int leftHeight = MaxDepth(root->left);
  int rightHeight = MaxDepth(root->right);
  int diff = abs(leftHeight - rightHeight);
  bool currAns = (diff <= 1);
  bool leftkaAns = isBalanced(root->left);
  bool rightkaAns = isBalanced(root->right);
  if(leftkaAns && rightkaAns && currAns){
    return true;
  }
  else{
    return false;
  }


}
bool TargetSumPath(Node* root, int targetSum, int sum){
  if(root == NULL){
    return false;
  }
  sum += root->data;
  if(root->left == NULL && root->right == NULL){
    if(sum == targetSum){
      return true;
    }
    else{
      return false;
    }
  }
  bool leftkaAns = TargetSumPath(root->left, targetSum, sum);
  bool rightkaAns = TargetSumPath(root->right, targetSum, sum);
  return leftkaAns || rightkaAns;
}
void TargetSumPathStored(Node* root, int targetSum, int sum, vector<vector<int>> &ans, vector<int> temp){
  if(root == NULL){
    return;
  }
  sum += root->data;
  temp.push_back(root->data);
  if(root->left == NULL && root->right == NULL){
    if(sum == targetSum){
      ans.push_back(temp);
    }
    else{
      return;
    }
  }
  TargetSumPathStored(root->left, targetSum, sum, ans, temp);
  TargetSumPathStored(root->right, targetSum, sum, ans, temp);
}
Node* lowestCommonAncestor(Node* root, int p, int q) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->data == p || root->data == q) {
        return root;
    }

    Node* leftkaAns = lowestCommonAncestor(root->left, p, q);
    Node* rightkaAns = lowestCommonAncestor(root->right, p, q);

    if (leftkaAns != NULL && rightkaAns != NULL) {
        return root;
    }
    
    if (leftkaAns != NULL) {
        return leftkaAns;
    }
    
    if (rightkaAns != NULL) {
        return rightkaAns;
    }

    return NULL;
}

int main(){
  vector<vector<int>> ans;
  vector<int> temp;
  Node* root = CreateTree();
  cout << endl <<"Preorderr Traversal: "<< endl;
  preOrderrTraversal(root);
  cout << endl <<"Inorderr Traversal: "<< endl;
  InOrderrTraversal(root);
  cout << endl <<"Postorderr Traversal: "<< endl;
  PostOrderrTraversal(root);
  cout << endl << "Levelorder Traversal: " << endl;
  LevelOrderTraversal(root);
  cout <<"MaxDepth || Height of BTree: ";
  cout << MaxDepth(root)<< endl;
  cout << "Max Diameter: ";
  cout << Diameter(root);
  cout << endl << "Is Tree Balanced: ";
  cout << isBalanced(root);
  // cout << endl << "Finding Target SumPath: ";
  // cout << TargetSumPath(root, 0, 0);
  cout << endl << "Path of Targeted Sum: " << endl;
  TargetSumPathStored(root, 3, 0, ans, temp);
  for(int i = 0; i < ans.size(); i++){
    for(int j = 0; j < ans[i].size(); j++){
      cout << ans[i][j] <<" ";
    }
  }

  cout << endl << "Finding Lowest Common Ancestor: " << endl;
  Node* temp1 = lowestCommonAncestor(root, 1, 3);
  cout << temp1->data << endl;
 


  return 0;
}
