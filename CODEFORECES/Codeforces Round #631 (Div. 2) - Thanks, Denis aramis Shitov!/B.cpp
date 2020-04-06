#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define ll long long

using namespace std;
ll a[200001];
ll d[200001];

ll foo(ll x){return x*(x+1)*(2*x+1)/6;}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        for(ll i=0;i<n;i++){
            cin >> a[i];
            if(i)d[i] = d[i-1]+(a[i]*a[i]);
            else d[0] = a[0]*a[0];
        }
        vector<pair<ll,ll>>ret;
        for(ll i=0;i<n-1;i++)
            if(foo(i+1) == d[i] && foo(n-i-1) == (d[n-1]-d[i]))ret.push_back({i+1,n-i-1});
        cout << ret.size() << '\n';
        for(auto x:ret)cout << x.first << ' ' << x.second << '\n';
    }
}