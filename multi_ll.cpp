#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
int  id;
node *next;
};
struct course{
    int coursecode;
    course *next;
    node *student;
};
void insertstudent(course **head,int coursecode1,int student1){
    bool flag=false;
    if(*head==NULL){
        cout<<"empty list of course"<<endl;
        flag=false;
    }
    else{
        course *curr = *head;
        while(curr!=NULL){
            if(curr->coursecode==coursecode1){
                flag =true;
                node *ptr=new node;
                ptr->id=student1;
                ptr->next=NULL;
                node *studentcurr=curr->student;
                if(studentcurr==NULL){
                    curr->student=ptr;
                }
                else{
                    
                while(studentcurr->next!=NULL){
                    studentcurr=studentcurr->next;
                }
                studentcurr->next=ptr;}
                break;
            }
            else{
                curr=curr->next;
            }
        }
    }
    if(flag==true){
        cout<<"inserted"<<endl;
    }
    else{
        cout<<"invalid course id"<<endl;
    }

}
void insertcourse(course **head,int code){
    course *ptr=new course;
    ptr->coursecode=code;
    ptr->next=NULL;
    ptr->student=NULL;
    if(*head==NULL){
        *head=ptr;
    }
    else{
        course *curr=*head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=ptr;
    }
}
void deletestudent(course **head,int code,int studentid){
    if(*head==NULL){
        cout<<"empty list"<<endl;
    }
    else{
        bool flag1=false;
        bool flag=false;
        course *curr=*head;
        while(curr!=NULL){
            if(curr->coursecode==code){
                flag1==true;
                node *studentcurr=curr->student;
                if(studentcurr->id==studentid){
                    curr->student=studentcurr->next;
                    flag==true;
                    free(studentcurr);
                }
                else{
                    node *prev=studentcurr;
                    studentcurr=studentcurr->next;
                    while(studentcurr!=NULL){
                        if(studentcurr->id==studentid){
                            prev->next=studentcurr->next;
                            flag=true;
                            free(studentcurr);
                            break;
                        }
                        else{
                            prev=prev->next;
                            studentcurr=studentcurr->next;
                        }
                    }
                }
                break;

            }   
            else{
                curr=curr->next;
            }
        }
    if(flag1==true){
        cout<<"course found ....."<<endl;
    }
    else{
        cout<<"invalid course "<<endl;
    }
    if(flag==true){
        cout<<"student found and delete successfully"<<endl;
    }
    else{
        cout<<"student didn't found"<<endl;
    }
    }
}
void deletecourse(course **head,int todelete){
    if(*head==NULL){
        cout<<"empty list"<<endl;
    }
    else{
        bool flag=false;
        course *curr=*head;
        if(curr->coursecode==todelete){
            flag=true;
            *head=curr->next;
           
            while(curr->student!=NULL){
                 node *studentcurr=curr->student;
                while(studentcurr->next!=NULL){
                    studentcurr=studentcurr->next;
                } 
                free(studentcurr);
            }
            
            free(curr);
        }
        else{
            course *prev=curr;
            curr=curr->next;
            while(curr!=NULL){
                if(curr->coursecode==todelete){
                    prev->next=curr->next;
                    while(curr->student!=NULL){
                node *studentcurr=curr->student;
                while(studentcurr->next!=NULL){
                    studentcurr=studentcurr->next;
                } 
                free(studentcurr);}
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
            cout<<"found and delete successfully\n"<<endl;
        }
        else{
            cout<<"course didn't found\n"<<endl;
        }
    }
}
void searchcourse(course **head,int tosearch){
    if(*head==NULL){
        cout<<"empty list"<<endl;
    }
    else{
        bool flag=false;
        course *curr=*head;
        while(curr!=NULL){
            if(curr->coursecode==tosearch){
                cout<<"found"<<endl;
                flag=true;
                break;
            }
            else{
                curr=curr->next;
            }
        }
        if(flag==true){
            cout<<"course found"<<endl;
        }
        else{
            cout<<"course didn't found"<<endl;
        }
        
    }
}
void searchstudent(course **head,int tosearch){
    if(*head==NULL){
        cout<<"empty list"<<endl;
    }
    else{
        bool flag=false;
        bool flag1=false;
        course *curr=*head;
        while(curr!=NULL){
            node *studentcurr=curr->student;
            while(studentcurr!=NULL){
                if(studentcurr->id==tosearch){
                flag=true;
                break;
            }
            else{
                studentcurr=studentcurr->next;
            }
            }
            if(flag==true){
                cout<<curr->coursecode<<endl;
                break;
            }
            else{
           curr=curr->next;}
        }
        if(flag==true){
            cout<<"student found"<<endl;
        }
        else{
            cout<<"student didn't found"<<endl;
        }
        
    }
}
void printcourse(course **head){
    if(*head==NULL){
        cout<<" empty list";
    }
    else{
        course *curr=*head;
        while(curr!=NULL){
            cout<<curr->coursecode<<endl;
            curr=curr->next;
        }
    }
}
void printstudent(course **head){
    if(*head==NULL){
        cout<<" empty list";
    }
    else{
        course *curr=*head;
        while(curr!=NULL){
            cout<<curr->coursecode<<endl;
            node *studentcurr=curr->student;
            while(studentcurr!=NULL){
                cout<<studentcurr->id<<"->";
                studentcurr=studentcurr->next;
            }
            cout<<"\n";
            curr=curr->next;
        }
    }
}
void Deletestudent(course **head,int todelete){
    if(*head==NULL){
        cout<<"empty list";

    }
    else{
        bool flag=false;
        course *curr =*head;
        while(curr!=NULL){
            node *studentcurr=curr->student;
            if(studentcurr->id==todelete){
                    curr->student=studentcurr->next;
                    flag==true;
                    free(studentcurr);
                }
                else{
                    node *prev=studentcurr;
                    studentcurr=studentcurr->next;
                    while(studentcurr!=NULL){
                        if(studentcurr->id==todelete){
                            prev->next=studentcurr->next;
                            flag=true;
                            free(studentcurr);
                            break;
                        }
                        else{
                            prev=prev->next;
                            studentcurr=studentcurr->next;
                        }
                    }
                }
                curr=curr->next;
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
    course *head=NULL;
    int a=1;
    while(a>=1){
        cout<<"Enter 1 for insert course\nEnter 2 for insert student\nEnter 3 for print course\nEnter 4 for print students\nEnter 5 for search course\nEnter 6 for search student\nEnter 7 for delete course\nEnter 8 for delete student\nEnter 9 for delete student from all course";
        cin>>a;
        if(a==1){
            int x;
            cout<<"enter a course code\n";
            cin>>x;
            insertcourse(&head,x);
        }
         else if(a==2){
            int x;
            cout<<"enter a course code\n";
            cin>>x;
            int a;
            cout<<"enter a student id\n";
            cin>>a;
            insertstudent(&head,x,a);
        }
        else if(a==3){
            printcourse(&head);
        }
        else if(a==4){
            printstudent(&head);
        }
        else if(a==5){
            int x;
            cout<<"enter a course code to search\n";
            cin>>x;
            searchcourse(&head,x);
        }
         else if(a==6){
            int x;
            cout<<"enter a student id to search\n";
            cin>>x;
            searchstudent(&head,x);
        }
         else if(a==7){
             int x;
            cout<<"enter a course code to delete\n";
            cin>>x;
            deletecourse(&head,x);
        }
        else if(a==8){
             int x;
            cout<<"enter a course code\n";
            cin>>x;
            int a;
            cout<<"enter a student id\n";
            cin>>a;
            deletestudent(&head,x,a);
        }
        else if(a==9){
             int x;
            cout<<"enter a student id to delete from all courses\n";
            cin>>x;
            Deletestudent(&head,x);
        }
    }
    }


