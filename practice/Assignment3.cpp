#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left,*right;
    int lth,rth;
    node(int data){
        this->data=data;
        lth=1;
        rth=1;
    }
};

class TBT{
    public:
        node *root,*dummy;
        TBT(){
            root=NULL;
            dummy=new node(-1);
            dummy->rth=0;
            dummy->lth=1;
            dummy->left=dummy;
            dummy->right=dummy;
        }
        void insertNode(){
            cout<<"Enter data of new node :";
            int data;
            cin>>data;
            node* newnode=new node(data);

            if(dummy->lth){
                root=newnode;
                root->left=dummy;
                root->right=dummy;
                dummy->left=root;
                dummy->lth=0;
            }
            else{
                insert(root,newnode);
            }
        }

        void insert(node* root,node* newnode){
            if(root->data > newnode->data){
                if(root->lth==1){
                    newnode->lth=root->lth;
                    newnode->left=root->left;
                    newnode->right=root;
                    newnode->rth=1;
                    root->left=newnode;
                    root->lth=0;
                }
                else{
                    insert(root->left,newnode);
                }
            }
            else{
                if(root->rth==1){
                    newnode->rth=root->rth;
                    newnode->right=root->right;
                    newnode->left=root;
                    newnode->lth=1;
                    root->right=newnode;
                    root->rth=0;
                }
                else{
                    insert(root->right,newnode);
                }
            }
        }

        node* pre_succ(node* p){
            if(p->lth==0){
                return(p->left);
            }
            while(p->rth==1){
                p=p->right;
            }
            return (p->right);

        }
        void preorder(node* T){
            node* head;
            head=T;
            T=T->left;
            while(T->left!=head){
                cout<<T->data<<" , ";
                T=pre_succ(T);
            }
        }
        void pre(){
            preorder(dummy);
        }

        node* in_succ(node* i){
            if(i->rth==1){
                return (i->right);
            }
            while(i->lth==0){
                i=i->left;
            }
            return i;
        }
        void inorder(node* T){
            node* head=T;
            T=T->left;
            while(T->lth == 0){
                T=T->left;
            }
            while(T != head){
                cout<<T->data<<" , ";
                T=in_succ(T);
            }
        }
        void in(){
            inorder(dummy);
        }
};

int main(){
    return 0;
}