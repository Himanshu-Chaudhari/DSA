#include<iostream>
using namespace std;    

void heapify(int* arr,int n ,int root){
    int largest =root;
    int left= root*2+1;
    int right= root*2+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest != root){
        swap(arr[largest],arr[root]);
        heapify(arr,n,largest);
    }  
}

void heapSort(int* arr,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}

int main(){
    int n;
    cout<<" Size of array"<<endl;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heapSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}