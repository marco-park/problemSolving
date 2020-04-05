#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int n;
int map[101][101];
int color[101][101];
int c;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int d[101][101];
queue<pair<int,int>>q;

void dfs(int x,int y){
    color[x][y] = c;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0||ny<0||nx>=n||ny>=n||color[nx][ny]!=-1)continue;
        if(!map[nx][ny]){
            if(d[x][y]==-1){
                d[x][y] = 0;
                q.push({x,y});
            }
            continue;
        }
        dfs(nx,ny);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    memset(color,-1,sizeof(color));
    memset(d,-1,sizeof(d));

    cin >> n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin >> map[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!map[i][j])continue;
            if(color[i][j]==-1){
                dfs(i,j);
                c++;
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=n || map[nx][ny])continue;
            if(d[nx][ny]!=-1){
                if(color[nx][ny]!=color[x][y]){
                    cout << d[x][y]+d[nx][ny] << '\n';
                    return 0;
                }
                continue;
            }
            d[nx][ny] = d[x][y] +1;
            color[nx][ny] = color[x][y];
            q.push({nx,ny});
        }
    }
}