#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums,vector<int> output,vector<vector<int> > &ans,int index){
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(nums,output,ans,index+1);
    //include
    int element=nums[index];
    output.push_back(element);
    solve(nums,output,ans,index+1);
}

int main(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(8);
    vector<vector<int> > ans;
    vector<int> output;
    int index=0;
    solve(nums,output,ans,0);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}