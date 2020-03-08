#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define ll long long

using namespace std;

ll a[40001],b[40001],da[40001],db[40001];
ll cnta[40001],cntb[40001],cntda[40001],cntdb[40001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) if(a[i])da[i] = da[i-1]+1;else da[i] = 0;
    for(int i=1;i<=m;i++) cin >> b[i];
    for(int i=1;i<=m;i++) if(b[i])db[i] = db[i-1]+1;else db[i] = 0;
    for(int i=1;i<=n;i++)cnta[da[i]]++;
    for(int i=1;i<=40000;i++)cntda[i] = cntda[i-1]+cnta[i];
    for(int i=1;i<=m;i++)cntb[db[i]]++;
    for(int i=1;i<=40000;i++)cntdb[i] = cntdb[i-1]+cntb[i];    

    vector<ll>p;
    for(ll i=1;i*i<=k;i++){
        if(k%i==0){
            p.push_back(i);if(i!=k/i)p.push_back(k/i);
        }
    }
    ll ret = 0;
    for(ll i:p){
        int j = k/i;
        if(i-1>40000 || j-1>40000)continue;
        ret += (cntda[40000]-cntda[i-1])*(cntdb[40000]-cntdb[j-1]);
    }
    cout << ret << '\n';
}