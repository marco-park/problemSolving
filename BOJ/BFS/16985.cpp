#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int dx[]={0,0,1,-1,0,0};
int dy[]={1,-1,0,0,0,0};
int dz[]={0,0,0,0,1,-1};

int map[5][5][5],ori[5][5][5],d[5][5][5];
int r[4][5][5][5];

struct T{int x,y,z;};
int rret = 0x3f3f3f3f;

void rotate(int cnt,int k){
    int tmp[5][5];
    for(int i=0;i<5;i++)for(int j=0;j<5;j++)tmp[i][j] = r[cnt-1][k][i][j];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            r[cnt][k][i][j] = tmp[4-j][i];   
        }
    }
}

int bfs(){
    if(!map[0][0][0] || !map[4][4][4])return 0x3f3f3f3f;
    queue<T>q;
    q.push({0,0,0});
    memset(d,-1,sizeof(d));
    d[0][0][0] = 0;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();
        for(int i=0;i<6;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nz = z+dz[i];
            if(nx<0 || ny<0 || nz<0 || nx>=5 || ny>=5 || nz>=5)continue;
            if(!map[nx][ny][nz] || d[nx][ny][nz]!=-1)continue;
            d[nx][ny][nz] = d[x][y][z]+1;
            q.push({nx,ny,nz});
            if(nx==4 && ny ==4 && nz ==4)return d[nx][ny][nz];
        }
    }
    return 0x3f3f3f3f;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   

    for(int k=0;k<5;k++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cin >> map[k][i][j];
                r[0][k][i][j] = map[k][i][j];
            }
        }
    }

    for(int t=1;t<4;t++)for(int k=0;k<5;k++)rotate(t,k);
    int ret = 0x3f3f3f3f;
    
    vector<int>p;
    for(int i=0;i<5;i++)p.push_back(i);

    do{
        for(int tmp = 0;tmp<(1<<(2*5));tmp++){
            int kk = tmp;
            for(int k=0;k<5;k++){   
                int x = kk%4;
                for(int i=0;i<5;i++)for(int j=0;j<5;j++)map[k][i][j] = r[x][p[k]][i][j];
                kk/=4;
            }
            ret = min(ret,bfs());
        }
    }while(next_permutation(p.begin(),p.end()));
    if(ret == 0x3f3f3f3f)ret = -1;
    
    cout << ret << '\n';
}   