#include<iostream>
#include<vector>
using namespace std;

// it gives tle
void maxNonAdjSumRec(vector<int> &nums,int &ans,int temp,int index){
    if(index>=nums.size()){
        return;
    }
    // cout<<ans<<endl;
    ans=max(ans,temp+nums[index]);
    //exclude
    maxNonAdjSumRec(nums,ans,temp,index+1);
    //include
    maxNonAdjSumRec(nums,ans,temp+nums[index],index+2);
}

int maxNonAdjSumRec2(vector<int> &nums,int index){
    if(index<0){
        return 0;
    }
    if(index==0){
        return nums[index];
    }
    int include=maxNonAdjSumRec2(nums,index-2)+nums[index];
    int exclude=maxNonAdjSumRec2(nums,index-1)+0;
    return max(include,exclude);
}

int maxNonAdjSumMemoisation(vector<int> &nums,vector<int> &dp,int index){
    if(index<0){
        return 0;
    }
    if(index==0){
        return nums[index];
    }
    if(dp[index]!=-1){
        return dp[index];
    }

    int include=maxNonAdjSumRec2(nums,index-2)+nums[index];
    int exclude=maxNonAdjSumRec2(nums,index-1)+0;
    dp[index]=max(include,exclude);
    return dp[index];
}

int maxNonAdjSumTabularisation(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n+1,-1);
    dp[0]=nums[0];
    dp[1]=nums[1];
    for(int i=1;i<n;i++){
        int include=(i >= 2 ? dp[i - 2] + nums[i] : nums[i]);
        int exclude=dp[i-1];
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[n-1];
}


int maxNonAdjSum(vector<int> &nums){
    int n=nums.size();
    int last=nums[0];
    int secondLast=0;
    for(int i=1;i<n;i++){
        int include=secondLast+nums[i];
        int exclude=last;
        secondLast=last;
        last=max(include,exclude);
    }
    return last;
}

int main(){
    vector<int> question{2,3,564,7,45,565,890};
    // int ans=0;
    // maxNonAdjSumRec(question,ans,0,0);
    // cout<<maxNonAdjSumRec2(question,question.size())<<endl;
    // cout<<ans;

    vector<int> dp(question.size()+1,-1);
    cout<<maxNonAdjSumMemoisation(question,dp,question.size())<<endl;
    return 0;
}