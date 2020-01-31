#include <iostream>
#include <cstring>
#define MOD 1000000007
long long d[101];
int n;

using namespace std;

int foo(int x){
    if(x<=1)return 1;
    long long &ret = d[x];
    if(ret!=-1)return ret;
    return ret = (foo(x-1)%MOD+foo(x-2)%MOD)%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        memset(d,-1,sizeof(d));
        cin >> n;
        long long ret = foo(n);
        ret = (ret-foo(n/2)+MOD)%MOD;
        if(n%2){
            cout << ret << '\n';
        }else{
            cout << (ret-foo(n/2-1)+MOD)%MOD << '\n';
        }
    }   
}