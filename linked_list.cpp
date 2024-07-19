#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
int value;
node *next;
};
void insert(node **head,int data){
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
void delete1(node **head,int todelete){
    if(*head==NULL){
        cout<<"empty list"<<endl;
    }
    else{
        bool flag=false;
        node *curr=*head;
        if(curr->value==todelete){
            flag=true;
            *head=curr->next;
            free(curr);
        }
        else{
            node *prev=curr;
            curr=curr->next;
            while(curr!=NULL){
                if(curr->value==todelete){
                    prev->next=curr->next;
                    free(curr);
                    flag=true;
                    break;
                }
                else{
                    curr=curr->next;
                    prev=prev->next;
                }
            }
        }
        if(flag==true){
            cout<<"found\n";
        }
        else{
            cout<<"not found\n";
        }
    }
}
int search(node **head,int tosearch){
    if(*head==NULL){
        cout<<"empty list"<<endl;
        return 1;
    }
    else{
        node *curr=*head;
        while(curr!=NULL){
            if(curr->value==tosearch){
                cout<<"found"<<endl;
                return 1;
            }
            else{
                curr=curr->next;
            }
        }
        cout<<"not found"<<endl;;
        return 1;
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
void Delete(node **head){
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
        cout<<"Enter 1 for insert\nEnter 2 for print\nEnter 3 for delete\nEnter 4 for search";
        cin>>a;
        if(a==1){
            int x;
            cout<<"enter a value\n";
            cin>>x;
            insert(&head,x);
        }
        else if(a==2){
            print(&head);
        }
        else if(a==3){
            int x;
            cout<<"enter a value\n";
            cin>>x;
            delete1(&head,x);
        }
         else if(a==4){
             int x;
            cout<<"enter a value\n";
            cin>>x;
            search(&head,x);
        }
    }
    }


