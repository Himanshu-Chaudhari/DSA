#include <iostream>
#include <map>
#include<vector>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void SLLInsertAtHead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

// REVERSE A LINKED LIST
void reverser1(node *&head, node *curr, node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    reverser1(head, curr->next, curr);
    curr->next = prev;
}

node *reverser2(node *&head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *chotaHead = reverser2(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}

void reverse(node *&head)
{
    node *current = head;
    node *prev = NULL;
    node *forward = NULL;
    //  node* next = NULL;
    while (current != NULL)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    head = prev;
}

// MIDDLE OF A LINKED LIST

node *Middle(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (head->next->next == NULL)
    {
        return head->next;
    }
    int cnt = 0;
    node *temp = head;
    while (head != NULL)
    {
        head = head->next;
        cnt++;
    }
    head = temp;
    int cnt2 = cnt;
    while (cnt - 1 != cnt2 / 2)
    {
        head = head->next;
        cnt--;
    }
    return head;
}

node *middle2(node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    if (head->next->next == NULL)
    {
        return head->next;
    }

    node *slow = head;
    node *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow;
}

node *reverseALinkedListInAGroupOfK(node *head, int k){
    // base case
    if (head == NULL){
        return NULL;
    }

    // step1: reverse 1st k nodes
    node *next = NULL;
    node *curr = head;
    node *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step2: baki recursion dekh lega
    if (next != NULL){
        head->next = reverseALinkedListInAGroupOfK(next, k);
    }

    // step 3: return head of reversed linked list
    return prev;
}

bool isCircular(node *head){
    if (head == NULL){
        return false;
    }
    node *temp = head->next;
    while (temp != NULL && temp != head){
        temp = temp->next;
    }
    if (temp == head){
        return true;
    }
    return false;
}

bool detectLoop(node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<node *, bool> visited;
    node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

node *floydDetectLoop(node *head)
{
    if (head == NULL)
        return NULL;
    node *slow = head;
    node *fast = head;
    while (slow != fast && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "loop present at " << slow->data << endl;
            return slow;
        }
    }
    if (fast == NULL){
        return NULL;
    }
    return slow;
}

// Distance of intersection of slow and fast from the start of cycle is same as the distance of intersection from the start
node *getStartOfLoop(node *head){
    if (head == NULL)
    {
        return NULL;
    }
    node *intersection = floydDetectLoop(head);
    node *start = head;
    while (start != intersection)
    {
        start = start->next;
        intersection = intersection->next;
    }
    return start;
}

void removeLoop(node *head)
{

    if (head == NULL)
    {
        return;
    }

    node *loop = getStartOfLoop(head);
    node *curr = loop->next;

    while (curr->next != loop)
    {
        curr = curr->next;
    }

    curr->next = NULL;
}

void removeDuplicateFromSortedLL(node *head){
    if (head == NULL){
        return;
    }

    node *current = head;
    while (current != NULL && current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            node *next_next = current->next->next;
            node *nodeToDelete = current->next;
            delete nodeToDelete;
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
}

void removeDuplicateFromUnsortedLL(node *head){

}

void insertAtTail(node *tail, node *curr)
{
    tail->next = curr;
    tail = curr;
}

void sort01And2Array(node *head)
{
    node *head0 = new node(-1);
    node *tail0 = head0;
    node *head1 = new node(-1);
    node *tail1 = head1;
    node *head2 = new node(-1);
    node *tail2 = head1;

    node *curr = head;
    while (curr != NULL)
    {
        int val = curr->data;
        if (val == 0)
        {
            insertAtTail(tail0, curr);
        }
        if (val == 1)
        {
            insertAtTail(tail1, curr);
        }
        if (val == 2)
        {
            insertAtTail(tail2, curr);
        }
        curr = curr->next;
    }

    if (head1->next != NULL){
        tail0->next = head1->next;
    }
    else{
        tail0->next = head2->next;
    }
    tail1->next = head2->next;
    tail2->next = NULL;

    head = head0->next;

    delete head0;
    delete head1;
    delete head2;
}



void MergeThis(node* first,node* second){

    //if only one node is present in first list
    if(first->next==NULL){
        first->next=second;
        return;
    }

    node* curr1=first;
    node* next1=first->next;
    node* curr2=second;
    node* next2;

    while(next1 != NULL && curr2!= NULL){

        if(curr1->data <= curr2->data && curr2->data <= next1->data){
            next2=curr2->next;
            curr1->next=curr2;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }

        else{
            curr1=curr1->next;
            next1=next1->next;

            if(next1==NULL){
                curr1->next=curr2;
                return;
            }
        }
    }
}

node* mergeTwoSortedArrays(node* first,node* second){
    if(first==NULL){
        return second;
    }
    else if(second==NULL){
        return first;
    }
    if(first->data > second->data){
        MergeThis(second,first);
        return second;
    }
    else{
        MergeThis(first,second);
        return first;
    }
}

bool checkPalindrome(node* head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    vector<int> arr;
    node* last=head;
    while(last != NULL){
        arr.push_back(last->data);
        last=last->next;
    }

    int s=0;
    int e=arr.size()-1;
    while(s<=e){
        if(arr[s] != arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

void printSLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // reverse a link list
    node *head = new node(6);
    SLLInsertAtHead(head, 5);
    SLLInsertAtHead(head, 78);
    SLLInsertAtHead(head, 34);
    SLLInsertAtHead(head, 3);
    SLLInsertAtHead(head, 4);
    printSLL(head);
    reverse(head);
    // reverser1(head,head,NULL);
    head = reverser2(head);
    printSLL(head);
    head = reverseALinkedListInAGroupOfK(head, 2);
    printSLL(head);
    cout << Middle(head)->data << endl;

    cout << middle2(head)->data;
    return 0;
}