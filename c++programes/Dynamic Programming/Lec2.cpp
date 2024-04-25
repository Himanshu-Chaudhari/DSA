#include<iostream>
#include<vector>
using namespace std;
// mininum steps to climb the stairs
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


// minimum steps to climb the stairs where the cost of climbing each stair is given
int countStepsWithCost(vector<int> cost,int n){
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    return cost[n]+min(countStepsWithCost(cost,n-1),countStepsWithCost(cost,n-2));
}

// Dp using memoisation
int countStepsWithCost2(vector<int> cost,int n,vector<int> &dp){
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=cost[n]+min(countStepsWithCost2(cost,n-1,dp),countStepsWithCost2(cost,n-2,dp));
    return dp[n];
}

// Dp using tabulation
int countStepsWithCost3(vector<int> cost,int n){
    vector<int> dp(n+1);
    dp[0]=cost[0];
    dp[1]=cost[1];

    for(int i=2;i<n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}

// More optimised
int countStepsWithCost4(vector<int> cost,int n){
    vector<int> dp(n+1);
    int last=cost[1];
    int secondLast=cost[0];
    int curr=min(last,secondLast);
    for(int i=2;i<n;i++){
        curr=cost[i]+min(last,secondLast);
        last=secondLast;
        last=curr;
    }
    return curr;
}

int main(){
    // cout<<countSteps(6);

    vector<int> cost{2,4,8,5,2,1,4,6};
    // without dp
    // int ans=min(countStepsWithCost(cost,cost.size()-1),countStepsWithCost(cost,cost.size()-2));
    // cout<<ans;


    // with dp using recursion and memoisation 
    // vector<int> dp(cost.size()+1,-1);
    // int ans=min(countStepsWithCost2(cost,cost.size()-1,dp),countStepsWithCost2(cost,cost.size()-2,dp));
    // cout<<ans;


    // with dp using tabulation
    int ans=countStepsWithCost3(cost,cost.size());
    cout<<ans;
    return 0;
}
