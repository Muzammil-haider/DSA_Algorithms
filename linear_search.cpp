#include<iostream>
using namespace std;
int Linearsearch(int arr[],int tosearch,int size){
for(int i =0;i<size;i++){
    if(arr[i]==tosearch){
        cout<<"found at"<<i;
        return 1;
    }
    
}
cout<<"not found";
return 1;
}
int main(){
int tosearch;
int arr[]={12,54,65,32,15,4,8,5,4};
int size=sizeof(arr)/sizeof(int);
cout<<"enter number to find";
cin>>tosearch;
Linearsearch(arr,tosearch,size);

}