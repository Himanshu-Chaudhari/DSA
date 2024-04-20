#include<iostream>
#include<vector>
using namespace std;

int fibo(int n, vector<int> &dp){
    if(n<=1)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n];
}
// fibo more optimal 

int fibo2(int n){
    int prev1=1;
    int prev2=0;
    if(n==0){
        return prev2;
    }
        
    for(int i=2;i<n;i++){
        int ans=prev1+prev2;
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    // cout<<"Hello World";
    cout<<fibo2(5)<<endl;
    cout<<fibo(n,dp)<<endl;;
    
}