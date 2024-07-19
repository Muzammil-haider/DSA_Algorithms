#include<iostream>
using namespace std;
void bubblesort(int arr[],int size){
for(int i=size;i>=0;i--){
    for(int j=0;j<i-1;j++){
        if(arr[j]>arr[j+1]){
            int temp;
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
for(int a =0;a<size;a++){
    cout<<arr[a]<<endl;
}
}

int main(){

int arr[]={12,54,65,32,15,4,8,5};
int size=sizeof(arr)/sizeof(int);
bubblesort(arr,size);

}