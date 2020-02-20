#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
const ll MOD = 1e9+7;

using namespace std;

ll a[100001],m[100001],d[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll maxj = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]]++;
        maxj = max(maxj,a[i]);
    }
    for(int i=1;i<=maxj;i++)
        d[i] = (d[i-1]%MOD+i*m[i]%MOD)%MOD;
   
    ll ret = 0;
    for(int j=0;j<n;j++){
        ret+=((d[a[j]-1]%MOD)*a[j]%MOD)%MOD*(d[maxj]%MOD-d[a[j]]%MOD+MOD)%MOD;
        ret%=MOD;
    }
    cout << ret << '\n';
}