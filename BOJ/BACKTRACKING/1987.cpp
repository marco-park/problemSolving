#include <iostream>
#include <algorithm>

using namespace std;

char map[21][21];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int r,c;

int foo(int x,int y,int visited){
    int ret = 1;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx >=r || nx <0 || ny>=c || ny<0)continue;
        if(visited & (1<<(map[nx][ny]-'A')))continue;
        ret = max(ret,foo(nx,ny,visited+(1<<(map[nx][ny]-'A')))+1);
    }
    return ret;
} 

int main(){
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> map[i][j];
        }
    }
    cout << foo(0,0,(1<<(map[0][0]-'A'))) << '\n';
}