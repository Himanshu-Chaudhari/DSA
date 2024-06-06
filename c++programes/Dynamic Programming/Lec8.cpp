#include<iostream>
#include<vector>
using namespace std;

// combination sum 4

int solve(vector<int> nums,vector<int> &dp,int target,int sum){
    if(sum > target){
        return 0;
    }
    if(sum==target){
        return 1;
    }
    if(dp[sum]!=0){
        return dp[sum];
    }
    for(int i=0;i<nums.size();i++){
        dp[sum]+=solve(nums,dp,target,sum+nums[i]);
    }
    return dp[sum];
}
int solveTabu(vector<int> nums,int target){
    vector<int> dp(target+1,0);
    dp[0]=1;
    //traversing 1 to target
    for(int i=1;i<=target;i++){
        for(int j=0;j<nums.size();j++){
            if(i-nums[j]>=0){
                dp[i]+=dp[i-nums[j]];
            }
        }
    }
    return dp[target];
}


int main(){
    vector<int> nums{1,2,5};
    vector<int> dp(5,0);
    int cnt=0;
    // cnt=solve(nums,dp,5,0);
    cnt=solveTabu(nums,5);
    cout<<cnt;
    return 0;
}