#include<iostream>
using namespace std;
void pop(int stack[],int size){
    stack[size]=0;

}
int push(int arr[],int size ){
    int element;
    cout<<"enter element";
    cin>>element;
    for(int i=size;i>=0;i--){
        if(i==0){
            
            arr[i+1]=arr[i];
            arr[i]=element;
            size=size+1;
        }
        else{
            arr[i+1]=arr[i];
        }

    }
    arr[size]=element;
    return size;
}


int main(){
int maxsize=100;
int stack[maxsize]={12,54,65,32,15,4,8,5,4};
int size1=9;

size1=push(stack,size1);
// pop(stack,size1);
for(int i =0; i<size1;i++){
    cout<<stack[i]<<endl;
}




}