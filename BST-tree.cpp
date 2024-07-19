#include <iostream>
#include <stdlib.h>
using namespace std;

struct BSTNode{
  int data;
  BSTNode *left;
  BSTNode *right;
};

BSTNode *insert(BSTNode *root, int data){
  if (root == NULL){
    BSTNode *node =new BSTNode;
    node->data = data;
    node->left = node->right = NULL;
    return node;
  }
  if (data < root->data){
    root->left = insert(root->left, data);
  }
  else if (data > root->data){
    root->right = insert(root->right, data);
  }
  return root;
}

// Search
void search(BSTNode *root, int toSearch){
  if (root == NULL)
  {
   cout<<"not found\n";
  }
  if (toSearch == root->data){
    cout<<"found\n";
  }
  if (toSearch < root->data){
    search(root->left, toSearch);
  }
  else if (toSearch > root->data){
    search(root->right, toSearch);
  }
}

// In Order Traversal
void inOrderTraversal(BSTNode *root){
  if (root == NULL){
    return;
  }
  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

// Pre Order Traversial
void preOrderTraversal(BSTNode *root){
  if (root == NULL){
    return;
  }
  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

// Post Order Traversial
void postOrderTraversal(BSTNode *root){
  if (root == NULL){
    return;
  }
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->data << " ";
}

BSTNode *min(BSTNode *root){
  if (root == NULL){
    return NULL;
  }
  if (root->left == NULL){
    return root;
  }
  min(root->left);
}

BSTNode *max(BSTNode *root){
  if (root == NULL){
    return NULL;
  }
  if (root->right == NULL){
    return root;
  }
  max(root->right);
}

BSTNode *deleteNode(BSTNode *root, int toDelete){
  if (root == NULL){
    cout << "Value not Found !" << endl;
    return root;
  }
  if (toDelete < root->data){
    root->left = deleteNode(root->left, toDelete);
  }
  else if (toDelete > root->data)
  {
    root->right = deleteNode(root->right, toDelete);
  }
  else{
    if (root->left == NULL){
      BSTNode *tmp = root->right;
      free(root);
      cout << "Deleted Successfully " << endl;
      return tmp;
    }
    if (root->right == NULL){
      BSTNode *tmp = root->left;
      free(root);
      cout << "Deleted Successfully " << endl;
      return tmp;
    }
    BSTNode *maxNode = max(root->left);
    root->data = maxNode->data;
    root->right = deleteNode(root->left, maxNode->data);
  }
}

int main(){
  BSTNode *root = NULL;

  int a=1;
  while(a<9){
    cout << "Enter 1 to Insert a value\nEnter 2 to Search a value\nenter 3 to print In Order Traversial\nEnter 4 to print PreOrder Traversial\nEnter 5 to Print Post Order Traversial\nEnter 6 to find Minimum Node\nEnter 7 to Find Maximum Node\nEnter 8 to Delete a Node\nEnter 9 to Quit " << endl;
    cin >> a;
    if (a == 1){
      int data;
      cout << "Enter value to Insert : ";
      cin >> data;
      root = insert(root, data);
    }
    else if (a == 2){
      int toSearch;
      cout << "Enter value to Search for : ";
      cin >> toSearch;
       search(root, toSearch);
    }
    else if (a == 3){
      inOrderTraversal(root);
      cout << endl;
    }
    else if (a == 4){
      preOrderTraversal(root);
      cout << endl;
    }
    else if (a == 5){
      postOrderTraversal(root);
      cout << endl;
    }
    else if (a == 6){
      BSTNode *minNode = min(root);
      if (minNode == NULL)
      {
        cout << "Tree is Empty" << endl;
      }
      else
      {
        cout << minNode->data << endl;
      }
    }
    else if (a == 7){
      BSTNode *maxNode = max(root);
      if (maxNode == NULL)
      {
        cout << "Tree is Empty" << endl;
      }
      else
      {
        cout << maxNode->data << endl;
      }
    }
    else if (a == 8){
      int toDelete;
      cout << "Enter value you want to Delete : ";
      cin >> toDelete;
      root = deleteNode(root, toDelete);
    }
    else if (a == 9){
      cout << "Quit Successfully!!!" << endl;
    }
    else
    {
      cout << "Invalid Number!!! " << endl;
    }
  }
}