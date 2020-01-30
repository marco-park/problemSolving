#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int d[101][101],track[101][101];
int a[101][101];
int n;

int foo(int x,int y){
    if(x==n)return 0;
    int &ret = d[x][y];
    if(ret!=-1)return ret;
    ret = max(foo(x+1,y),foo(x+1,y+1))+a[x][y];
    return ret;
}

int bar(int x,int y){
    if(x==n-1)return 1;
    int &ret = track[x][y];
    if(ret!=-1)return ret;
    ret = 0;
    if(d[x+1][y]>d[x+1][y+1])ret += bar(x+1,y);
    else if(d[x+1][y]<d[x+1][y+1])ret += bar(x+1,y+1);
    else ret += bar(x+1,y)+bar(x+1,y+1);
    return ret;
}

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        memset(d,-1,sizeof(d));
        memset(track,-1,sizeof(track));
        cin >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cin >> a[i][j];
            }
        }
        foo(0,0);
        cout << bar(0,0) << '\n';
    }
}