#include <iostream>
using namespace std;

class NodeCLL
{
public:
    int data;
    NodeCLL *next;
    NodeCLL(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~NodeCLL()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "deleted " << value << endl;
    }
};

void insertNode(NodeCLL *&tail, int element, int d)
{
    // empty list
    if (tail == NULL)
    {
        NodeCLL *newnode = new NodeCLL(d);
        tail = newnode;
        newnode->next = newnode;
    }
    else{
        NodeCLL *current=tail;
        while(current-> data != element){
            current=current->next;
        }
        NodeCLL* temp=new NodeCLL(d);
        temp->next=current->next;
        current->next=temp;
    }
}


void delete1(NodeCLL* &tail,int d){
    //empty ll
    if(tail == NULL){
        return;
    }
    else{
        NodeCLL* previous=tail;
        NodeCLL* current=previous->next;
        if(current==previous){
            tail=NULL;
        }
        while (current->data != d)
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
        
        if(tail==current){
            tail=previous;
        }
        current->next=NULL;
        delete current;
    }
}

void print(NodeCLL* tail){
    if(tail==NULL){
        cout<<"empty ll"<<endl;
        return;
    }
    NodeCLL* temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail != temp);
    cout<<endl;
    cout<<endl;
}

int main()
{

    // Circular linked list doesnt requires head pointer , all the operations can be performed using last(End) pointer
    // as CLL is circular it doest has a starting and end point

    NodeCLL* tail =NULL;
    insertNode(tail,5,2);
    print(tail);
    
    insertNode(tail,2,5);
    print(tail);

    insertNode(tail,5,4);
    print(tail);

    insertNode(tail,2,89);
    print(tail);

    insertNode(tail,2,67);
    print(tail);


    delete1(tail,2);
    print(tail);

    delete1(tail,67);
    print(tail);

    delete1(tail,4);
    print(tail);

    return 0;
}