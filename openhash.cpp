#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
int  value;
node *next;
};
struct Index{
    int index;
    Index *next;
    node *valuenode;
};
void insert(Index **head,int data){
    int index=data%10;
    bool flag=false;
    
        Index *curr = *head;
        while(curr->index!=index){
                curr=curr->next;
            }
                node *ptr=new node;
                ptr->value=data;
                ptr->next=NULL;
                node *valuecurr=curr->valuenode;
                if(valuecurr==NULL){
                    curr->valuenode=ptr;
                    flag=true;
                }
                else{
                    
                while(valuecurr->next!=NULL){
                    valuecurr=valuecurr->next;
                }
                valuecurr->next=ptr;
                flag=true;
                }
                
     
    
    if(flag==true){
        cout<<"inserted"<<endl;
    }
    else{
        cout<<"invalid course id"<<endl;
    }

}
void insertindex(Index **head,int code){
    Index *ptr=new Index;
    ptr->index=code;
    ptr->next=NULL;
    ptr->valuenode=NULL;
    if(*head==NULL){
        *head=ptr;
    }
    else{
        Index *curr=*head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=ptr;
    }
}

void searchvalue(Index **head,int tosearch){
    int index=tosearch%10;
    if(*head==NULL){
        cout<<"empty list"<<endl;
    }
    else{
        bool flag=false;
       
        Index *curr=*head;
        while(curr->index!=index){
            
            
           curr=curr->next;
        }
        node *valuecurr=curr->valuenode;
            while(valuecurr!=NULL){
                if(valuecurr->value==tosearch){
                flag=true;
                break;
            }
            else{
                valuecurr=valuecurr->next;
            }
            }
        if(flag==true){
            cout<<"value found"<<endl;
        }
        else{
            cout<<"value didn't found"<<endl;
        }
        
    }
}

void printvalue(Index **head){
    if(*head==NULL){
        cout<<" empty list";
    }
    else{
        Index *curr=*head;
        while(curr!=NULL){
            cout<<curr->index<<"==";
            node *valuecurr=curr->valuenode;
            while(valuecurr!=NULL){
                cout<<valuecurr->value<<"->";
                valuecurr=valuecurr->next;
            }
            cout<<"\n";
            curr=curr->next;
        }
    }
}
void Deletevalue(Index **head,int todelete){
    int index=todelete%10;
    if(*head==NULL){
        cout<<"empty list";

    }
    else{
        bool flag=false;
        Index *curr =*head;
        while(curr->index!=index){
           
                curr=curr->next;
        }
         node *valuecurr=curr->valuenode;
            if(valuecurr->value==todelete){
                    curr->valuenode=valuecurr->next;
                    flag==true;
                    free(valuecurr);
                }
                else{
                    node *prev=valuecurr;
                    valuecurr=valuecurr->next;
                    while(valuecurr!=NULL){
                        if(valuecurr->value==todelete){
                            prev->next=valuecurr->next;
                            flag=true;
                            free(valuecurr);
                            break;
                        }
                        else{
                            prev=prev->next;
                           valuecurr=valuecurr->next;
                        }
                    }
                }

    if(flag==true){
            cout<<"student found"<<endl;
        }
        else{
            cout<<"student didn't found"<<endl;
        }
    }
}

int main(){
    Index *head=NULL;
    for(int i=0;i<10;i++ ){
        insertindex(&head,i);
    }
    int a=1;
    while(a>=1){
        cout<<"Enter 1 for insert value\nEnter 2 for print values\nEnter 3 for search value\nEnter 4 for delete value\n";
        cin>>a;
        if(a==1){
            int x;
            cout<<"enter a value\n";
            cin>>x;
            insert(&head,x);
        }
         else if(a==2){
          
           printvalue(&head);
        }
        else if(a==3){
            int x;
            cout<<"enter a value to search\n";
            cin>>x;
            searchvalue(&head,x);
        }
        else if(a==4){
            int x;
            cout<<"enter a value to delete\n";
            cin>>x;
            Deletevalue(&head,x);
        }
    }
    }


