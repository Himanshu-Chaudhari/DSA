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

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" , ";
    inorder(root->right);
    // cout<<endl;
}

// class list{
//     public:
//         int max;
//         int min;
//         bool isBST;
//         int size;
// };

class info{
    public:
        int max;
        int min;
        bool isBST;
        int size;
        
};

info largestBST(node* root,int& ans){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }

    info left=largestBST(root->left,ans);
    info right=largestBST(root->right,ans);

    info curr;
    curr.size=left.size+right.size+1;
    curr.max=max(right.max,root->data);
    curr.min=min(root->data,left.min);
    if(left.isBST && right.isBST && root->data>left.max && root->data<right.min){
        curr.isBST=true;
    }
    else{
        curr.isBST=false;
    }
    if(curr.isBST){
        ans=max(ans,curr.size);
    }
    return curr;
    
    
}

int main(){
    node* root=createTree(root);
    int ans=0;
    info a=largestBST(root,ans);
    cout<<endl;
    cout<< ans;
    return 0;
}