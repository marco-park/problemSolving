#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool visited[201][201]={0,};
    bool dfs(vector<vector<char>>& board,int x,int y,string s,string word,int n,int m){
        if(s==word)return true;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0|| ny<0 || nx>=n || ny>=m || visited[nx][ny])continue;
            if(board[nx][ny] != word[s.size()])continue;
            visited[nx][ny] = true;
            if(dfs(board,nx,ny,s+board[nx][ny],word,n,m))return true;
            visited[nx][ny] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) { 
        bool ret = false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = true;
                    ret |= dfs(board,i,j,string(1,word[0]),word,board.size(),board[i].size());
                    memset(visited,0,sizeof(visited));
                }
            }
        }
        return ret;
    }
};