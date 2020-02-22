#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int d[1001][1001][3];
int a[1001][1001];
int n;

int foo(int x,int y,int k){
    if(x==n || y==n)return 0;
    int &ret = d[x][y][k];
    if(ret!=-1)return ret;
    if(a[x][y]==k)
        ret = max(foo(x+1,y,(k+1)%3),foo(x,y+1,(k+1)%3))+1;
    else 
        ret = max(foo(x+1,y,k),foo(x,y+1,k));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    cin >> n;
    memset(d,-1,sizeof(d));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin >> a[i][j];
    cout << foo(0,0,0) << '\n';
}