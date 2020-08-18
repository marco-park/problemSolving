#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int N,L,R;
int map[51][51],visited[51][51];
pair<int,int> pcnt[2501];

bool foo(){
    memset(visited,-1,sizeof(visited));
    for(int i=0;i<2500;i++)pcnt[i].first = pcnt[i].second = 0;
    int cnt = 0;
    queue<pair<int,int>>q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]==-1){
                visited[i][j] = ++cnt;
                q.push({i,j});
                pcnt[cnt].first = map[i][j];
                pcnt[cnt].second = 1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        int diff = abs(map[x][y] - map[nx][ny]);
                        if(nx<0 || ny<0 || nx>=N || ny>= N || diff < L || diff > R || visited[nx][ny] != -1)continue;
                        visited[nx][ny] = cnt;
                        q.push({nx,ny});
                        pcnt[cnt].first+=map[nx][ny];
                        pcnt[cnt].second++;
                    }
                }
            }
        }
    }
   
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)map[i][j] = pcnt[visited[i][j]].first / pcnt[visited[i][j]].second;
    return N*N!=cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L >> R;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin >> map[i][j];
    int ret = 0;
    while(foo())ret++;
    cout << ret << '\n';
}