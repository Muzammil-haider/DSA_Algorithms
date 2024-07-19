#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct Node{
  char value;
  Node *left;
  Node *right;
};
struct stack{
    Node *address;
    stack *next;
};
stack *head=NULL;
void push(Node* node) {
        stack* newNode = new stack;
        newNode->address=node ;
        newNode->next = head; // Link the new node to the previous top node
        head = newNode; 
}



Node* pop() {
    if (head == NULL) {
        cout << "Stack underflow" << endl;
        return 0; 
    }
    
    Node* temp=head->address;
    stack* curr= head;
    head = head->next;
    free(curr);
    return temp ;
    
}

void inOrderTraversal(Node *root){
  if (root == NULL){
    return;
  }
  inOrderTraversal(root->left);
  cout << root->value << " ";
  inOrderTraversal(root->right);
}
void postOrderTraversal(Node *root){
  if (root == NULL){
    return;
  }
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->value << " ";
}

int main(){
    string postfix="abc*d/x*+fd*-";

for(int i =0;i<postfix.length();i++){
    
    char a=postfix[i];

    if(isalnum(a)){
        Node *temp=new Node;
        temp->value=postfix[i];
        temp->right=NULL;
        temp->left=NULL;
        
        push(temp);
    }
    else{
        Node *temp=new Node;
        temp->value=postfix[i];
        temp->right=pop();
        temp->left=pop();
        push(temp);

    }
}
inOrderTraversal(pop());

}