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
  if (root->left==NULL){
    root->left = insert(root->left, data);
  }
  else if (root->right==NULL){
    root->right = insert(root->right, data);
  }
  else{
    if(height(root)==1){
    if(root->left!=NULL && root->right!=NULL){
    root->left=insert(root->left,data);}}
    else{
          root->right=insert(root->right,data);}
    }
}
void inOrderTraversal(BSTNode *root){
  if (root == NULL){
    return;
  }
  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}
int height(BSTNode *root){
    if(root->data==NULL){
        return -1;
    }
    else{
        int lh;
        int rh;
        lh=height(root->left);
        rh=height(root->right);
if(lh>=lh-rh){
    return lh=lh+1;
}
else{
   return rh=rh+1;
}

    }
}
int main(){
    BSTNode *root = NULL;
    int a=1;
    while(a>=1){
        cout<<"Enter 1 for insert\nEnter 2 for print\nEnter 3 for delete\nEnter 4 for search";
        cin>>a;
        if(a==1){
            int x;
            cout<<"enter a value\n";
            cin>>x;
            root=insert(root,x);
        }
        else if(a==2){
            inOrderTraversal(root);
        }
        // else if(a==3){
        //     int x;
        //     cout<<"enter a value\n";
        //     cin>>x;
        //     Delete(root,x);
        // }
        //  else if(a==4){
        //      int x;
        //     cout<<"enter a value\n";
        //     cin>>x;
        //     search(root,x);
        // }
    }
    }