#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int cost[501][501];
int d[501][501];
int n;
pair<int,int>a[501];

int foo(int now,int cnt){
    if(now == n-1)return 0;
    int &ret = d[now][cnt];
    if(ret!=-1)return ret;
    ret = 1e9;
    for(int i=0;i<=cnt;i++){
        int next = now+i+1;
        if(next<=n-1)ret = min(ret,foo(next,cnt-i)+cost[now][next]);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> n >> k;
    memset(d,-1,sizeof(d));

    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;

    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cost[i][j] = abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second);
        }
    }

    cout << foo(0,k) << '\n';
}