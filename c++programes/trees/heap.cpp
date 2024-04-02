#include<iostream>
#include<queue>
using namespace std;
class heap{
    public:
        int arr[100];
        int size=0;
        
        void insert(int val){
            
            size=size+1;
            int index=size;
            arr[index]=val;
            while (index > 1)
            {
                int parent=index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[index],arr[parent]);
                    index=parent;
                }
                else{
                    return;
                }
            } 
        }
        void print(){
            int i=1;
            for(;i<=size;i++){
                cout<<arr[i]<<" , ";
            }
            cout<<endl;
        }

        void deleteFromHeap(){
            if(size==0){
                cout<<"Heap is empty"<<endl;
            }
            int i=1;
            swap(arr[i],arr[size]);
            size--;
            
            while(i<size){
                int left=2*i;
                int right=2*i+1;

                if(left<size && arr[left]>arr[i]){
                    swap(arr[left],arr[i]);
                }
                else if(right<size && arr[i]<arr[right]){
                    swap(arr[right],arr[i]);
                }
                else{
                    return;
                }
                i++;
            }
        }

};
// 1 based indexing
void heapify(int arr[],int size , int i){
    if(size<=0){
        cout<<" heap is empty "<<endl;
    }
    int largest=i;
    int left=largest*2;
    int right=largest*2+1;
    if(left<size && arr[i]<arr[left]){
        largest=left;
    }
    if(right<size && arr[i]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}

void heapSort(int arr[],int n){
    int i=n;
    heapify(arr,n,1);
    while(i>1){
        swap(arr[1],arr[i]);
        heapify(arr,i,1);
        i--;
    }
}
int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.deleteFromHeap();
    h.print();
    
    int arr[6] = {-1, 54, 53, 55, 52,50};
    for(int i=5/2;i>0;i--){
        heapify(arr,5,i); 
    }
    cout<<arr[1]<<" , ";
    cout<<arr[2]<<" , ";
    cout<<arr[3]<<" , ";
    cout<<arr[4]<<" , ";
    cout<<arr[5]<<" , "<<endl;

    heapSort(arr,5);
    cout<<arr[1]<<" , ";
    cout<<arr[2]<<" , ";
    cout<<arr[3]<<" , ";
    cout<<arr[4]<<" , ";
    cout<<arr[5]<<" , ";
    return 0;

    //implementing heap using priority queue
    //max heap
    priority_queue<int> maxHeap;
    //min heap
    priority_queue< int , vector<int> , greater<int> > minHeap;


}