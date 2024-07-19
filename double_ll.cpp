#include<iostream>
using namespace std;
struct node{
int value;
node *next;
node *prev;

};


void insert(node **head,int data){
    node *temp = new node;
    temp->next=NULL;
    temp->prev=NULL;
    temp->value=data;
if(*head ==NULL){
    *head=temp;
    
}
else{
    node *curr =*head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
   
}
}



void print(node **head){
    if(*head == NULL){
        cout<<"empty list";
    }
    else{
         node *curr =*head;
    while(curr!=NULL){
        cout<<curr->value<<endl;
        curr=curr->next;
    }
    }
}
// int addsorted(node **head,int data){
//     node *temp = new node;
//     temp->next=NULL;
//     temp->prev=NULL;
//     temp->value=data;
//     if(*head==NULL){
//         *head=temp;
//         return 1;
//     }
//     else{
//         node *curr=*head;
//         if(curr->value>data){
//             *head=temp;
//             temp->next=curr;
//             curr->prev=temp;
//             return 1;
//         }
//         else{
//             while(curr->next!=NULL){
//                 curr=curr->next;
//                 if(curr->value>data){
//                     temp->prev=curr->prev;
//                     node *cash=curr->prev;
//                     cash->next=temp;
//                     temp->next=curr;
//                     curr->prev=temp;
//                     return 1;
//                 }
//             }
//             if(curr->value>data){
//                     temp->prev=curr->prev;
//                     node *cash=curr->prev;
//                     cash->next=temp;
//                     temp->next=curr;
//                     curr->prev=temp;
//                     return 1;
//             }
//             else{
//                 curr->next=temp;
//                 temp->prev=curr;
//                 return 1;
//             }
            
//         }
//         }
// }
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
            while(curr->next!=NULL){
                if(curr->value==todelete){
                    prev->next=curr->next;
                    curr->next->prev=prev;
                    free(curr);
                    flag=true;
                    break;
                }
                else{
                    curr=curr->next;
                    prev=prev->next;
                }
            }
            if(curr->value==todelete){
                    prev->next=curr->next;
                    free(curr);
                    flag=true;
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
void search(node **head,int tosearch){
    if(*head==NULL){
        cout<<"empty list"<<endl;
        
    }
    else{
        bool flag=false;
        node *curr=*head;
        while(curr!=NULL){
            if(curr->value==tosearch){
                flag=true;
                break;
            }
            else{
                curr=curr->next;
            }
        }
        if(flag==true){
    cout<<"found";

   }
   else{
    cout<<"not found";
   }
    }
    
   
}
int main(){
    node *head=NULL;
    int a=1,b;
    while(a>=1){   
    cout<<"enter number \n1 for insert\n2 for print\n3 for delete\n4 for dsearch\n 5 for reverse";
    cin>>a;
    if(a==1){
        cout<<"Enter value"<<endl;
        cin>>b;
    insert(&head,b);
    }
    else if(a==2){
        print(&head);
    }
    else if(a==3){
        cout<<"Enter value"<<endl;
        cin>>b;
    delete1(&head,b);
    }
      else if(a==4){
        cout<<"Enter value"<<endl;
        cin>>b;
    search(&head,b);
    }
    else if(a==5){
        
    reverse1(&head);
    }
}
}