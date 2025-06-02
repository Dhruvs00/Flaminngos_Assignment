#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<pair<int,int>> diag={{0,-1},{1,-1},{-1,-1}}; // Directions to check for queen threats (left row, left-down, left-up)

    bool isSafe(int n, int row , int col , vector<string> board){
        for(auto x:diag){
            int vertical=row+x.first;
            int horizontal = col+x.second;
            while(vertical>=0 && vertical<n && horizontal>=0 && horizontal<n){
                if(board[vertical][horizontal]=='Q') return false; // Queen in attacking path
                vertical+=x.first;
                horizontal+=x.second;
            } 
        }
        return true; // Safe to place queen
    }

    void solve(int n,int col , vector<string>& board){
        if(col>=n){
            ans.push_back(board); // Valid configuration found
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(n,row,col,board)){
                board[row][col]='Q'; // Place queen
                solve(n,col+1,board); // Recurse to next column
                board[row][col]='.'; // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n,'.'); // Empty row
        for(int i=0;i<n;i++) board[i]=s; // Initialize board
        solve(n,0,board); // Start from column 0
        return ans;
    }
};


int main(){
  int n;
  cin>>n;
  Solution S;
  vector<vector<string>> ans=S.solveNQueens(n);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<n;j++){
      cout<<ans[i][j]<<"\n";
    }
    cout<<"\n";
  }
  return 0;
}