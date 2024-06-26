#include<iostream>
#include<string>
#include<vector>

using namespace std;

void solve(string digits, vector<string> &ans,string output,int index,string mapping[]){
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }
    int num=digits[index]-'0';
    string value=mapping[num];
    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        solve(digits,ans,output,index+1,mapping);
        output.pop_back();
    }
}
int main(){
    string digits="346";
    vector<string> ans;
    string output="";
    int index=0;
    string mapping[10]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,ans,output,index,mapping);
    
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}