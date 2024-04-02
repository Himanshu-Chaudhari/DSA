#include<iostream>
using namespace std;

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
Node *reverser2(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *chotaHead = reverser2(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}

void insertAtTail(Node* &head,Node* &tail,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        head=tail=temp;
        return;
    }
    tail->next=temp;
    tail=tail->next;
}

Node* add(Node* first,Node* second){
    int carry=0;
    Node* ansHead=NULL;
    Node* ansTail=NULL;

    while(first != NULL || second != NULL || carry != 0){
        int val1=0;
        if(first != NULL){
            val1=first->data;
        }

        int val2=0;
        if(second != NULL){
            val2=second->data;
        }

        int sum= carry + val1 + val2;

        int digit= sum%10;

        insertAtTail(ansHead,ansTail,digit);

        carry=sum/10;

        if(first != NULL){
            first=first->next;
        }

        if(second != NULL){
            second=second->next;
        }

    }
    return ansHead;
}

Node* Add(Node* head1,Node* head2){
   
    head1=reverser2(head1);
    head2=reverser2(head2);
    
    Node* tail=add(head1,head2);

    tail=reverser2(tail);
    return tail;
}

void printSLL(Node* head){
    while(head != NULL){ 
        cout<<head->data<<"  ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    
    Node* head1=new Node(4);
    SLLInsertAtHead(head1,6);
    SLLInsertAtHead(head1,9);

    Node* head2=new Node(9);
    SLLInsertAtHead(head2,7);
    SLLInsertAtHead(head2,2);
    SLLInsertAtHead(head2,2);
    SLLInsertAtHead(head2,2);
    SLLInsertAtHead(head2,2);
    Node* output=Add(head1,head2);
    printSLL(output);
    return 0;
}