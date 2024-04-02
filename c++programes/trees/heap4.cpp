#include<iostream>
#include<queue>
using namespace std;

//Smallest Range From K Sorted List
// You are given 'K' lists containing non-negative integers. Each list has a size 'N' and is sorted in non-decreasing order. You need to find the minimum length of a range such that at least one element of each list must be included in that range.

class node{
    public:
        int data;
        int col;
        int row;
        node(int data,int col,int row){
            this->data=data;
            this->col=col;
            this->row=row;
        }
};

class compare{
    public:
        bool operator()(node* a,node* b){
            return a->data>b->data;
        }
};

pair<int,int> kSorted(vector<vector<int>> &arr, int k, int n){
    int mini=INT_MAX;
    int maxi=INT_MAX;
    
    //step1: create a min Heap for starting element of each list and tracking mini/maxi value
    priority_queue<node* ,vector<node*> , compare> pq;

    for (int i=0;i<k;i++){
        int ele=arr[i][0];
        mini=min(ele,mini);
        maxi=max(ele,maxi);
        pq.push(new node(ele,k,0));
    }

    int start=mini;
    int end=maxi;
    //process ranges
    while (pq.top())
    {
        //fetch mini
        node* temp=pq.top();
        pq.pop();
        mini=temp->data;

        // range or answer updation
        if(maxi-mini < end-start){
            start=mini;
            end=maxi;
        }

        // checking next element 
        if (temp->col +1 < n){
            mini=max(mini,arr[temp->row][temp->col+1]);
            pq.push(new node(arr[temp->row][temp->col+1],temp->row,temp->col+1));
        }
        else{
            //next element does not exist
            break;
        }
        
    }
    return make_pair(end,start);
}


// Problem Statement (Median in a stream)
// Given that integers are read from a data stream.
// Your task is to find the median of the elements read so far.
// Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.

int signum(int a,int b){
    if(a>b){
        return 1;
    }
    else if(b<a){
        return -1;
    }
    else{
        return 0;
    }

}
void callMedian(int element,priority_queue<int> &maxHeap,priority_queue<int , vector<int> , greater<int> > &minHeap , int median){
    switch (signum(maxHeap.size(),minHeap.size()))
    {
        case 0: if(element > median){
                minHeap.push(element);
                median=minHeap.top();
            }
            else{
                maxHeap.push(element);
                median=maxHeap.top();
            }

        case 1: if(element > median){
                minHeap.push(element);
                median=(minHeap.top()+maxHeap.top())/2;
            }
            else{
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(element);
                median=(minHeap.top()+maxHeap.top())/2;
            }
            break;

        case -1:  if(element > median){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(element);
                median=(minHeap.top()+maxHeap.top())/2;
            }
            else{
                maxHeap.push(element);
                median=(minHeap.top()+maxHeap.top())/2;
            }
            break;
    }
}

vector<int> findMedian(vector<int> arr,int n){
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int , vector<int> , greater<int> > minHeap;
    int median=0;
    for(int i=0;i<n;i++){
        callMedian(arr[i],maxHeap,minHeap,median);
        ans.push_back(median);
    }
    return ans;
}

int main(){
    return 0;
}