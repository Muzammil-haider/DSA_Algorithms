#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
int value;
node *next;
};
void push(node **head,int data){
    node *temp=new node;
    temp->value=data;
    temp->next=NULL;
    if(*head==NULL){
        *head=temp;
    }
    else{
        node *curr=*head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
    }
}
void print(node **head){
    if(*head==NULL){
        cout<<" empty list";
    }
    else{
        node *curr=*head;
        while(curr!=NULL){
            cout<<curr->value<<endl;
            curr=curr->next;
        }
    }
}
void pop(node **head){
    if(*head==NULL){
        cout<<"empty list";

    }
    else{
        node *curr =*head;
        node *prev=curr;
        curr=curr->next;
        while(curr->next!=NULL){
            curr=curr->next;
            prev=prev->next;
        }
        prev->next=curr->next;
        free(curr);
    }
}

int main(){
    node *head=NULL;
    int a=1;
    while(a>=1){
        cout<<"Enter 1 for push\nEnter 2 for print\nEnter 3 for pop\n";
        cin>>a;
        if(a==1){
            int x;
            cout<<"enter a value\n";
            cin>>x;
            push(&head,x);
        }
        else if(a==2){
            print(&head);
        }
        else if(a==3){
            pop(&head);
        }
    }


}