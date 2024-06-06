#include<iostream> 
#include<vector>
using namespace std;

//  VVIP question 
// Count derangements
// recursive
long long int countDerangements(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    int ans= (n-1)*(countDerangements(n-1)+countDerangements(n-2));
    return ans;
}

// memoisation
long long int countDerangements(int n,vector<int> &dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]= (n-1)*(countDerangements(n-1)+countDerangements(n-2));
    return dp[n];
}

// tabulation
long long int countDerangements(int n){
     if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    vector<int> dp(n+1,-1);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=(n-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}

int main(){

}