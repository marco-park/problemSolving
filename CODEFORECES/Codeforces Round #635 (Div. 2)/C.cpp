#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
vector<int>p[200001];
vector<int>tree[200001];
pair<int,int> d[200001];
bool visited[200001];
int c[200001];
#define ll long long 

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.first-a.second > b.first-b.second;
}

void dfs(int now){
    visited[now] = true;
    for(auto next:p[now]){
        if(visited[next])continue;
        d[next].first = d[now].first+1;
        dfs(next);
        d[now].second += d[next].second+1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   

    int n,k;
    cin >> n >> k;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        p[a].push_back(b);
        p[b].push_back(a);
    }
   
    dfs(0);    
    sort(d,d+n,cmp);
    ll ret = 0;

    for(int i=0;i<k;i++){
        ret+=((ll)d[i].first-(ll)d[i].second);
    }
    cout << ret << '\n';
}