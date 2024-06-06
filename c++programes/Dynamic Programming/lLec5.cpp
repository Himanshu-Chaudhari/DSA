#include<iostream>
#include<vector>
using namespace std;
// using memoisation
int cutIntoSegmentsMemo(int len,int x,int y,int z,vector<int> &dp){
    if(len==0){
        return 0;
    }
    if(len<0){
        return INT_MIN;
    }
    if(dp[len]!=-1){
        return dp[len];
    }
    int a=cutIntoSegmentsMemo(len-x,x,y,z,dp)+1;
    int b=cutIntoSegmentsMemo(len-y,x,y,z,dp)+1;
    int c=cutIntoSegmentsMemo(len-z,x,y,z,dp)+1;
    dp[len]=max(a,max(b,c));
    return dp[len];
}

// using taulation
int cutIntoSegmentsTabu(int len,int x,int y,int z){
    vector<int> tabulation(len+1,-1);
    tabulation[0]=0;
    for(int i=1;i<=len;i++){
        if(len-x>=0){
            tabulation[len]=max(tabulation[len],tabulation[len-x]+1);
        }
        if(len-y>=0){
            tabulation[len]=max(tabulation[len],tabulation[len-y]+1);
        }
        if(len-z>=0){
            tabulation[len]=max(tabulation[len],tabulation[len-z]+1);
        }
    }
    if(tabulation[len]<0){
        return 0;
    }
    return tabulation[len];
}


int main(){
    vector<int> dp(5,-1);
    int ans=cutIntoSegmentsMemo(4,3,4,2,dp);
    int ans1=cutIntoSegmentsTabu(4,3,4,2);
    cout<<ans<<"       "<<ans;
}