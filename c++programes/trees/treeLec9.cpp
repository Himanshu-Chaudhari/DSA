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
        }
};

node* InsertNode(node* root,int data){
    if(root==NULL){
        root=new node(data);
        return root;
    }
    if(root->data > data){
        root->left=InsertNode(root->left,data);
    }
    else{
        root->right=InsertNode(root->right,data);
    }
    return root;
}

node* createBST(node* root){
    int data;
    cout<<"Please enter the data to Insert";
    cin >> data;
    while(data != -1){
        root=InsertNode(root,data);
        cout<<"Please enter the data to Insert";
        cin >> data;
    }
    return root;
}

void preOrder(node* root,vector<int>& store){
    if(root==NULL){
        return;
    }
    store.push_back(root->data);
    preOrder(root->left,store);
    preOrder(root->right,store);
}

void printBST(node* root){
    queue<node*> q;
    q.push(root);
    while (!q.empty()){
        int size=q.size();
        while(size>0){
            node* front=q.front();
            q.pop();
            cout<<front->data<<" , ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
            size--;
        }
        cout<<endl;
    }
}

// -----------------------Que Approach 1--------------------------

void inOrder(node* root,vector<int> &inOrderVal){
    if(root==NULL){
        return;
    }
    inOrder(root->left,inOrderVal);
    inOrderVal.push_back(root->data);
    inOrder(root->right,inOrderVal);
}

vector<int> mergeArray(vector<int> &bst1,vector<int> &bst2){
    vector<int> merged;
    int i=0;
    int j=0;
    while(i<bst1.size() && j<bst2.size()){
        if(bst1[i]==bst2[j]){
            merged.push_back(bst1[i++]);
            merged.push_back(bst2[j++]);
        }
        if(bst1[i]<bst2[j]){
            merged.push_back(bst1[i++]);
        }
        if(bst1[i]>bst2[j]){
            merged.push_back(bst2[j++]);
        }
    }
    while(i<bst1.size()){
        merged.push_back(bst1[i++]);
    }
    while (j<bst2.size()){
        merged.push_back(bst2[j++]);  
    }
    return merged;
}

node* inOrderToBST(int s,int e, vector<int> &in){
    if(s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    node* root=new node(in[mid]);
    root->left=inOrderToBST(s,mid-1,in);
    root->right=inOrderToBST(mid+1,e,in);
    return root;
}

node* mergeTwoBST(node* root1,node* root2){
    vector<int> bst1,bst2;
    inOrder(root1,bst1);
    inOrder(root2,bst2);
    vector<int> mergedArray=mergeArray(bst1,bst2);
    node* root=inOrderToBST(0,mergedArray.size()-1,mergedArray);
    return root;
}

// ----------------Aproach 2---------------------

void convertToSortedDDL(node* root,node* &head){
    if(root==NULL){
        return;
    }
    convertToSortedDDL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    convertToSortedDDL(root->left,head);
}

int cntNodes(node* head){
    int cnt=0;
    node* temp=head;
    while (temp!=NULL)
    {
        cnt++;
        temp=temp->right;
    }
    return cnt;

}
node* sortedLLToBST(node* head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    node* left=sortedLLToBST(head,n/2);
    node* root=head;
    root->left=left;
    head=head->right;
    root->right=sortedLLToBST(head,n-n/2-1);
    return root;

}
node* mergeTwoLL(node* root1,node* root2){
    node* head=NULL;
    node* tail=NULL;
    while (root1!=NULL && root2!=NULL){
        if(root1->data<root2->data){
            if(head==NULL){
                head=root1;
                tail=root1;
                root1=root1->right;
            }
            else{
                tail->right=root1;
                root1->left=tail;
                tail=root1;
                root1=root1->right;

            }
        }
        else{
            if(head==NULL){
                head=root2;
                tail=root2;
                root2=root2->right;
            }
            else{
                tail->right=root2;
                root2->left=tail;
                tail=root2;
                root2=root2->right;

            }
        }

    }
    while (root1!=NULL){
        tail->right=root1;
        root1->left=tail;
        tail=root1;
        root1=root1->right;
    }
    while (root2!=NULL){
        tail->right=root2;
        root2->left=tail;
        tail=root2;
        root2=root2->right;
    }
    return head;
}

node* mergeTwoBST2(node* root1,node* root2){
    // Step1 : convert BST to sorted DLL
    node* head1=NULL;
    convertToSortedDDL(root1,head1);
    head1->left=NULL;
    node* head2=NULL;
    convertToSortedDDL(root2,head2);
    head2->left=NULL;
    //merge two sorted LL
    node* head=mergeTwoLL(head1,head2);
    //convert LL into BST
    return sortedLLToBST(head,cntNodes(head));
}

int main(){
    node* root1=NULL;
    node* root2=NULL;
    cout<<"Please enter the first BST"<<endl;
    root1=createBST(root1);
    cout<<endl<<"Please enter the second BST"<<endl;
    root2=createBST(root2);
    node* root=mergeTwoBST(root1,root2);
    printBST(root);
}