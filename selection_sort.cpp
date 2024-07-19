#include<iostream>
using namespace std;
void selectionsort(int arr[],int size){
    for(int i=0;i<size-1;i++){

    int min=i;
        for(int j=i+1;j<size;j++){
            if(arr[min]>arr[j]){
                int temp;
                temp=arr[min];
                arr[min]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){

int arr[]={12,54,65,32,15,4,8,5};
int size=sizeof(arr)/sizeof(int);
selectionsort(arr,size);


}