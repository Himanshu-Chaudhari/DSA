// N queens problem

#include<iostream>
using namespace std;

void storeAns(vector<vector<int>> &board,vector<vector<int>> &ans, int n){
    vector<int> temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row,int col,vector<vector<int>> &board,int n){

    // checking left row
    int x = row;
    int y = col;

    while(y>=0){
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }

    // checking nort west diagonal
    x = row;
    y = col;

    while( x >= 0 && y >= 0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    // checking south west
    x = row;
    y = col;

    while( x < n && y >= 0){
        if(board[x][y]==1){
            return false;
        }
        x++;
        y--;
    }
    return true;

}

void solve(int col,vector<vector<int>> &board,vector<vector<int>> &ans, int n){
    if(col==n){
        storeAns(board,ans,n);
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]=1;
            solve(col+1,board,ans,n);
            board[row][col]=0;
        }
    }
}

vector<vector<int>> nQueens(int n){
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;
    solve(0,board,ans,n); 
    return ans;
}

int main(){
    vector<vector<int>> ans=nQueens(4);
    int cnt=1;
    for(int i=0;i<ans.size();i++){
        cout<<"Soln no " << i+1 << " - "<<endl;
        for(int j=0;j<ans[i].size();j++){
            cout<< ans[i][j]<<" , ";
            if(cnt==4){
                cnt=0;
                cout<<endl;
            }
            cnt++;
        }
        cout<<endl;
    }
}