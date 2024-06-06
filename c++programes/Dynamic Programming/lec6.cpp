#include<iostream>
#include<vector>
using namespace std;

// Painting Fence Algorithmn
// Recursion n=number of fences , k=number of colours , max 2 fences can have same colour
int paintingFence(int n,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return k*(k-1)+k;
    }
    // considering same and different colour both cases
    int ans=(paintingFence(n-1,k)*(k-1)+ paintingFence(n-2,k)*(k-1));
    return ans;
}

// memo
int paintingFenceMemo(int n,int k,vector<int> &dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return k*(k-1)+k;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    // considering same and different colour both cases
    dp[n]=(paintingFence(n-1,k)*(k-1)+ paintingFence(n-2,k)*(k-1));
    return dp[n];
}


// tabu
int paintingFenceTabu(int n,int k){
    vector<int> dp(n+1.-1);
    dp[1]=k;
    dp[2]=k*(k-1)+k;
    for(int i=3;i<=n;i++){
        // considering same and different colour both cases
        dp[i]=(dp[i-1]*(k-1)+ dp[i-2]*(k-1));
    }
    return dp[n];
}
int main(){
    cout<<paintingFenceTabu(4,3);

    return 0;
}