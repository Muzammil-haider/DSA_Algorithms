#include<iostream>
using namespace std;
void LS(int arr[],int tosearch,int size){
    bool flag=false;
    for(int i=0;i<size;i++){
        if(arr[i]==tosearch){
            cout<<"Found at"<<i;
            flag=true;
            break;
        }
    }
    if(flag==false){
        cout<<"Not Found";
    }
}


int main(){
int arr[7]={18,16,15,19,12,11,14};
int size = sizeof(arr)/sizeof(arr[0]);
cout<<size<<endl;
int tosearch;
cout<<"Enter value to search";
cin>>tosearch;
LS(arr,tosearch,size);
}