#include<iostream>
#include<queue>

using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int data){
            this->data=data;
            this->left=NULL;
            this->left=NULL;
        }
};

node* createTree(node* root){
    cout<<"Please enter the data to insert"<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node* temp=new node(data);
    root=temp;
    root->left=createTree(root->left);
    root->right=createTree(root->right);
    return root;
}

class heap{
    public:
        int arr[100];
        int size=0;
        void insert(int val){
            size++;
            int index=size;
            arr[index]=val;
            while(index>1){
                int parent=index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }
                else{
                    return;
                }
            }
        }

        void print(){
            int i=1;
            while(i<=size){
                cout<<arr[i]<<" , ";
                i++;
            }
            cout<<endl;
        }

        void deleteFromHeap(){
            if(size==0){
                cout<<"Heap is empty"<<endl;
            }
            int i=1;
            size--;

            while(i<size){
                int left=i*2+1;
                int right=i*2+2;
                if(arr[left] > arr[i] && left < size){
                    swap(arr[left],arr[i]);
                }
                else if(arr[right] > arr[i] && right < size){
                    swap(arr[right],arr[i]);
                }
                else{
                    return;
                }
                i++;
            }
        }
};

int kthSmallestElement(int arr[],int size,int k){
    priority_queue< int , vector<int> , greater<int> > pq;
    for(int i=0 ; i<k ; i++){
        pq.push(arr[i]);
    }
    for(int i=k ; k<size ; k++){
        if(pq.top()<arr[k]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

void heapify(vector<int> arr,int size,int index){
    if(size <= 0){
        return;
    }
    int largest = index;
    int left = largest*2;
    int right = largest*2+1;

    if(arr[left]>arr[largest] && left<size){
        largest = left;
    }
    if(arr[right]>arr[largest] && right<size){
        largest = right;
    }
    if(largest != index){
        swap(arr[index],arr[largest]);
        heapify(arr,size,largest);
    }

}
void heapSort(vector<int> arr,int n){
    int i=n;
    heapify(arr,n,1);
    while(i>1){
        swap(arr[1],arr[i]);
        heapify(arr,i,1);
        i--;
    }
}

// Is binnary tree a heap

int countNodes(node* root){
    if(root==NULL){
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}

bool isCBT(node* root,int index,int count){
    if(root==NULL){
        return true;
    }
    if(index>=count){
        return false;
    }
    bool left=isCBT(root->left,index*2+1,count);
    bool right=isCBT(root->right,index*2+1,count);
    return left && right;
}

bool isMaxOrder(node* head){
    if(head->left==NULL && head->right==NULL){
        return true;
    }
    if(head->right==NULL){
        return head->left->data < head->data;
    }
    bool left=isMaxOrder(head->left);
    bool right=isMaxOrder(head->right);
    return (left && right) && (head->left->data < head->data && head->right->data < head->data);
}

bool isBinnaryTreeAHeap(node* root){
    int count=countNodes(root);
    int index=0;
    return (isCBT(root,index,count) && isMaxOrder(root));
}

//Merge Two heap

vector<int> mergeTwoHeap(vector<int> heap1,vector<int> heap2){
    vector<int> heap3;
    for(auto i : heap1){
        heap3.push_back(i);
    }
    for(auto i : heap2){
        heap3.push_back(i);
    }
    int size=heap3.size();
    for(int i=size/2;i>=1;i--){
        heapify(heap3,i,size);
    }
}

// Min Cost
int findMinCostOfRopes(vector<int> heap1){
    if(heap1.size()==0){
        return 0;
    }
    priority_queue< int , vector<int> , greater<int> > pq;
    for(auto i:heap1){
        pq.push(i);
    }
    int cost=0;
    int total=0;
    while (pq.size()>1){
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        cost=first+second;
        total=total+cost;
        pq.push(cost);
    }
    return total;
}

// BST to Heap
void preOrderFill(node* root,queue<int> ans){
    if(root==NULL){
        return;
    }
    root->data=ans.front();
    ans.pop();
    preOrderFill(root->left,ans);
    preOrderFill(root->right,ans); 
}
void InOrder(node* root, queue<int> &ans){
    if(root==NULL){
        return;
    }
    InOrder(root->left,ans);
    ans.push(root->data);
    InOrder(root->right,ans);
}

node* BSTToHeap(node* root){
    if(root==NULL){
        return NULL;
    }
    queue<int> nodes;
    InOrder(root,nodes);
    preOrderFill(root,nodes);
    return root;
}

//kth largest sum subarray
int kThLargestSumSubarray(vector<int> que,int k){
    if(que.size()==0){
        return 0;
    }
    priority_queue<int , vector<int> , greater<int> > pq;
    int size=que.size();
    for(int i=0;i<size;i++){
        int sum=0;
        for(int j=i;j<size;j++){
            sum=sum+que[j];
            if(pq.size()<k){
                pq.push(sum);
            }
            else{
                if(pq.top() < sum){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}

//  You have been given 'K' different arrays/ligts, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order. NEED TO REVISE THIS QUESTION

class Node{
    public:
        int data;
        int i;
        int j;
        Node(int data,int i,int j){
            this->data=data;
            this->i=i;
            this->j=j;
        }
};

class compare{
    public:
    bool operator()( Node* first,Node* second){
        return first->data > second->data;
    }
};
vector<int> mergeKSortedArray(vector<vector<int>> arr,int k){
    priority_queue<Node* , vector<Node*> , compare> pq;
    for(int i=0;i<k;i++){
        Node* temp = new Node(arr[i][0],i,0);
        pq.push(temp);
    }
    vector<int> ans;
    while(pq.size()>0){
        Node* temp=pq.top();
        ans.push_back(temp->data);
        pq.pop();
        int j=temp->j;
        int i=temp->i;
        if(j+1 < arr[i].size()){
            Node* thisOne=new Node(arr[i][j+1],i,j+1);
            pq.push(thisOne);
        }
    }
    return ans;
}

// Merge k sorted lists
// Given 'K' sorted linked lists, each list is sorted in increasing order. You need to merge all these lists into one single sorted list. You need to return the head of the final linked list.

class NODE{
    public:
        int data;
        NODE* next;
        NODE(int data){
            next=NULL;
            this->data=data;
        }
};

class comp{
    public:
        bool operator()(NODE *first , NODE *second){
            return first->data>second->data;
        }
};

NODE* MergeKSortedLinkedList(vector<NODE*> arr , int k){
    priority_queue<NODE* , vector<NODE*> , comp > pq;
    for(int i=0;i<k;i++){
        if(arr[i] != NULL){
            pq.push(arr[i]);
        }
    }
    NODE* ans=NULL;
    NODE* ansHead=NULL;
    while(pq.size()>0){
        NODE* temp=pq.top();
        pq.pop();
        if(ans==NULL){
            ans=temp;
            ansHead=temp;
        }
        else{
            ans->next=temp;
            ans=ans->next;
        }
        if(ans->next!=NULL){
            pq.push(ans->next);
        }
    }
    return ansHead;
}

pair<int,int> range(vector<NODE*> arr , int k){
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0;i<k;i++){
        if(arr[i]->data < min){
            min=arr[i]->data;
        }
        if(arr[i]->data > max){
            max=arr[i]->data;
        }
    }
    return make_pair(min,max);
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
    
    vector<int> arr{-1, 54, 53, 55, 52,50};
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

} 
