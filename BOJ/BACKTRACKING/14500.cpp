#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int map[505][505];
bool check[500][500];
int n,m,ret;

int foo(int x,int y,int depth){
    if(depth==4)return 0;
    if(x>=n || y>=m || x<0 || y<0)return 0;
    int ret = 0;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(check[nx][ny])continue;
        check[nx][ny] = true;
        ret = max(ret,foo(nx,ny,depth+1)+map[x][y]); 
        check[nx][ny] = false;  
    }
    return ret;
}

int bar(int x,int y){
    int tmp = 0;
    int ret = 0;
    for(int i=0;i<3;i++)tmp+=map[x+i][y];
    if(!y)ret = tmp+map[x+1][y+1];
    else ret = tmp+max(map[x+1][y-1],map[x+1][y+1]);
    tmp = 0;
    for(int i=0;i<3;i++)tmp+=map[x][y+i];
    if(!x)ret = max(ret,tmp+map[x+1][y+1]);
    else ret = max(ret,tmp+max(map[x+1][y+1],map[x-1][y+1]));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   

    cin >> n >> m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> map[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            check[i][j] =true;
            ret = max({ret,foo(i,j,0),bar(i,j)});
            check[i][j] = false;
        }
    }
    cout << ret << '\n';
}