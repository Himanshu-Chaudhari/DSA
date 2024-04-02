#include<iostream>
using namespace std;

class stack{
    public:
    int size;
    int *arr;
    int top;

    stack(int size){
            this->size=size;
            arr=new int[size];
            top=-1;
    }

    void push(int data){
        if(size-top>1){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"Stack Owerflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack is empty"<<endl;   
        } 
    }

    void peek(){
        if(top>=0){
            cout<<arr[top]<<endl;
        }
        cout<<"Stack is empty"<<endl;
    }

    void printStack(){
        int cnt=top;
        while(cnt>=0){
            cout<<arr[cnt]<<" ";
            cnt--;
        }
        cout<<endl;
    }
};

int main(){
    int si;
    cin>>si;
    stack s(si);
    s.push(9);
    s.push(7);
    s.peek();
    s.pop();
    s.peek();
    s.push(8);
    s.push(10); 
    s.push(81);
    s.push(110); 
    s.push(1);
    s.push(1710);
    s.printStack();
    return 0;
}