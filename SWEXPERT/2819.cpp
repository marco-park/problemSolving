#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> p;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int map[4][4];

void foo(int x,int y,string s){
    if(s.size()==7){
        p.insert(s);
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=4 || ny>=4 || nx<0 || ny<0)continue;
        foo(nx,ny,to_string(map[nx][ny])+s);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    for(int tt = 1; tt <= t; tt++){
        p.clear();
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                cin >> map[i][j];
            
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                foo(i,j,to_string(map[i][j]));
            
        cout << "#" << tt << " " << p.size() << '\n';
    }
}