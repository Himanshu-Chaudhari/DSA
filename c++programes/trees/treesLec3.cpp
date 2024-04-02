#include<iostream>
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

void solve(node* root,int sum,int &maxSum,int len,int &maxLen){
    if(root==NULL){
        if(len>maxLen){
            maxLen=len;
            maxSum=sum;
        }
        else if(len==maxLen){
            maxSum=max(maxSum,sum);
        }
        return;
    }
    sum+=root->data;
    solve(root->left,sum,maxSum,len+1,maxLen);
    solve(root->right,sum,maxSum,len+1,maxLen);
}
int sum0fLongRootToLeafPath(node* root){
    if(root==NULL){
        return 0;
    }
    int maxSum=INT_MIN;
    int len=0;
    int maxLen=0;
    int sum=0;
    solve(root,sum,maxSum,len,maxLen);
    return maxSum;
}

node* leastCommomAncestor(node* root, int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }

    node* leftAns=leastCommomAncestor(root->left,n1,n2);
    node* rightAns=leastCommomAncestor(root->right,n1,n2);

    if(leftAns !=NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }
    else if(rightAns==NULL && leftAns != NULL){
        return leftAns;
    }
    else{
        return NULL;
    }
}

node* solveK(node* root,int &k,int n){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n){
        return root;
    }
    node* leftAns=solveK(root->left,k,n);
    node* rightAns=solveK(root->left,k,n);

    if(leftAns!=NULL && rightAns==NULL){
        k--;
        if(k<=0){
            //Ans locked
            k=INT_MAX;
            return root;
        }
        return leftAns;
    }

    if(leftAns==NULL && rightAns!=NULL){
        k--;
        if(k<=0){
            //Ans locked
            k=INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}


int kthAncestor(node* root,int &k,int n){
    node* ans=solveK(root,k,n);
    if(ans==NULL || ans->data==n){
        return -1;
    }
    else{
        return root->data;
    }  
}

void solveThis(node* root,int sum,int &maxSum,int len , int &maxLen){
    if(root==NULL){
        if (len>maxLen){
            maxLen=len;
            maxSum=sum;
        }
        if(len==maxLen){
            maxSum=max(sum,maxSum);
        }
        return;
    }
    sum=sum+root->data;
    solveThis(root->left,sum,maxSum,len+1,maxLen);
    solveThis(root->right,sum,maxSum,len+1,maxLen);
}

int sumOfLongestPathFromRootToLeaf(node* root){
    if(root==NULL){
        return 0;
    }
    int sum=0;
    int maxSum=INT_MIN;
    int len=0;
    int maxLen=0;
    solveThis(root,sum,maxSum,len,maxLen);
    return maxSum;
}

node* LCA(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node* leftAns=LCA(root->left,n1,n2);
    node* rightAns=LCA(root->right,n1,n2);

    if(leftAns==NULL && rightAns==NULL){
        return NULL;
    }
    else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }
    else if(rightAns==NULL && leftAns!=NULL){
        return leftAns;
    }
    else{
        return root;
    }
}

int main(){
    node* root;
    root=createTree(root);
    inorder(root);
    // int ans=sum0fLongRootToLeafPath(root);
    // cout<<endl<<ans<<endl;
    node* ans=leastCommomAncestor(root,7,11);
    cout<<endl<<ans->data<<endl;
    cout<<endl<<sumOfLongestPathFromRootToLeaf(root)<<endl;
    cout<<LCA(root,7,11)->data<<endl;
    return 0;
}