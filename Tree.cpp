#include<iostream>
using namespace std;
void LS(int arr[],int tosearch,int size){
    bool flag=false;
    for(int i=0;i<size;i++){
        if(arr[i]==tosearch){
            cout<<"Found at"<<i;
            flag=true;
            break;
        }
    }
    if(flag==false){
        cout<<"Not Found";
    }
}

void BS(int arr[],int tosearch,int size){
int left=0;
int right=size-1;
bool flag=false;
int mid;
while(left<=right){
    mid=left+((left-right)/2);
    if(arr[mid]==tosearch){
        cout<<"Found"<<mid;
        flag=true;
        break;
    }
    else if(arr[mid]<tosearch){
        
        left=mid+1;
    }
    else {
        right=mid-1;
        
    }
}
if (flag==false){
    cout<<"Not Found";
}
}



//Linked list

struct node{
int value;
node* next;
};

void addlast(node **head,int data){
node *temp=new node;
temp->next=NULL;

if(*head==NULL){
    *head=temp;
    temp->value=data;
}
else{
    node *curr=*head;
    while(curr->next!=NULL){
         curr=curr->next;
    }
    curr->next=temp;
    temp->value=data;
}
}
void addfirst(node **head,int data){
        node *temp=new node;
        temp->next=NULL;
if(*head==NULL){
    *head=temp;
    temp->value=data;
}
else{
    node *curr =*head;
    *head=temp;
    temp->next=curr;
}
}

void print(node **head){
    if(*head==NULL){
        cout<<"list empty";
    }
    else{
        node *curr=*head;
        while(curr!=NULL){
            cout<<curr->value<<endl;
            curr=curr->next;
        }
    }
}
void addcenter(node **head, int data,int tosearch){
    if(*head==NULL){
        cout<<"empty list"<<endl;
    }
    else{ 
           node *curr=*head;
            bool flag=true;
        while(curr!=NULL){
            if(curr->value==tosearch){
                node *temp=new node;
                temp->next=NULL;
                temp->next==curr->next;
                curr->next=temp;
                flag=true;
                break;

            }
            else{
               flag=false;           }
            
        }
        if(flag=false){
            cout<<"Not found";
        }
    }
}
void Delete(node **head,int todelete){
    if(*head==NULL){
        cout<<"empty list";
    }
    else{
        node *curr=*head;
        if(curr->value==todelete){
            *head=curr->next;
            free(curr);
        }
        else{
            bool flag;
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
                    flag=false;
                    curr=curr->next;
                    prev=prev->next;
                }
            }
            if(flag==false){
                cout<<"not find";
            }
        }
    }
}
int main(){
    node *head=NULL;
    int a=1,b;
    while(a>=1){   
    cout<<"enter number \n1 for addlast\n2 for addfirst\n3 for print\n4 for delete";
    cin>>a;
    if(a==1){
        cout<<"Enter value"<<endl;
        cin>>b;
addlast(&head,b);
    }
    else if(a==2){
 cout<<"Enter value"<<endl;
 cin>>b;
addfirst(&head,b);
    }
     else if(a==3){
        print(&head);
    }
    else if(a==4){
 cout<<"Enter value to delete"<<endl;
 cin>>b;
Delete(&head,b);
    }
    }
// int arr[25]={10,20,30,40,50};

// int size = sizeof(arr)/sizeof(arr[0]);
// cout<<size<<endl;
// int tosearch;
// cout<<"Enter value to search";
// cin>>tosearch;
// BS(arr,tosearch,size);
// // LS(arr,tosearch,size);

}