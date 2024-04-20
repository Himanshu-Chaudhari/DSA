#include<iostream>
#include<vector>
using namespace std;

int countSteps(int n){
    if(n==0){
        return 0;
    }
    if(n<0){
        return -1;
    }
    if(n%2==0){
        return n/2;
    }
    return n/2+1;
}

int main(){
    cout<<countSteps(6);
   
    return 0;
}
