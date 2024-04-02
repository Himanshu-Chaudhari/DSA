#include<iostream>
using namespace std;
//  singly linked list
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        ~Node(){
            int value=this->data;
            if(this->next != NULL){
                delete next;
                this->next=NULL;
            }
            cout<<"memory is free for node with value "<<value<<endl;
        }
};

void SLLInsertAtHead(Node* &head,int data){
    Node *temp=new Node(data);
    temp->next=head;
    head=temp;
}

void SLLInsertAtEnd(Node* head,int data){
    Node* temp=new Node(data);
    Node* traverse=head;
    while(traverse->next != NULL){
        traverse=traverse->next;
    }
    traverse->next=temp;
}

void SLLInsertAtMiddle(Node* head,int after,int data){
    Node* temp=new Node(data);
    Node* traverse=head;
    while(traverse->data != after){
        traverse=traverse->next;
    }
    temp->next=traverse->next;
    traverse->next=temp;
    
}

void deleteThisNode(Node* &head,int data){
    Node *temp;
    if(head->data==data){
        temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    temp=head;
    Node* temp1=NULL;
    while(temp->data != data){
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=temp->next;
    temp->next=NULL;
    delete temp;
}

void printSLL(Node* head){
    while(head != NULL){
        cout<<head->data<<"  ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{ 
    Node* node1=new Node(4);
    SLLInsertAtHead(node1,6);
    printSLL(node1);
    SLLInsertAtEnd(node1,7);
    printSLL(node1);
    SLLInsertAtMiddle(node1,4,9);
    printSLL(node1);
    deleteThisNode(node1,6);
    printSLL(node1);
    deleteThisNode(node1,9);
    printSLL(node1);
    deleteThisNode(node1,7);
    printSLL(node1);
    return 0;
} 
