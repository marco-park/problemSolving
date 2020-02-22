#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int d[2001][2001];
int a[2001],b[2001];
int n;

int foo(int x,int y){
    if(x==n || y==n)return 0;
    int &ret = d[x][y];
    if(ret!=-1)return ret;
    if(a[x]>b[y])ret = max(ret,foo(x,y+1)+b[y]);
    else ret = 0;
    ret = max({ret,foo(x+1,y+1),foo(x+1,y)});
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    memset(d,-1,sizeof(d));  

    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    cout << foo(0,0) << '\n';
}