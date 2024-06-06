#include<iostream>
#include<vector>
using namespace std;

// min number of coins (Minimum elements Coding Ninjas)
// Using recursion
// It gives TLE
int minCoins(vector<int> &nums,int x){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    int ans;
    int mini=INT_MAX;
    for(int i=0;i<nums.size();i++){
        ans=minCoins(nums,x-nums[i]);
        if(ans!=INT_MAX){
            mini=min(1+ans,mini);
        }
    }
    return mini;
}

// using DP memo
int solveUsingMemo(vector<int> &dp,vector<int> nums,int x){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    int ans;
    int mini=INT_MAX;
    for(int i=0;i<nums.size();i++){
        ans=solveUsingMemo(dp,nums,x-nums[i]);
        if(ans!=INT_MAX){
            mini=min(1+ans,mini);
        }
    }
    dp[x]=mini;
    return mini;
}

//using DP tabu
int solveUsingTabulation(vector<int> nums,int x){
    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;

    for(int i=0;i<=x;i++){
        // We need to solve for each amount which is less than x
        for(int j=0;j<nums.size();j++){
            if(i-nums[j]>=0 && dp[i-nums[j]]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-nums[j]]);
            }
        }
    }
    return dp[x];
}
int main(){
    vector<int> numbers{2,3,4,5,67,6,7,8};
    // int ans=minCoins(numbers,20);
    // if(ans==INT_MAX){
    //     cout<<"No soln possible"<<endl;
    // }
    // else{
    //     cout<<ans;
    // }

    int amount=100;
    // vector<int> dp(amount+1,-1);
    // int ans=solveUsingMemo(dp,numbers,amount);
    // if(ans==INT_MAX){
    //     cout<<"No soln possible"<<endl;
    // }
    // else{
    //     cout<<ans;
    // }

    int ans=solveUsingTabulation(numbers,amount);
    if(ans==INT_MAX){
        cout<<"No soln possible"<<endl;
    }
    else{
        cout<<ans;
    }
}