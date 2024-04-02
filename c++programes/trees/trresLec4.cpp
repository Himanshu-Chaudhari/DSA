#include<iostream>
#include<map>
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

void postOrder(node* root){
        if(root==NULL){
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
         cout<<root->data<<" ";
    }

// int findIndex(int in[],int ele,int n){
//     for(int i=0;i<n;i++){
//         if(in[i]==ele){
//             return i;
//         }
//     }
//     return -1;
// }

// node* buildTree(int in[],int pre[],int &pOI,int start,int end,int size){
//     if( pOI>=size || start>end ){
//         return NULL;
//     }
//     int ele=pre[pOI++];
//     node* root=new node(ele);
//     int index= findIndex(in,ele,size);
//     root->left=buildTree(in,pre,pOI,start,index-1,size);
//     root->right=buildTree(in,pre,pOI,index+1,end,size);
//     return root;
// }


void createMapping(int in[],map<int,int> &maping,int size){
    for(int i=0;i<size;i++){
        maping[in[i]]=i;
    }
}
node* buildTree(int in[],int post[],int &pOI,int start,int end,int size,map<int,int> &maping){
    if(pOI < 0 || start>end){
        return NULL;
    }
    int ele=post[pOI--];
    int index=maping[ele];
    node* root=new node(ele);

    root->right=buildTree(in,post,pOI,index+1,end,size,maping);
    root->left=buildTree(in,post,pOI,start,index-1,size,maping);
    return root;
}

int main(){
    // node* root;
    // int in[]={7,3,11,1,17,5};
    // int pre[]={1,3,7,11,5,17};
    // int preOrderIndex=0;
    // int n=6;
    // node* root=buildTree(in,pre,preOrderIndex,0,n-1,n);
    // postOrder(root);

    int in[]={9,3,15,20,7};
    int post[]={9,15,7,20,3};
    int pOI=4;

    map<int,int> maping;
    createMapping(in,maping,5);
    node* root=buildTree(in,post,pOI,0,4,5,maping);
    postOrder(root);
    return 0;
}