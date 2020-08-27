#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define ll long long
 
using namespace std;
ll n;
vector<int>p[100001];
ll d[100001];
vector<ll>ret;
deque<ll>prime;
const ll MOD = 1e9+7;
 
void dfs(int now){
    d[now] = 1;
    for(auto next:p[now]){
        if(d[next])continue;   
        dfs(next);
        d[now] += d[next];
    }
    if(now)ret.push_back((d[now] * (n-d[now])));
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++)p[i].clear();
        ret.clear();
        prime.clear();
        memset(d,0,sizeof(d));
        for(int i=0;i<n-1;i++){
            int u,v;
            cin >> u >> v;
            u--;v--;
            p[u].push_back(v);
            p[v].push_back(u);
        }
        int m;
        cin >> m;
        for(int i=0;i<m;i++){
            ll x;
            cin >> x;
            prime.push_back(x);
        }
        dfs(0);
        sort(ret.rbegin(),ret.rend());
        sort(prime.rbegin(),prime.rend());
        ll ans = 0;
        if(m<=n-1){
            while(prime.size()!=n-1)prime.push_back(1);
            for(int i=0;i<n-1;i++){
                ans += (ret[i]%MOD * prime[i]%MOD);
                ans %= MOD;
            }
        }else{
            ll tmp = 1;
            while(prime.size()!=n-2){
                tmp *= prime[0]%MOD;
                tmp%=MOD;
                prime.pop_front();
            }
            ans += (ret[0] * tmp%MOD);
            ans %= MOD;
            
            for(int i=1;i<n-1;i++){
                ans += (ret[i]%MOD * prime[i-1]%MOD);
                ans %= MOD;
            }
        }
        cout << ans << '\n';
    }
}