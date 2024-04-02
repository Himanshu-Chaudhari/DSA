#include<iostream> 
#include<queue>
#include<vector>
using namespace std;

// You have been given an array/list of 'N' integers. Now you are supposed to find the K-th largest sum of the subarray.

int getKthLargest (vector<int> arr, int k){
    int s=arr.size();
    priority_queue< int , vector<int> , greater<int> > heap;
    for(int i=0;i<s;i++){
        int sum=0;
        for(int j=i;j<s;j++){
            sum=sum+arr[j];
            if(heap.size()<k){
                heap.push(sum);
            }
            else{
                if(heap.top()<sum){
                    heap.pop();
                    heap.push(sum);
                }
            }
        }
    }
    return heap.top();
}

// You have been given 'K' different arrays/ligts, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order. NEED TO REVISE THIS QUESTION

// class node{
//     public:
//         int data;
//         int i;
//         int j;
//         node(int data,int row,int col){
//             this->data=data;
//             i=row;
//             j=col;
//         }
// };

// class compare{
//     public:
//         bool operator()(node* a,node* b){
//             return a->data > b->data;
//         }
// };
// vector<int> mergeKSortedArrays (vector<vector<int>>& arr,int k){
//     priority_queue<node* , vector<node*> , compare> minHeap;

//     // Insert 1 st elements of all sub arrays
//     for(int i=0;i<k;i++){
//         node* temp=new node(arr[i][0],i,0);
//         minHeap.push(temp);
//     }

//     // size of min heap is > 0

//     vector<int> ans;
//     while(minHeap.size()>0){
//         node* temp=minHeap.top();
//         ans.push_back(temp->data);
//         minHeap.pop();

//         int i=temp->i;
//         int j=temp->j;
//         if(j+1<arr[i].size()){
//             node* next=new node(arr[i][j+1],i,j+1);
//             minHeap.push(next);
//         }
//     }
//     return ans;
// }

// Merge k sorted lists
// Given 'K' sorted linked lists, each list is sorted in increasing order. You need to merge all these lists into one single sorted list. You need to return the head of the final linked list.

class node{
    public:
        int data;
        node* next;
        node(int data){
            this->data=data;
            this->next=NULL;
        }
};

class cmp{
    public:
        bool operator()(node* a,node* b) {
            return a->data > b->data;
        }
};

node* mergeKSortedLinkedList(vector<node*> listArray){
    priority_queue<node*,vector<node*> , cmp > pq;

    int k=listArray.size();

    if(k==0){
        return NULL;
    }
    for(int i=0;i<k;i++){
        if(listArray[i] != NULL){
            pq.push(listArray[i]);
        }
    }
    node* head=NULL;
    node* tail=NULL;
    while (pq.size()>0)
    {
        node* temp=pq.top();
        pq.pop();

        if(temp->next != NULL){
            pq.push(temp->next);
        }
        if(head==NULL){
            // LL is empty
            head=temp;
            tail=temp;
        }
        else{
            // insert at LinkLists end
            tail->next=temp;
            tail=temp;
        }
    }
    return head;
    
}
int main(){
    vector<int> arr{10, -10, 20, -40};
    cout<<getKthLargest(arr,6 )<<endl;
    return 0;
}