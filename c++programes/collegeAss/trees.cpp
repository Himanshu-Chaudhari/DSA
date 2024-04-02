#include<iostream>
using namespace std;

class node{
    public:
        char data;
        node *left;
        node *right;
        node(int d){
            data=d;
            left=right=NULL;
        }
};

class stack{
    node *data[30];
    int top;
    public:
        stack(){top=1;}
        int empty(){
            if(top == -1){
                return 1;
            }
            return 0;
        }
        void push(node *p){
            data[++top]=p;
        }
        node *pop(){
            return(data[top--]);
        }
};

class tree{
        node* root;
    public:
        tree(){root = NULL;}
        void create();
        node* rootaval(){return root;}
        void preorder(node *T);
        void postorder(node *T);
        void inorder(node *T);
        // void non_rec_inorder();
        // void non_rec_preorder();
        // void non_rec_postorder();
};

void tree:: create(){
    char exp[30];
    node *temp, *temp1, *temp2;
    stack S;
    char ch;
    cout<<"Enter postfix expression"<<endl;
    cin>>exp;
    int i=0;
    while((ch=exp[i]) != '\0'){
        if(isalnum(ch)){
            temp=new node(ch);
            S.push(temp);
        }
        else{
            temp2=S.pop();
            temp1=S.pop();
            temp=new node(ch);
            temp->left=temp1;
            temp->right=temp2;
            S.push(temp);
        }
        i++;
    }
    root=S.pop();
};



void tree::preorder(node *T){
    if(T != NULL){
        cout<<" "<<T->data;
        preorder(T->left);
        preorder(T->right);
    }
}

void tree::inorder(node *T){
    if(T!=NULL){
        inorder(T->left);
        cout<<" "<<T->data;
        inorder(T->right);
    }
}

void tree:: postorder(node *T){
    if(T != NULL){
        postorder(T->left);
        postorder(T->right);
        cout<<" "<<T->data;
    }
}

// void tree::non_rec_inorder(){
    
// }
// void tree::non_rec_preorder(){

// }
// void tree::non_rec_postorder(){
//     stack s,s1;
//     node* T=root;
//     cout<<"/n";
//     while(T != NULL){
//         s.push(T);
//         s1.
//     }
// }



int main(){
    tree t1;
    node *root1;
    int x,op;
    do{
        cin>>op;
        switch(op){
            case 1:
                t1.create();
                root1=t1.rootaval();
                break;
            
            case 2:
                t1.preorder(root1);
                break;
            
            case 3:
                t1.inorder(root1);
                break;

            case 4:
                t1.postorder(root1);

            // case 5:
            //     t1.non_rec_inorder();
            //     break;
            
            // case 6:
            //     t1.non_rec_preorder();
            //     break;

            // case 7:
            //     t1.non_rec_postorder();
        }
    }while(op!=8);
}