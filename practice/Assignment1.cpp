#include<iostream>
#include <stack>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;
        Node(int data){
            this->data=data;
        }
};


Node* createTree( Node* root){
    cout<<"Please enter the data"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
     cout<<"Enter the data for inserting data in left of "<<data<<endl;
    root->left = createTree(root->left);

    cout<<"Enter the data for inserting data in right of "<<data<<endl;
    root->right = createTree(root->right);
    return root;
}

void inorder_rec(Node* root){
    if(root==NULL){
        return;
    }
    inorder_rec(root->left);
    cout<<root->data<<" , ";
    inorder_rec(root->right);
}
void preorder_rec(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" , ";
    preorder_rec(root->left);
    preorder_rec(root->right);
}
void postorder_rec(Node* root){
    if(root==NULL){
        return;
    }
    postorder_rec(root->left);
    postorder_rec(root->right);
    cout<<root->data<<" , ";
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    stack<Node*> s;
    Node* curr=root;
    while (!s.empty() || curr!=NULL)
    {
         if (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }
        else {
            curr=s.top();
            s.pop();
            cout << curr->data << " , ";
            curr = curr->right;
        }
    }
}

void preorder(Node* root)
{
    // Base Case
    if (root == NULL)
        return;
    // Create an empty stack and push root to it
    stack<Node*> nodeStack;
    nodeStack.push(root);
    while (nodeStack.empty() == false) {
        // Pop the top item from stack and print it
        Node* node = nodeStack.top();
        cout<<node->data<<" , ";
        nodeStack.pop();
        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}
void postorder(Node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
    // create an empty stack and push the root node
    stack<Node*> s;
    s.push(root);
    // create another stack to store postorder traversal
    stack<int> out;
    // loop till stack is empty
    while (!s.empty()){
        // pop a node from the stack and push the data into the output stack
        Node* curr = s.top();
        s.pop();
        out.push(curr->data);
        // push the left and right child of the popped node into the stack
        if (curr->left) {
            s.push(curr->left);
        }
        if (curr->right) {
            s.push(curr->right);
        }
    }
    // print postorder traversal
    while (!out.empty()){
        cout << out.top() << " ";
        out.pop();
    }
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
int main(){
    
    Node* root;
    root=createTree(root);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}