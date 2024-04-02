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


bool isBST(node* root,int max,int min){
    if(root==NULL){
        return true;
    }
    if(root->data<=max && root->data>=min){
        bool left=isBST(root->left,root->data,min);
        bool right=isBST(root->right,max,root->data);
        return left && right;
    }
    else{
        return false;
    }
    
}


int kSmallest(node* root,int &i,int k){
    if(root==NULL){
        return -1;
    }
    int left=kSmallest(root->left,i,k);

    if(left!=-1){
        return left;
    }

    i++;
    if(i==k){
        return root->data; 
    }

    return kSmallest(root->right,i,k);
}

pair<int , int> preSucc(node *root,int tar){

    node* temp=root;
    int pre=-1;
    int scc=-1;
    // sesrching target
    while(temp->data==tar){
        if (temp->data>tar){
            scc=temp->data;
            temp=temp->left;
        }
        else if(temp->data<tar){
            pre=temp->data;
            temp=temp->right;
        }
    }

    //finding pre
    node* leftTree=temp->left;
    while(leftTree!=NULL){
        pre=leftTree->data;
        leftTree=leftTree->right;
    }

    // finding succ
    node* rigthTree=temp->right;
    while(rigthTree!=NULL){
        scc=rigthTree->data;
        rigthTree=rigthTree->left;
    }

    return make_pair(pre,scc);

}

void inOrder(node* root,vector<int> &inOrderVal){
    if(root==NULL){
        return;
    }
    inOrder(root->left,inOrderVal);
    inOrderVal.push_back(root->data);
    inOrder(root->right,inOrderVal);
}

bool twoSumInBST(node* root, int tar){
    if(root==NULL){
        return false;
    }
    vector<int> inOrderVal;
    inOrder(root,inOrderVal);
    int s=0;
    int e=inOrderVal.size()-1;
    int sum=0;
    while(s<e){
        sum=inOrderVal[s]+inOrderVal[e];
        if(sum==tar){
            return true;
        }
        else if(sum>tar){
            e--;
        }
        else{
            s++;
        }
    }
    return false;
}

void inOrder2(node* root,vector<node*> &store){
    if(root==NULL){
        return;
    }
    inOrder2(root->left,store);
    store.push_back(root);
    inOrder2(root->right,store);
}

node* flattenBSTtoSortedLL(node* root){
    if(root==NULL){
        return NULL;
    }
    vector<node*> storeNode;
    inOrder2(root,storeNode);
    int size=storeNode.size();
    int i;
    node* newRoot=storeNode[0];

    for(i=0;i<size-1;i++){
        storeNode[i]->left=NULL;
        storeNode[i]->right=storeNode[i+1];
    }
    storeNode[i]->left=NULL;
    storeNode[i]->right=NULL;
    return newRoot;
}

node* solve(int s,int e,vector<int> &store){
    if(s>e){
        return NULL;
    }

    int mid=s+(e-s)/2;

    node* root=new node(store[mid]);
    root->left=solve(s,mid-1,store);
    root->right=solve(mid+1,e,store);
    return root;
}

node* convertToBalancedBST(node* root){
    if(root==NULL){
        return NULL;
    }

    vector<int> store;
    inOrder(root,store);
    root=solve(0,store.size()-1,store);
    return root;
}

node* POTBST(vector<int> pre,int minV,int maxV,int &POI){
    if(POI>=pre.size()){
        return NULL;
    }

    if(pre[POI]>maxV || pre[POI]<minV){
        return NULL;
    }

    node* root=new node(pre[POI++]);
    root->left=POTBST(pre,minV,root->data,POI);
    root->right=POTBST(pre,root->data,maxV,POI);
    return root;

}

 
node* preOrderToBST(vector<int> pre){
    int POI=0;
    return POTBST(pre,INT_MIN,INT_MAX,POI);
}
int main(){

    node* root=NULL;
    root=createBST(root);

    // cout<<isBST(root,INT_MAX,INT_MIN)<<endl;
    // int i=0;
    // cout<<kSmallest(root,i,4)<<endl;
    // pair<int,int> ans=preSucc(root,4);
    // cout<<ans.first<<" , "<<ans.second<<endl;
    // cout<<twoSumInBST(root,10)<<endl;
    // root=flattenBSTtoSortedLL(root);
    // while(root->right!=NULL){
    //     cout<<root->data<<" , ";
    //     root=root->right;
    // }
    // cout<<endl;

    vector<int> ans;
    preOrder(root,ans);

    root=preOrderToBST(ans);

    printBST(root);
}