#include<iostream>
#include<queue>
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
        this->right=NULL;
    }
};

node* createTree(node* root){
    cout<<"Please insert the data"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Please enter the element to insert at the left of "<<data<<endl;
    root->left=createTree(root->left);
    cout<<"Please enter the element to insert at the right of "<<data<<endl;
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
}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int lefth=height(root->left);
    int righth=height(root->right);
    int h=max(lefth,righth);
    return h+1;
}

bool balanced(node* root){
    if(root == NULL){
        return true;
    }
    bool l=balanced(root->left);
    bool r=balanced(root->right);
    bool h=abs(height(root->left)-height(root->right))>=1;
    if((l && r ) && h){
        return true;
    }
    else{
        return false;
    }
}

bool checkSame(node *root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL && root2!=NULL){
        return false;
    }
    if(root1!=NULL && root2==NULL){
        return false;
    }
    bool left=checkSame(root1->left,root2->left);
    bool right=checkSame(root1->right,root2->right);
    if(left && right && (root1->data==root2->data)){
        return true;
    }
    else{
        return false;
    }  
}

void leftSubtree(node *root){
    if((root->left==NULL && root->right==NULL) || root==NULL){
        return;
    }
    if(root->left==NULL && root->right != NULL){
        cout<<root->data<<" , ";
        leftSubtree(root->right);
    }
    else{
        cout<<root->data<<" , ";
        leftSubtree(root->left);
    }
}

void rightSubtree(node* root){
    if((root->right==NULL && root->left==NULL) || root==NULL){
        return ;
    }
    if(root->right==NULL && root->left!=NULL){
        rightSubtree(root->left);
        cout<<root->data<<" , ";
    }else{
        rightSubtree(root->right);
        cout<<root->data<<" , ";   
    }
    
}

void leafNodes(node* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" , ";
    }
    leafNodes(root->left);
    leafNodes(root->right);
}

void boundary(node* root){
    // cout<<root->data<<endl;
    if(root==NULL){
        return;
    }
    cout<<root->data<<" , ";
    leftSubtree(root->left);
    leafNodes(root->left);
    leafNodes(root->right);
    rightSubtree(root->right);
    
}
int diameter(node* root){

    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return left+right+1;
}

void levelOrder(node* root){
    if(root==NULL){
        return;
    }
    queue<node*> store;
    bool leftToRight=true;
    store.push(root);
    store.push(NULL);
    while(!store.empty()){
        
        node* temp=store.front();
        if(temp==NULL){
            leftToRight=false;
        }
        cout<<temp->data<<" , ";
        store.pop();
        if(temp->left){
            store.push(temp->left);
        }
        if(temp->right){
            store.push(temp->right);
        }
    }
}

vector<int> vertical(node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    // <level , <co-ordinate , ans> >
    map<int, map<int,vector<int> > > store;
    // <node , < level , co-ordinate> >
    queue<pair<node* , pair<int,int> > > q;
    
    q.push(make_pair(root,make_pair(0,0)));
    while (!q.empty()){
        pair<node* , pair<int , int> > temp = q.front();
        q.pop();

        node* r=temp.first;
        int lvl=temp.second.first;
        int co=temp.second.second;

        store[lvl][co].push_back(r->data);

        if(r->left){
            q.push(make_pair(r->left,make_pair(lvl+1,co-1)));
        }
        if(r->right){
            q.push(make_pair(r->right,make_pair(lvl+1,co+1)));
        }
    }
    
    for (auto i: store){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;

}

vector<int> topView(node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    map<int,int> topNode;
    queue<pair<node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp=q.front();
        q.pop();
        node* store=temp.first;
        int co=temp.second;

        // Finds entry in whole map and returns the last element of the map if entry is not present
        if(topNode.find(co)==topNode.end()){
            topNode[co]=store->data;
        }
        if(store->left){
            q.push(make_pair(store->left,co-1));
        }
        if(store->right){
            q.push(make_pair(store->right,co+1));
        }

    }
    for(auto i:topNode){
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> BottomView(node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    map<int,int> topNode;
    queue<pair<node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp=q.front();
        q.pop();
        node* store=temp.first;
        int co=temp.second;

        // Finds entry in whole map and returns the last element of the map if entry is not present
        
        topNode[co]=store->data;
        
        if(store->left){
            q.push(make_pair(store->left,co-1));
        }
        if(store->right){
            q.push(make_pair(store->right,co+1));
        }

    }
    for(auto i:topNode){
        ans.push_back(i.second);
    }
    return ans;
}

void solve(node* root,int lvl,vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(ans.size()==lvl){
        ans.push_back(root->data);
    }
    solve(root->right,lvl+1,ans);
    solve(root->left,lvl+1,ans);
}
vector<int> RightView(node* root){
    vector<int> ans;
    
    if(root==NULL){
        return ans;
    }
    solve(root,0,ans);
    return ans;
}


void solve1(node* root,int lvl,vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(ans.size()==lvl){
        ans.push_back(root->data);
    }
    solve(root->left,lvl+1,ans);
    solve(root->right,lvl+1,ans);
}
vector<int> leftView(node* root){
    vector<int> ans;
    
    if(root==NULL){
        return ans;
    }
    solve1(root,0,ans);
    return ans;
}

    


int main(){
    node* root=createTree(root);
    // cout<<root->data<<endl;
    inorder(root);
    // cout<<root->data<<endl;
    // cout<<endl<<height(root)<<endl;
    // cout<<root->data<<endl;
    // cout<<balanced(root)<<endl;
    // cout<<endl<<checkSame(root,root)<<endl;
    // boundary(root);
    // cout<<endl<<diameter(root)<<endl;
    // levelOrder(root);
    // cout<<endl<<root->data<<endl;
    // vector<int> ans=vertical(root);
    // cout<<endl;
    // for(auto i: ans){
    //     cout<<i<<" , ";
    // }
    // vector<int> ans=BottomView(root);
    // vector<int> ans2=topView(root);
    // vector<int> ans2=leftView(root);
    // vector<int> ans2=RightView(root);
    // for(auto i:ans2){
    //     cout<<i<<" ";
    // }
    // return 0;
}