#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

char map[21][21];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int d[21][21];
bool check[21][21];
int r,c;
int rret;

void foo(int x,int y,int visited){
    rret = max(rret,d[x][y]);
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx >=r || nx <0 || ny>=c || ny<0)continue;
        if(visited & (1<<(map[nx][ny]-'A')))continue;
        if(check[nx][ny])continue;
        check[nx][ny] = true;
        d[nx][ny] = d[x][y]+1;
        foo(nx,ny,visited+(1<<(map[nx][ny]-'A')));
        check[nx][ny]=false;
    }
} 

int main(){
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> map[i][j];
        }
    }
    d[0][0] = 1;
    check[0][0] = 1;    
    foo(0,0,(1<<(map[0][0]-'A')));
    cout << rret<< '\n';
}