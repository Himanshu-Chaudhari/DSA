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
            left=NULL;
            right=NULL;
        }
};

node* createTree(node* root){
    
    cout<<"Please enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter the data for inserting data in left of "<<data<<endl;
    root->left = createTree(root->left);

    cout<<"Enter the data for inserting data in right of "<<data<<endl;
    root->right = createTree(root->right);

    return root;
}

void levelOrderTransversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();
        
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
void postOrder(node* root){
        if(root==NULL){
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }

    void preOrder(node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" "   ;
        preOrder(root->left);
        preOrder(root->right);
    }

    void Inorder(node* root){
        if(root==NULL){
            return;
        }
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }

    node* mirrorOfTree(node* root){
        if(root==NULL)
            return NULL;
        node* temp=new node(root->data);
        temp->left=mirrorOfTree(root->right);
        temp->right=mirrorOfTree(root->left);

        return temp;
    }



int main(){
    node* root =NULL;

    root=createTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<endl<<"Level order traversal"<<endl;
    levelOrderTransversal(root);

    Inorder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;

    root=mirrorOfTree(root);
    levelOrderTransversal(root);
    return 0;
}