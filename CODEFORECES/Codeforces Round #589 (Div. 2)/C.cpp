#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;
#define ll long long
#define mod (ll)(1e9+7)

ll foo(int x,ll y){
    if(x==0)return 1%mod;
    if(x==1)return y%mod;
    ll tmp = foo(x/2,y)%mod;
    if(x%2==0)return (tmp%mod*tmp%mod)%mod;
    else return (tmp*y%mod*tmp%mod)%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll x;ll n;
    cin >> x >> n;
    set<ll>p;
    for(ll i = 2; i*i<=(1e9);i++){
        while(x%i == 0){
            p.insert(i);
            x/=i;
        }
    }
    if(x!=1)p.insert(x);
    ll ret = 1;
    for(auto x:p){
        ll tmp = n;
        ll cnt = 0;
        while(tmp){
            cnt+=(tmp/x);
            tmp/=x;
        }
        ret*=foo(cnt%(ll)(1e9+6),x)%mod;
        ret%=mod;        
    }
    cout << ret << '\n';
}   