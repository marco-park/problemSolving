#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n,m;
int map[50][50];
vector<pair<pair<int,int>, bool>>c;
vector<pair<int,int>>h;

int bar(int x1,int y1,int x2,int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int cal(){
    int ret = 0;
    for(int i=0;i<h.size();i++){
        int t = 101;
        for(int j=0;j<c.size();j++){
            if(c[j].second) 
                t = min(t, bar(h[i].first,h[i].second,c[j].first.first,c[j].first.second));
        }
        ret+=t;
    }
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j] == 2){
                c.push_back({{i,j},false});
            }else if(map[i][j]==1){
                h.push_back({i,j});
            }
        }
    }

    int ret = 100 * 100;

    for(int i=0;i<(1<<c.size());i++){
        int cnt = 0, tmp = i;
        for(int i=0;i<c.size();i++)c[i].second  = false;
        while(tmp){
            cnt += tmp%2;
            tmp/=2;
        }
        if(cnt > m) continue;
        for(int j=0;j<c.size();j++)c[j].second = (i & (1<<j));  
        ret = min(ret,cal());
    }
    cout << ret << '\n';
}