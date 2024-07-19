#include <iostream>
using namespace std;

struct NodeStack{
    char character;
    NodeStack* nextNode;
};

NodeStack* topNode = NULL;

void push(char ch){
    NodeStack* tempNode = new NodeStack;
    tempNode->character = ch;
    tempNode->nextNode = NULL;

    if (topNode == NULL)
    {
        topNode = tempNode;
    }
    else
    {
        NodeStack* currentNode = topNode;
        topNode = tempNode;
        tempNode->nextNode = currentNode;
    }
}

char top(){
    if(topNode==NULL){
        cout<<"stack overflow";
        return 0;
    }
    else{
        NodeStack *curr=topNode;
       return curr->character;
    }
    
}

char pop(){
    if (topNode == NULL)
    {
        cout<< "Stack underflow" << "\n";
        return 0;
    }
    else
    {
        NodeStack* currentNode = topNode;
        char ch = topNode->character;
        topNode = topNode->nextNode;
        delete currentNode;
        return ch;
    }
}
int presedence(char a){
if(a=='*'||a=='/'||a=='%'){
    return 4;
}
else if(a=='+'||a=='-'){
    return 3;
}
else if(a=='<'||a=='>'){
    return 2;
}
else if(a=='&'||a=='|'){
    return 1;
}
return -1;
}
string  infixToPostfix(string infix,int size){
 string postfix="";
 for(int i=0;i<size;i++){
    char a=infix[i];
    if(isalnum(a)){
        postfix +=a;
    }
    else if(a==')'){
        while(topNode!=NULL && top()=='('){
            postfix+=pop();
        }
        pop();
    }
      else if(a=='('){
        
        push(a);
    }
    else{
         while(topNode!=NULL && presedence(a)<=presedence(top())){
            postfix+=pop();
         }
         push(a);
        
        
    }
    

 }
 while(topNode!=NULL){
        postfix+=pop();
    }
    return postfix;
}
int postfixEvaa(string postfix){
    int size=sizeof(postfix[size])/postfix[0];
for (int i =0;i<size;i++){
    if(isalnum(postfix[i])){
        push(postfix[i]);
    }
    else{
        int a =pop();
        int b =pop();
        if(postfix[i]=='+'){
            int c =a+b;
        }
        else if(postfix[i]=='-'){
            int c =a-b;
        }
        else if(postfix[i]=='*'){
            int c =a*b;
        }
        else{
            int c =a/b;
        }
        push('c');
    }
}
return pop();
}





int main()
{
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);
   int size=sizeof(infixExpression)/sizeof(int);
        

    string postfixExpression = infixToPostfix(infixExpression,size);
    cout << "Postfix expression: " << postfixExpression << endl;

    // int postfixEva = postfixEvaa("7+6*2/4*1*23");
    // cout<< "postfix Evaluations: " << postfixEva << endl;

    return 0;
}



