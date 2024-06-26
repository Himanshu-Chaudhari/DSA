#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums,vector< vector<int> > &ans,int index){
    if(index >= nums.size()){
        ans.push_back(nums);
        return ;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        solve(nums,ans,index+1);
        swap(nums[index],nums[i]);
    }
}

int main(){
    vector< int > nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(8);
    vector< vector<int> > ans;
    int index=0;
    solve(nums,ans,index);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}