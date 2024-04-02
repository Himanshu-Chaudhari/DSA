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


//creates mapping and return target node 
node* createParentMapping(node* root,int target,map<node* ,node*> &nodeToParent){
    node* res=NULL;
    queue<node*> q;
    q.push(root);
    while (!q.empty()){
        node* front=q.front();
        q.pop();

        if(front->data==target){
            res=front;
        }
        if(front->left){
            nodeToParent[front->left]=front;
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right]=front;
            q.push(front->right);
        }   
    }
    return res;
}

int burnTree(node* root,node* targetNode, map<node*,node*> nodeToParent){
    map<node* ,bool> visited;
    queue<node*> q;

    q.push(root);
    visited[root]=true;
    int ans=0;
    while(!q.empty()){
        bool flag=0;
        int size=q.size();
        for(int i=0;i<size;i++){
            // process neighbour node
            node* front=q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag=1;
                q.push(front->left);
                visited[front->left]=1;
            }

            if(front->right && !visited[front->right]){
                flag=1;
                q.push(front->right);
                visited[front->right]=1;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag=1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]]=1;
            }

        }
        if(flag==1){
            ans++;
        }
    }
    return ans;
}

int minTimeToBurn(node* root,int target){
    // //Algo:
    // Step 1: Create nodeToParent createParentMapping
    // Step 2: Find target node
    // Step 3: Burn tree in min time

    
    map<node* ,node*> nodeToParent;
    node* targetNode=createParentMapping(root,target,nodeToParent);

    int ans=burnTree(root,targetNode,nodeToParent);
    return ans;

}
int main(){
    node* root;
    root=createTree(root);
    cout<<minTimeToBurn(root,17);
    return 0; 
}