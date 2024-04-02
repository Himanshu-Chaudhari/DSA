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

node* createTree(node *root){
    int d;
    cout<<"Please enter the data "<<endl;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* temp=new node(d);
    root=temp;
    cout<<"Please enter the data to the left of "<<d<<endl;
    root->left=createTree(root->left);
    cout<<"Please enter the data to the right of "<<d<<endl;
    root->right=createTree(root->right);
    return root;
}

int kthSmallestElement(int arr[],int size,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<size;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

//Is Binnary tree a heap

int countNodes(node* root){
    if(root==NULL){
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}

bool isMaxOrder(node* root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->right==NULL){
        return root->data>root->left->data;
    }
    bool leftAns=isMaxOrder(root->left);
    bool rightAns=isMaxOrder(root->right);
    return leftAns && rightAns && (root->data>root->left->data && root->data>root->right->data);
}

bool isCBT(node* root,int index,int count){
    if(root==NULL){
        return true;
    }
    if(index>=count){
        return false;
    }
    bool leftAns=isCBT(root->left,2*index+1,count);
    bool rightAns=isCBT(root->right,2*index+2,count);
    return leftAns && rightAns;
}

bool isHeap(node* root){
    int index=0;
    int cnt=countNodes(root);
    return (isCBT(root,index,cnt) && isMaxOrder(root));
}

// Merge two heaps
void heapify(vector<int> &arr,int index,int size){
    int largest=index;
    int leftChild=index*2+1;
    int rightChild=index*2+2;
    if(leftChild<size && arr[largest]<arr[leftChild]){
        largest=leftChild;
    }
    if(rightChild<size && arr[largest]<arr[rightChild]){
        largest=rightChild;
    }
    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,largest,size);
    }
}

vector<int> mergeTwoHeap( vector<int> tree1,vector<int> tree2){
    vector<int> tree3;
    for(auto i:tree1){
        tree3.push_back(i);
    }
    for(auto i:tree2){
        tree3.push_back(i);
    }
    int size=tree3.size();
    for(int i=size/2-1;i>=0;i--){
        heapify(tree3,i,size);
    }
    return tree3;
}

// Minimum cost of heap
int minCost(vector<int> heap){
    //create min heap 
    priority_queue< int , vector<int> , greater<int> > pq;
    for(auto i:heap){
        pq.push(i);
    }
    int cost=0;
    int sum=0;
    while(pq.size()>1){
        int ele1=pq.top();
        pq.pop();
        int ele2=pq.top();
        pq.pop();
        cost = ele1 + ele2;
        sum=sum+cost;
        pq.push(cost);
    }
    return sum;
}


int main(){
    // node* root=createTree(root);
    // cout<<isHeap(root);
    // vector<int> heap1{10, 5, 6, 2};
    // vector<int> heap2{12, 7, 9};
    // vector<int> ans=mergeTwoHeap(heap1,heap2);
    // for(auto i:ans){
    //     cout<<i<<" ";
    // }
    vector<int> ans{4, 2, 7, 6, 9};
    cout<<endl<<minCost(ans)<<endl;
    return 0;
}
// 20 10 4 -1 -1 3 -1 -1 16 -1 -1

