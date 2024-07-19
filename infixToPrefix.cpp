#include <iostream>
using namespace std;

struct NodeStack
{
    char character;
    NodeStack* nextNode;
};

NodeStack* topNode = NULL;

void push(char ch)
{
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

char top()
{
    if (topNode == NULL)
    {
        cout << "Stack underflow" << "\n";
        return 0;
    }
    else
    {
        char ch = topNode->character;
        return ch;
    }
}

char pop()
{
    if (topNode == NULL)
    {
        cout << "Stack underflow" << "\n";
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

int precedence(char operatorChar)
{
    if (operatorChar == '*' || operatorChar == '/' || operatorChar == '%')
    {
        return 4;
    }
    if (operatorChar == '+' || operatorChar == '-')
    {
        return 3;
    }
    if (operatorChar == '<' || operatorChar == '>')
    {
        return 2;
    }
    if (operatorChar == '&' || operatorChar == '|')
    {
        return 1;
    }
    return -1;
}

void reverseString(string &inputString){
    string reverseStr = "";

    for(int i=0; i < inputString.length(); i++){
        reverseStr = inputString[i] + reverseStr;
    }

    inputString = reverseStr;
}

string InfixtoPrefix(string &inputString){
    string result="";
    reverseString(inputString);
    for(int i=0;i<inputString.length();i++){
        char c=inputString[i];
        if(isalnum(c)){
            result +=c;
        }
        else if(c==')'){
            push(c);
        }
        else if(c=='('){
            while(topNode!=NULL && top()!=')'){
                result +=top();
                pop();
            }
            pop();
        }
        else{
            while(topNode!=NULL && precedence(top()) <= precedence(c)){
                result +=top();
                pop();
            }
            push(c);
        }
    }
    while(topNode!=NULL){
        result +=top();
        pop();
    }
    reverseString(result);
    return result;
}



int preFixEvaluation(string prefix){
    for(int i=prefix.length()-1;i>=0;i--){
        if(isdigit(prefix[i])){
            push(prefix[i] - '0');
        }
        else{
            int a=top();
            pop();
            int b=top();
            pop();
            switch(prefix[i]){
                case '+':
                push(a+b);
                break;
            
                case '-':
                push(a-b);
                break;

                case '*':
                push(a*b);
                break;

                case '/':
                push(a/b);
                break;
        }
    }
}
return top();
}

int main()
{
    // string infixExpression;
    // cout << "Enter an infix expression: ";
    // getline(cin, infixExpression);

    // string prefixExpression = InfixtoPrefix(infixExpression);
    // cout << "Prefix expression: " << prefixExpression << endl;

    int preFixEva = preFixEvaluation("+6*2/4*1*23");
    cout<< "PreFix Evaluations: " << preFixEva << endl;

    return 0;
}



