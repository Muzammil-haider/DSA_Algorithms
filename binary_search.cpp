#include<iostream>
using namespace std;

int binarysearch(int arr[],int tosearch,int size){
    int left=0;
    int right=size-1;
    int mid;
    while(left<=right){
    
        mid=(left+right)/2;
        if(arr[mid]==tosearch){
            cout<< "found at";
            return mid;
        }
        else if(arr[mid]<tosearch){
            left=mid + 1;

        }
        else{
            right=mid-1;
        }
    }
    return 0;
}
int main(){
int tosearch;
int arr[]={4,5,6,7,8,12,15,16,18,20,26};
int size=sizeof(arr)/sizeof(int);
cout<<"enter number to find";
cin>>tosearch;
int a=binarysearch(arr,tosearch,size);
if(a!=0){
    cout<<a;
}
else{
    cout<<"not found";
}

}