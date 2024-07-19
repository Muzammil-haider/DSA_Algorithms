#include <iostream>
using namespace std;
struct Bnode{
    int value;
    Bnode *right;
    Bnode *left;
};



Bnode *Insert(Bnode *root,int data){
    if(root==NULL){
        Bnode *ptr = new Bnode;
        ptr->value=data;
        ptr->left=NULL;
        ptr->right=NULL;
        return ptr;
   }
  
    if(root->value>data){
        root->left=Insert(root->left,data);
        

    }
    else if(root->value<data){
        root->right=Insert(root->right,data);
        
    }

   
   return root;
}

void inOrderTraversal(Bnode *root){
  if (root == NULL){
    return;
  }
  inOrderTraversal(root->left);
  cout << root->value << " ";
  inOrderTraversal(root->right);
}
void postOrderTraversal(Bnode *root){
  if (root == NULL){
    return;
  }
  postOrderTraversal(root->left);
  
  postOrderTraversal(root->right);

  cout << root->value << " ";
}
void preOrderTraversal(Bnode *root){
  if (root == NULL){
    return;
  }

    cout << root->value << " ";
  preOrderTraversal(root->left);

  preOrderTraversal(root->right);
}
 void search(Bnode *root, int data){
    if(root==NULL){
        cout<<"not found"<<endl;
    }
    else if(root->value<data){
        search(root->right,data);
    }
    else if(root->value>data){
        search(root->left,data);
    }
    else{
        cout<<"found"<<endl;
    }
 }
 int min(Bnode *root){
    if(root->left=NULL){
        return root->value;
    }
    else{
        min(root->left);
    }
    return 0;
 }
  int max(Bnode *root){
    if(root->right=NULL){
        return root->value;
    }
    else{
        max(root->right);
    }
    return 0;
 }
 Bnode *Delete(Bnode *root,int todelete){
    if(root==NULL){
        cout<<"not found"<<endl;
    }
    else if(root->value<todelete){
        root->right=Delete(root->right,todelete);
    }
    else if(root->value>todelete){
        root->left=Delete(root->left,todelete);
    }
    else{
        if(root->left==NULL){
            return root->right;
            free(root);
        }
        else if(root->right==NULL){
            return root->left;
            free(root);
        }
        else{
            int a =max(root->left);
            root->value=a;
            Delete(root->left,a);
        }
    }
    return root;
 }

int main(){
    Bnode *root = NULL;
    int a=1;
    while(a>=1){
        cout<<"Enter 1 for insert\nEnter 2 for print\nEnter 3 for delete\nEnter 4 for search";
        cin>>a;
        if(a==1){
            int x;
            cout<<"enter a value\n";
            cin>>x;
            root=Insert(root,x);
        }
        else if(a==2){
            inOrderTraversal(root);
        }
        else if(a==3){
            int x;
            cout<<"enter a value\n";
            cin>>x;
            Delete(root,x);
        }
         else if(a==4){
             int x;
            cout<<"enter a value\n";
            cin>>x;
            search(root,x);
        }
    }
    }

