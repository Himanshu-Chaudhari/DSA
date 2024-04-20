#include<iostream>
#include <stack>
#include<queue>
using namespace std;

class Node{
    public:
        Node* left;
        Node* right;
        int data;
        Node(int data){
            this->data=data;
        }
};

void insert(Node* &root,int data){
    Node* temp=new Node(data);
    Node* store=NULL;
    Node* curr=root;
    if(root==NULL){
        root=temp;
        return;
    }
    while(curr!=NULL){
        store=curr;
        if(curr->data > temp->data){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
    if(store->data > temp->data){
        store->left=temp;
    }
    else{
        store->right=temp;
    }
}

void displayInorder(Node* root){
    if(root==NULL){
        return;
    }
    // stack<Node*> s;
    // // s.push(root);
    // Node* current=root;
    // while(!s.empty() || current != NULL){
    //     if(current != NULL){
    //         s.push(current);
    //         current=current->left;
    //     }
    //     else{
    //         current=s.top();
    //         s.pop();
    //         cout<<current->data<<" , ";
    //         current=current->right;
    //     }
    // }

    displayInorder(root->left);
    cout<<root->data<<" , ";
    displayInorder(root->right);

}

void search(Node* root,int key){
    if(root==NULL){
        return;
    }
    while(true){
        if(root->data ==key){
            cout<<"key found"<<endl;
            return;
        }
        if(root->data > key){
            root= root->left;
        }
        else{
            root=root->right;
        }
        if(root==NULL){
            cout<<"key not found"<<endl;
            break;
        }
    }

}
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;

}

Node* delete2(Node* root,int key){
    Node* temp;
    if(root==NULL){
        cout<<" key not found "<<endl;
        return root;
    }
    if(root->data > key){
        root->left=delete2(root->left,key);
        return root;
    }
    if(root->data < key){
        root->right=delete2(root->right,key);
        return root;
    }
    //key found
    //leaf node
    if(root->left==NULL && root->right==NULL){
        temp=root;
        free(temp);
        return NULL;
    }
    //only right child
    if(root->left==NULL){
        temp=root;
        root=root->right;
        free(temp);
        return root;
    }
    //only left child
    if(root->right==NULL){
        temp=root;
        root=root->left;
        free(temp);
        return root;
    }

    temp=root;
    
    while(temp->left){
        temp=temp->left;
    }

    root->data=temp->data;
    root->right=delete2(root->right,temp->data);
    return root;


    temp=root->right;

    while(temp->left != NULL){
        temp=temp->left;
    }
    root->data=temp->data;
    root->right=delete2(root->right,temp->data);
    return root;

}
// void levelOrderTraversal(Node* root){
//     if(root==NULL){
//         return;
//     }
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty()){
//         Node* curr=q.front();
//         cout<<curr->data<<" , ";
//         q.pop();
//         if(curr->left){
//             q.push(curr->left);
//         }
//         if(curr->right){
//             q.push(curr->right);
//         }
//     }
// }

void levelOrderTransversal(Node* root){
    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        
        q.pop();

        if(temp==NULL){
            //complete traversal of last level is done
            cout<<endl;
            
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node* mirror(Node* root){
    if( root==NULL ){
        return root;
    }
    Node* temp=new Node(root->data);
    temp->right=mirror(root->left);
    temp->left=mirror(root->right);
    return temp;
}

int main(){
    Node* root=NULL;
    insert(root,11);
    insert(root,5);
    insert(root,13);
    insert(root,1);
    insert(root,112);
    insert(root,10);
    //cout<<root->data;
   // displayInorder(root);
    search(root,112);
    cout<<height(root)<<endl<<endl;
    levelOrderTransversal(root);
    cout<<endl;
    //root=mirror(root);
    levelOrderTransversal(root);
    cout<<endl;
    root=delete2(root,112);

    levelOrderTransversal(root);
    return 0;
}