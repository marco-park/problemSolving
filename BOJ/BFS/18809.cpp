#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int board[51][51],ori[51][51];
int g,r,n,m;
vector<pair<int,int>>p,rp,gp;
bool chcomb[51][51];
queue<pair<int,int>>rq,gq;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ret;
int bfs();
void comb2(int,int);

void comb(int cnt,int idx){
    if(cnt == r){
        comb2(0,0);
        return;
    }
    for(int i=idx;i<p.size();i++){
        auto x = p[i];
        if(!chcomb[x.first][x.second]){
            chcomb[x.first][x.second] = true;
            rp.push_back(x);
            comb(cnt+1,i+1);
            rp.pop_back();
            chcomb[x.first][x.second] = false;
        }
    }
}

void comb2(int cnt,int idx){
    if(cnt == g){
        ret = max(ret,bfs());
        return;
    }
    for(int i=idx;i<p.size();i++){
        auto x = p[i];
        if(!chcomb[x.first][x.second]){
            chcomb[x.first][x.second] = true;
            gp.push_back(x);
            comb2(cnt+1,i+1);
            gp.pop_back();
            chcomb[x.first][x.second] = false;
        }
    }
}

int bfs(){
    int ret = 0;
    int level = 5;
    while(!rq.empty())rq.pop();
    while(!gq.empty())gq.pop();
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)board[i][j] = ori[i][j];
    for(auto x:rp)rq.push(x),board[x.first][x.second] = 3;
    for(auto x:gp)gq.push(x),board[x.first][x.second] = 4;

    while(!rq.empty() || !gq.empty()){
        int rqsize = rq.size();
        while(rqsize--){
            int rx = rq.front().first;
            int ry = rq.front().second;
            rq.pop();
            if(board[rx][ry]==-1)continue;  //큐에 이미 넣었지만 g에 의해 수틀린 경우!!
            for(int i=0;i<4;i++){
                int nx = rx+dx[i];
                int ny = ry+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m)continue;
                if(board[nx][ny] == 1 || board[nx][ny] == 2){
                    board[nx][ny] = level;
                    rq.push({nx,ny});   
                }
            }
        }
        int gqsize = gq.size();
        while(gqsize--){
            int gx = gq.front().first;
            int gy = gq.front().second;
            gq.pop();
            for(int i=0;i<4;i++){
                int nx = gx+dx[i];
                int ny = gy+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m)continue;
                if(board[nx][ny] == level){ret++;board[nx][ny] = -1;}
                if(board[nx][ny] == 1 || board[nx][ny] == 2){
                    board[nx][ny] = -1;
                    gq.push({nx,ny});
                }
            }
        }
        level++;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cin >> n >> m >> g >> r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            ori[i][j] = board[i][j];
            if(board[i][j] == 2)p.push_back({i,j});
        }
    }
    comb(0,0);
    cout << ret << '\n';
}