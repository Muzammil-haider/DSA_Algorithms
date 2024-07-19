#include<iostream>
using namespace std;
void insertionsort(int arr[],int size){
for(int i=1;i<size;i++){
    int unsort=arr[i];
    int j=i-1;
    while(arr[j]>unsort && j>=0){
    arr[j+1]=arr[j];
    j=j-1;
    }
    arr[j+1]=unsort;
    
}
for(int i=0;i<size;i++){
    cout<<arr[i]<<endl;
}

}


int main(){

int arr[]={12,54,65,32,15,4,8,5};
int size=sizeof(arr)/sizeof(int);
insertionsort(arr,size);


}