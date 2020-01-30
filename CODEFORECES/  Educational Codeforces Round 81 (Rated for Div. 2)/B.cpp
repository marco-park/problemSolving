#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define ll long long
ll d[100001];
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        ll n,x;
        cin >> n >> x;
        string s;
        cin >> s;
        ll c0=0,c1=0;
        memset(d,0,sizeof(d));
        for(int i=0;i<n;i++){
            if(s[i]=='1')c1++;
            else c0++;
            d[i] = c0-c1;
        }
    
        ll ret = 0;
        bool flag = false;
        for(int i=0;i<n;i++){
            if(d[i]==x)flag = true;
        }
        if(!x)ret++;
        if(!d[n-1]){
            if(flag){
                cout << -1 << '\n';
            }else{
                cout << ret << '\n';
            }
            continue;
        }
        for(int i=0;i<n;i++){
            if((x-d[i])%d[n-1]==0 && ((x-d[i])/d[n-1])>=0)ret++;
        }
        cout << ret << '\n';
    }
}