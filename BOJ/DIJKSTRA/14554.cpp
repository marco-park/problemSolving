#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long

using namespace std;

ll mod = 1e9+9;
ll d[100001],cnt[100001];

int n,m,s,e;

struct E{
    int v;
    ll c;
    bool operator < (const E &a) const {return a.c < c;}
};

vector<E>p[100001];

void dijk(){
    for(int i=1;i<=n;i++)d[i] = 1e18+1;
    priority_queue<E>pq;
    pq.push({s,0});
    d[s] = 0;
    cnt[s] = 1;
    while(!pq.empty()){
        int now = pq.top().v;
        ll prevcost = pq.top().c;
        pq.pop();
        if(d[now] < prevcost)continue;
        for(auto x:p[now]){
            int next = x.v;
            ll cost = x.c;
            if(d[now] + cost < d[next]){
                d[next] = d[now] + cost;
                cnt[next] = cnt[now];
                pq.push({next,d[next]});
            }else if(d[now] + cost == d[next]){
                cnt[next] += cnt[now]%mod;
                cnt[next]%=mod;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> s >> e;
    for(int i=0;i<m;i++){
        int u,v;
        ll c;
        cin >> u >> v >> c;
        p[u].push_back({v,c});
        p[v].push_back({u,c});
    }
    dijk();
    cout << cnt[e] << '\n';
}