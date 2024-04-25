#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(int row,int col,vector<vector<bool>> &visited,vector<vector<int>> &maze,int n){
    if(row>=0 && row<n && col>=0 && col<n && !visited[row][col] && maze[row][col]==1){
        return true;
    }
    return false;
}

void solve(int row,int col,string store,vector<vector<bool>> &visited,vector<vector<int>> &maze,
            int n,vector<string> &ans){
    if(row==n-1 && col==n-1){
        ans.push_back(store);
    }
    visited[row][col]=true;
    if(isSafe(row+1,col,visited,maze,n)){
        solve(row+1,col,store+'D',visited,maze,n,ans);
    }
    if(isSafe(row-1,col,visited,maze,n)){
        solve(row-1,col,store+'U',visited,maze,n,ans);
    }
    if(isSafe(row,col+1,visited,maze,n)){
        solve(row,col+1,store+'R',visited,maze,n,ans);
    }
    if(isSafe(row,col-1,visited,maze,n)){
        solve(row,col-1,store+'L',visited,maze,n,ans);
    }
    visited[row][col]=false;
}

vector<string> findPaths(vector<vector<int>> &maze,int n){
    vector<vector<bool>> visited(n,vector<bool> (n,false));
    vector<string> ans;
    solve(0,0,"",visited,maze,n,ans);
    return ans;
}

int main(){
    
    return 0;
}