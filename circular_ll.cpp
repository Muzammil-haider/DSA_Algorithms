#include<iostream>
using namespace std;
struct node{
int value;
node *next;

};

void insert(node **head,int data){
    node *temp = new node;
    temp->value=data;

    if(*head==NULL){
    *head=temp;
    temp->next=*head;
    }
    else{
        node *curr=*head;
        while(curr->next!=*head){
            curr=curr->next;
        }
        curr->next=temp;
        temp->next=*head;
    }
}
void Delete(node **head,int todelete){
    if(*head==NULL){
        cout<<"list empty"<<endl;
        
    }
    else{
        bool flag=false;
        node *curr=*head;
        if(curr->value==todelete){
            if(curr->next==*head){
                free(*head);
                flag=true;
            }
            else{
             node *temp=curr;
            while(curr->next!=*head){
                curr=curr->next;

            }
            *head=temp->next;
            curr->next=*head;
            free(temp);
            flag=true;
            }
            
        }
        else{
           node *prev=curr;
           curr=curr->next;
           while(curr->next!=*head){
            if(curr->value==todelete){
                prev->next=curr->next;
                free(curr);
                break;
                flag=true;
            }
            else{
                curr=curr->next;
                prev=prev->next;
            }
           }
           if(curr->value==todelete){
      prev->next=*head;
           free(curr);
           flag=true;}
           else{
            cout<<"not found"<<endl;
           
           }
           
        }
        if(flag==true){
        cout<<"found"<<endl;
        }
        else{
            cout<<"not found"<<endl;
        }
    }
}
void print(node **head){
    if(*head==NULL){
    cout<<"empty"<<endl;
    return;
    }
    else{
        node *curr=*head;
        while(curr->next!=*head){
            cout<<curr->value<<endl;
            curr=curr->next;
        }
        cout<<curr->value<<endl;

    }
}
int main(){
    node *head=NULL;
    int a=1,b;
    while(a!=2){   
    cout<<"enter number \n1 for insert\n2 for addfirst\n3 for print\n4 for delete";
    cin>>a;
    if(a==1){
        cout<<"Enter value"<<endl;
        cin>>b;
    insert(&head,b);
    }
    else if(a==3){
        print(&head);
    }
    else if(a==4){
        cout<<"Enter value"<<endl;
        cin>>b;
    Delete(&head,b);
    }
}
}