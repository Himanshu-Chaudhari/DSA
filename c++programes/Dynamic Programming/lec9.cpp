#include<iostream> 
#include<vector>

using namespace std;
int minNumberOfPerfectSquaresToBuildANumber(int n,int &minCount){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans=0;
    for(int i=0;i<n/2 ;i++){
        ans+=minNumberOfPerfectSquaresToBuildANumber(n-i*i,minCount);
    }
    minCount=min(ans,minCount);
    return ans;
}

int main(){
    int ans=0;
    cout<<minNumberOfPerfectSquaresToBuildANumber(100,ans);
    
    return 0;
}

