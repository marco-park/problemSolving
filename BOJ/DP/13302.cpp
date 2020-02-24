#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int d[101][301]; 
int n,m;
bool check[101];

int foo(int now,int cu){
    if(now>=n+1)return 0;
    int &ret = d[now][cu];
    if(ret!=-1)return ret;
    if(check[now])return ret = foo(now+1,cu);
    ret = min(foo(now+3,cu+1)+25000,foo(now+5,cu+2)+37000);
    ret = min(foo(now+1,cu)+10000,ret);
    if(cu>=3)ret = min(ret,foo(now+1,cu-3));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    memset(d,-1,sizeof(d));
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        check[x] = true;
    }
    cout << foo(1,0) << '\n';
}