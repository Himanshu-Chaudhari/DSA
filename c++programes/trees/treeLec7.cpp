//BST
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

void printBST(node* root){
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
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

bool search(node* root,int data){
    if(root==NULL){
        return false;
    }
    if(root->data==data){
        return true;
    }
    if(root->data>data){
        return search(root->left,data);
    }
        
    else{
        return search(root->right,data);
    }
        
    return false;
}

node* minVal(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}


node* deleteNode(node* root,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){

        // no child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 1child

        // left child
        if(root->left != NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }

        if(root->right!=NULL && root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL){
            int min =minVal(root->right)->data;
            root->data=min;
            root->right=deleteNode(root->right,min);
            return root;
        }

    }

    else if(root->data>data){
        root->left=deleteNode(root->left,data);
        return root;
    }

    else{
        root->right=deleteNode(root->right,data);
        return root;
    }
 
}
int main(){
    node* root=NULL;
    root=createBST(root);
    printBST(root);
    cout<<search(root,6);
    cout<<endl;
    root= deleteNode(root,6);
    printBST(root);
    return 0;
}