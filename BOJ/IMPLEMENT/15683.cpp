#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int n,m;
int map[8][8],ori[8][8];
int ret = 64;

vector<pair<int,int>>p;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};

void foo(int dir,int x,int y){
    while(true){
        x+=dx[dir];
        y+=dy[dir];
        if(x<0 || y<0 || x>=n || y>=m)break;
        if(map[x][y] == 6)break;
        if(map[x][y]==0)map[x][y] = -1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin >> n >> m;
  
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            ori[i][j] = map[i][j];
            if(map[i][j]>=1 && map[i][j]<=5)p.push_back({i,j});
        }
    } 
    for(int i = 0; i<(1<<(2*p.size()));i++){
        int tmp = i;
        int sum = 0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)map[i][j] = ori[i][j];
        for(int j=0;j<p.size();j++,tmp/=4){
            int dir = tmp%4;
            int x = p[j].first;
            int y = p[j].second;
            switch(map[x][y]){
                case 1: foo(dir,x,y); break;
                case 2: foo(dir,x,y); foo((dir+2)%4,x,y); break;
                case 3: foo(dir,x,y); foo((dir+1)%4,x,y); break;
                case 4: for(int k=0;k<3;k++) foo((dir+k)%4,x,y); break;
                case 5: for(int k=0;k<4;k++) foo((dir+k)%4,x,y); break;
            }
        }
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(!map[i][j])sum++;
        ret = min(ret,sum);
    }
    cout << ret << '\n'; 
}