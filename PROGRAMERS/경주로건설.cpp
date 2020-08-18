#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct E{
    int x,y,dir,cost;
    bool operator < (const E &a) const {return a.cost < cost;}
};

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int d[25][25][4];

int solution(vector<vector<int>> board){
    int ret = 0x3f3f3f3f;
    int n = board[0].size();
    priority_queue<E>pq;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<4;k++)d[i][j][k] = 0x3f3f3f3f;
    for(int i=0;i<4;i++){
        pq.push({0,0,i,0});
        d[0][0][i] = 0;
    }
    while(!pq.empty()){
        int x = pq.top().x;
        int y = pq.top().y;
        int dir = pq.top().dir;
        int prevCost = pq.top().cost;
        pq.pop();
        if(d[x][y][dir] < prevCost)continue;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=n || board[nx][ny]==1)continue;
            int cost = i!=dir ? 600 : 100;
            if(d[x][y][dir] + cost < d[nx][ny][i]){
                d[nx][ny][i] = d[x][y][dir] + cost;
                pq.push({nx,ny,i,d[nx][ny][i]});
            }
        }
    }
    for(int i=0;i<4;i++)ret = min(ret,d[n-1][n-1][i]);
    return ret;
}