
#include<iostream>
using namespace std;
//dll 

class NodeDLL{
    public:
        int data;
        NodeDLL* next;
        NodeDLL* prev;
        NodeDLL(int data){
            this->data=data;
            next=NULL;
            prev=NULL;
        }
        ~NodeDLL(){
            int value=this->data;
            if(next != NULL){
                delete next;
                next=NULL;
            }
            cout<<"deleted "<<value<<endl;
        }
};

void InsertAtHead(NodeDLL* &head,int data){

    NodeDLL* temp=new NodeDLL(data);
    if(head == NULL){
        head=temp;
        return;
    }

    temp->next=head; 
    head->prev=temp; 
    head=temp;
}

void InsertAtEnd(NodeDLL* head,int data){
    NodeDLL* temp=new NodeDLL(data);
    if(head==NULL){
        head=temp;
        return;
    }
    NodeDLL* temp1=head;
    while((temp1->next) != NULL){
        temp1=temp1->next;
    }
    temp1->next=temp;
    temp->prev=temp1;
}

//insert at end using external pointer tail pointing the end
// void insertatend(NodeDLL* &last,int data){
//     NodeDLL *temp=new NodeDLL(data);
//     last->next=temp;
//     temp->prev=last;
//     last=temp; 
// }

void InsertAtMiddle(NodeDLL* head,int position,int data){
    if(position==1){
        InsertAtHead(head,data);
        return;
    }
    int cnt=1;
    NodeDLL* temp=head;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        InsertAtEnd(head,data);
        return;
    }
    NodeDLL *insert=new NodeDLL(data);
    insert->next=temp->next;
    (temp->next)->prev=insert;
    temp->next=insert;
    insert->prev=temp;

}

void DeleteThis(NodeDLL* &head,int data){
    NodeDLL *current=head;
    NodeDLL *previous=NULL;
    if(current->data==data){
        (head->next)->prev=NULL;
        head=head->next;
        current->next=NULL;
        delete current;
        return;
    }

    while(current->data != data){
        previous=current;
        current=current->next;
    }
    if(current->next==NULL){
        delete current;
        previous->next=NULL;
        return;
    }
    (current->next)->prev=previous;
    previous->next=current->next;
    delete current;

}

void printReverse(NodeDLL* head){
    while(head->next != NULL){
        head=head->next;
    }
    while(head->prev!=NULL){
        cout<<head->data<<"  ";
        head=head->prev;
    }
    cout<<head->data;
    cout<<endl<<endl;
}

void printDLL(NodeDLL* head){
    cout<<endl;
    while(head != NULL){
        cout<<head->data<<"  ";
        head=head->next;
    }
    cout<<endl;
}


int main(){

    NodeDLL* node2=new NodeDLL(5);
    // NodeDLL* last=node2;

    InsertAtHead(node2,4);
    printDLL(node2);
    printReverse(node2);

    InsertAtEnd(node2,8);
    printDLL(node2);
    printReverse(node2);

    InsertAtEnd(node2,9);
    printDLL(node2);  
    printReverse(node2);

    InsertAtMiddle(node2,2,3);
    printDLL(node2);  
    printReverse(node2);
    
    InsertAtMiddle(node2,2,3);
    printDLL(node2);
    printReverse(node2);

    DeleteThis(node2,8);
    printDLL(node2);
    printReverse(node2);

    DeleteThis(node2,5);
    printDLL(node2);
    printReverse(node2);

    DeleteThis(node2,4);
    printDLL(node2);
    printReverse(node2);  
}