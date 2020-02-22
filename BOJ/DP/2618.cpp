#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
int n,w;

pair<int,int>a[1003];
int d[1003][1003],t[1003];

int dist(int x,int y){
    return abs(a[x].first-a[y].first)+abs(a[x].second-a[y].second);
}

int foo(int x,int y){  
    int now = max(x,y)+1;
    if(now==w+2)return 0;
    int &ret = d[x][y];
    if(ret!=-1)return ret;
    return ret = min(foo(now,y)+dist(x,now),foo(x,now)+dist(y,now));
}

void track(int x,int y){
    int prev = max(x,y)+1;
    if(prev==w+2)return;
    if(d[prev][y]+dist(x,prev) < d[x][prev]+dist(y,prev)){
        t[prev] = 1;
        track(prev,y);
    }else{
        t[prev] = 2;
        track(x,prev);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(d,-1,sizeof(d));

    cin >> n >> w;
    for(int i=2;i<w+2;i++){
        cin >> a[i].first >> a[i].second;
    }
    a[0].first = a[0].second = 1;
    a[1].first = a[1].second = n;
    cout << foo(0,1) << '\n';
    track(0,1);
    for(int i=2;i<w+2;i++)cout << t[i] << '\n';
}