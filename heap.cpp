#include <iostream>
using namespace std;

void minHeap(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int child = i;
        while (child > 0) {
            int parent = (child - 1) / 2;
            if (arr[parent] <= arr[child]) {
                break;
            }
            swap(arr[parent], arr[child]);
            child = parent;
        }
    }
}

void deleteMin(int arr[], int size){
    arr[0] = arr[size-1];
    arr[size-1] = -1;
    minHeap(arr, size-1);
}


void maxHeap(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int child = i;
        while (child > 0) {
            int parent = (child - 1) / 2;
            if (arr[parent] >= arr[child]) {
                break;
            }
            swap(arr[parent], arr[child]);
            child = parent;
        }
    }
}

void deleteMax(int arr[], int size){
    maxHeap(arr, size-1);
    arr[0] = arr[size-1];
    arr[size-1] = -1;
    maxHeap(arr, size-1);
}

void heapSort(int arr[], int size) {
    maxHeap(arr, size);//230 117 78 99 97 23 70 11 63 55
    for(int i = size-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        maxHeap(arr, i);
    }
}

int main(){
    // int arr[] = {78,99,23,63,97,55,230,117,70,11};
    int arr[] = {99,117,230,55,70,97,78,11,23,63,};
    int size = sizeof(arr)/sizeof(arr[0]);

    //  minHeap(arr, size);
    //   for(int i=0; i<size; i++){
    //      cout<<arr[i]<<" ";
         
    //  }

     maxHeap(arr, size);
     for(int i=0; i<size; i++){
         cout<<arr[i]<<",";
        
     }

    // cout<<"Now for delete"<<endl;

    //  heapSort(arr, size);
    //  for(int i=0; i<size; i++){
    //      cout<<arr[i]<<" "<<endl;
         
    // }



    // deleteMin(arr, size);
    // for(int i=0; i<size; i++){
    //     cout<<arr[i]<<" ";
    // }

    return 0;
}