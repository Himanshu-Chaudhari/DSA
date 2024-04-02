#include <iostream>
#include<map>
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

void morrisTraversal(node* root){
    if(root==NULL){
        return;
    }
    node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" , ";
            curr=curr->right;
        }
        else{
            node* pre=curr->left;
            while (pre->right!=NULL && pre->right != curr){
                pre = pre->right;
            }
            if(pre->right==NULL){
                pre->right=curr;
                curr=curr->left;
            }
            else {
                pre->right = NULL;
                cout << curr->data << " , ";
                curr = curr->right;
            }
        }
    }
}

node* flattenIntoLL(node* root){
    node* curr=root;
    while(curr!=NULL){
        if(curr->left){
            node* temp=curr->left;
            while (temp->right){
                temp=temp->right;
            }
            temp->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right; 
    }
    return root;
}

int main(){
    node* root=createTree(root);
    // morrisTraversal(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    root=flattenIntoLL(root);
    while(root->right!=NULL){
        cout<<root->data<<" , ";
        root=root->right;
    }
}