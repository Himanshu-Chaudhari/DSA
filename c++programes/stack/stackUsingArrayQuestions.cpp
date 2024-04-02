#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

// two stacks in one
// class Stack{
//     public:
//         int size;
//         int top1;
//         int top2;
//         int *arr;

//         Stack(int size){
//             this->size = size;
//             this->top1=-1;
//             this->top2=size;
//             arr=new int[size];
//         }

//         void push1(int data){
//             if(this->top1<size/2){
//                 this->top1++;
//                 arr[this->top1]=data;
//             }
//             else{
//                 cout<<"Stack1 Owerflow"<<endl;
//             }
//         }
//         void push2(int data){
//             if(this->top2>top1){
//                 this->top2--;
//                 arr[this->top2]=data;
//             }
//             else{
//                 cout<<"stack owerflow"<<endl;
//             }
//         }
//         void pop1(){
//             if(this->top1>=0){
//                 this->top1--;
//             }
//             else{
//                 cout<<"Stack is already empty"<<endl;
//             }
//         }

//         void pop2(){
//             if(this->top2<size){
//                 this->top2++;
//             }
//             else{
//                 cout<<"Stack is already empty"<<endl;
//             }
//         }
//         void print1(){
//             int top=top1;
//             while(top>=0){
//                 cout<<arr[top]<<" ";
//                 top--;
//             }
//             cout<<endl;
//         }
//         void print2(){
//             int top=top2;
//             while(top<size){
//                 cout<<arr[top]<<" ";
//                 top++;
//             }
//             cout<<endl;
//         }
// };

// int main(){
//     Stack s(8);
//     s.push1(6);
//     s.push1(8);
//     s.push2(10);
//     s.push2(76);
//     s.push2(34);
//     s.push2(98);

//     s.print1();
//     s.print2();

//     s.pop1();
//     s.pop2();

//     s.print1();
//     s.print2();

//      s.pop1();
//     s.pop2();

//     s.print1();
//     s.print2();

//      s.pop1();
//     s.pop2();

//     s.print1();
//     s.print2();

//     s.pop1();
//     s.pop2();

//     s.print1();
//     s.print2();

//     return 0;
// }


// reverse a string using stack
// class stack{
//     public:
//     int size;
//     char *arr;
//     int top;

//     stack(int size){
//             this->size=size;
//             arr=new char[size];
//             top=-1;
//     }

//     void push(char data){
//         if(size-top>1){
//             top++;
//             arr[top]=data;
//         }
//         else{
//             cout<<"Stack Owerflow"<<endl;
//         }
//     }

//     void pop(){
//         if(top>=0){
//             top--;
//         }
//         else{
//             cout<<"Stack is empty"<<endl;   
//         } 
//     }

//     char peek(){
//         if(top>=0){
//             return arr[top];
//         }
//         return -1;
//     }

//     void printStack(){
//         int cnt=top;
//         while(cnt>=0){
//             cout<<arr[cnt]<<" ";
//             cnt--;
//         }
//         cout<<endl;
//     }
// };

// int main(){

//     string str;
//     cout<<"please enter the string"<<endl;
//     cin >> str;
//     stack s1(str.length());
//     for( int i=0 ; i < str.length() ; i++ ){
//         s1.push(str[i]);
//     }
//     for(int i=0 ;i<str.length();i++){
//         str[i]=s1.peek();
//         s1.pop();
//     }
//     cout<<str<<endl;
//     return 0;
// }


//Delete middle element of a stack

// void solve(stack<int> &s1 , int cnt , int size){
//     if(cnt == size/2){
//         s1.pop();
//         return;
//     }
//     int store=s1.top();
//     s1.pop();
//     solve(s1,cnt+1,size);
//     s1.push(store);
//     return;
// }


//insert element at last position


// void appendLast(stack<int> &s, int data){
    
//     if(s.empty()){
//         s.push(data);
//         return;
//     }

//     int store=s.top();
//     s.pop();
//     appendLast(s,data);
//     s.push(store);
//     return;
// }

//Sort the stack
// void SortedInsert(stack<int> &s, int data){
//     if(s.empty() || (s.empty() && s.top()<data)){
//         s.push(data);
//         return;
//     }
//     int n=s.top();
//     s.pop();
//     SortedInsert(s,data);
//     s.push(n);
// }

// void SortStack(stack<int> &s){
//     if(s.empty()){
//         return;

//     }
//     int store=s.top();
//     s.pop();

//     SortStack(s);
//     SortedInsert(s,store  );
// }

// int main(){

//     stack<int> s1;
//     s1.push(9);
//     s1.push(8);
//     s1.push(7);
//     s1.push(6);
//     s1.push(5);

//    SortStack(s1);

//     stack<int> s2=s1;
//     while (!s1.empty())
//     {
//         cout<<s1.top()<<endl;
//         s1.pop();
//     }
    
//     return 0;
// }




//Find redundant brackets

// bool Solve(stack<char> s, string exp){
//     for(int i=0 ; i<exp.size() ; i++ ){
//         char ch=exp[i];
//         if( ch  == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
//             s.push(ch);
//         }
//         else if( ch == ')'){
//             int temp=s.top();
//             if(temp == ')'){
//                 bool isRedundant =true;
//                 while(s.top() != '('){
//                     char top=s.top();
//                     if(top=='+' || top=='-' || top=='*' || top=='/'){
//                         isRedundant=false;
//                     }
//                 }
//                 if(isRedundant==true){
//                     true;
//                 }
//                 s.pop();
//             }
//         }
//     }
//     return false;
// }



//Check weather the brackets in the screen are valid or not

// int checkValid(string s){
//     if(s.length()%2==1){
//         return -1;  
//     }
//     stack<char> st;
//     for(int i=0;i<s.size();i++){
//         char ch = s[i];
//         if(ch=='{'){
//             st.push('{');
//         }
//         else{
//                 if(!st.empty() && st.top()=='{'){
//                     st.pop();
//                 }
//                 else{
//                     st.push(ch);
//                 }
//         }
//     }   
//     int open=0;
//     int close=0;
//     while(!st.empty()){
//         if(st.top()=='{'){
//             open++;
//         }
//         else{
//             close++;
//         }
//         st.pop();
//     }
//     int ans=(open+1)/2 + (close+1)/2;
//     return ans;
// }
    

//Find the next smallest int in the array

// vector<int> nextSmallest(int *arr, int n){
//     stack<int> st;
//     st.push(-1);
//     vector<int> ans(n);
//     for(int i=n-1; i>=0 ; i-- ){
//         int curr=arr[i];
//         while(st.top() >= curr){
//             st.pop();
//         }
//         ans[i]=st.top();
//         st.push(curr);
//     }
//     return ans;
// }


//Find the rectangle with largest area in the histogram . Given the heights of rectangles

// vector<int> nextSmallerElement(vector<int> arr, int n){
//     stack<int> st;
//     st.push(-1);
//     vector<int> ans(n);
//     for(int i=n-1; i>=0 ; i-- ){
//         int curr=arr[i];
//         while(st.top() != -1 && arr[st.top()] >= curr){
//             st.pop();
//         }
//         ans[i]=st.top();
//         st.push(i);
//     }
//     return ans;
// }

// vector<int> prevSmallerElement(vector<int> arr, int n){
//     stack<int> st;
//     st.push(-1);
//     vector<int> ans(n);
//     for(int i=0; i<n ; i++ ){
//         int curr=arr[i];
//         while(st.top() != -1 && st.top() >= curr){
//             st.pop();
//         }
//         ans[i]=st.top();
//         st.push(curr);
//     }
//     return ans;
// }

// int largestRectangleArea(vector<int> &height){
//     int n=height.size();

//     vector<int> next(n);
//     next=nextSmallerElement(height,n);

//     vector<int> prev(n);
//     prev=prevSmallerElement(height,n);

//     int area=INT_MIN;
//     for(int i=0;i<n;i++){
//         int l=height[i]; 
//         if(next[i]==-1){
//             next[i]=n;
//         }
//         int b= next[i] - prev[i] - 1; 
//         int newArea=l*b;
//         area=max(area,newArea);
//     }
//     return area;
// } 


// Celebrity Problem

bool knows(vector<vector<int>> &M,int a,int b,int n){
    if(M[a][b] == 1){
        return true;
    }
    else{
        return false;
    }
}
int celebrity(vector<vector<int>> &M,int n){
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    while(s.size()>1){
        int a=s.top();
        s.pop();

        int b=s.top();
        s.pop();

        if(knows(M,a,b,n)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }

    int candidate=s.top();
    bool rowCheck=false;
    int zeroCount=0;

    for(int i=0;i<n;i++){
        if(M[candidate][i] == 0)
            zeroCount++;
    }

    if(zeroCount==0)
        rowCheck=true;
            
    bool colCheck=false;
    int oneCount=0;

    for(int i=0;i<n;i++){
        if(M[i][candidate] == 0)
            oneCount++;
    }

    if(oneCount==n-1)
        colCheck=true;

    if(rowCheck==true && colCheck==true){
        return candidate;
    }
    else{ 
        return -1;
    }
}

int main(){

    return 0;
}