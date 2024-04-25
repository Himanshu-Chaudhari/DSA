
#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> num,int index,vector<int> &ans){
	if(index>=num.size()){
		return;
	}
	int sum=0;
    // ans.push_back(num[index]);
	int size=ans.size();
	for(int i=0;i<size;i++){
		ans.push_back(ans[i]+num[index]);
		sum+=ans[i];
	}
	// ans.push_back(sum);
	solve(num,index+1,ans);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
	vector<int> ans;
    ans.push_back(0);
	solve(num,0,ans);
	return ans;
}

int main(){
    vector<int> num{1 ,2 ,3};
    vector<int> ans=subsetSum(num);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}
