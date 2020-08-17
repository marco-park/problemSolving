#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;


struct E{
    int v,c;
    bool operator < (const E &a)const{return a.c < c;}
};

int n,m;
int d[1001],par[1001];
vector<E>p[1001];
bool check[1001][1001];

int dijk(){
    for(int i=1;i<=n;i++)d[i] = INF;
    priority_queue<E>pq;
    pq.push({1,0});
    d[1] = 0;
    while(!pq.empty()){
        int now =  pq.top().v;
        int prevCost = pq.top().c;
        pq.pop();
        if(prevCost > d[now])continue;
        for(auto x:p[now]){
            int next = x.v;
            int cost = x.c;
            if(check[now][next])continue;
            if(d[now] + cost < d[next]){
                d[next] = d[now] + cost;
                par[next] = now;
                pq.push({next,d[next]});
            }
        }
    }
    return d[n] == INF ? -1 : d[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    while(m--){
        int u,v,c;
        cin >> u >> v >> c;
        p[u].push_back({v,c});
        p[v].push_back({u,c});
    }
    dijk();
    int e=n;
    int ret = 0;
    par[1] = -1;
    while(e!=-1){
        int parent = par[e];
        check[parent][e]  = true;
        ret = max(ret,dijk());
        check[parent][e]  = false;
        e = parent;
    }
    cout << ret << '\n';
}