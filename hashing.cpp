#include<iostream>
using namespace std;

void LinearProb(int Hash[],int data,int size){
    int index=data%size;
    int counter=1;
    while(Hash[index]!=-1){
        index=(data+counter)%size;
        if(counter==size){
            cout<<"full"<<endl;
            break;
            return;
        }
        counter++;
    }
    if(counter != size){
        Hash[index]=data;
    }
}


void QuadraticProb(int Hash[],int data,int size){
    int index=data%size;
    int counter=1;
    while(Hash[index]!=-1){
        index=(data+(counter*counter))%size;
        if(counter>=size){
            LinearProb(Hash,data,size);
            break;
            return;
        }
        counter++;
    }
    if(counter != size){
        Hash[index]=data;
    }
}
void print(int Hash[],int size){
    for(int i=0;i<size;i++){
        cout<<i<<" "<<Hash[i]<<endl;
    }
    
}

int main(){
    int size=10;
    int Hash[size];
    for(int i=0;i<size;i++){
        Hash[i]=-1;
    }
    int a=1;
    while(a!=4){
        cout<<"Enter 1 for Insert 2 for print 3 for Quadratic"<<endl;
        cin>>a;
        if(a==1){
            int data;
            cout<<"Enter a num"<<endl;
            cin>>data;
            LinearProb(Hash,data,size);
        }
        else if(a == 2){
            print(Hash,size);
        }
        else if(a==3){
            int data;
            cout<<"Enter a num"<<endl;
            cin>>data;
            QuadraticProb(Hash,data,size);
        }
    }
    return 0;
}