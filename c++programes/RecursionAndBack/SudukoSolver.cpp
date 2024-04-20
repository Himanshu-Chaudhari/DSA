
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    bool isSafe(vector<vector<char>>& board,int i,int j,char ele){
        for(int k=0;k<9;k++){
            if(board[k][j]==ele){
                return false;
            }
            if(board[i][k]==ele){
                return false;
            }
            // Remember 
            if(board[3*(i/3) + k/3][3*(j/3)+k%3]==ele){
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        char ele='0'+k;
                        if(isSafe(board,i,j,ele)){
                            board[i][j]=ele;
                            bool furtherSolutionExists=solve(board);
                            if(furtherSolutionExists){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};