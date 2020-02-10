#include <iostream>
#include <algorithm>

using namespace std;

int a[11],op[4];

pair<int,int> foo(int idx){
    pair<int,int> ret = {-1e9,1e9};
    if(!idx)return {a[idx],a[idx]};
    
    for(int i=0;i<4;i++){
        if(!op[i])continue;
        op[i]--;
        auto next = foo(idx-1);
        if(i==0)ret = {max(ret.first,next.first + a[idx]),min(ret.second,next.second + a[idx])}; 
        if(i==1)ret = {max(ret.first,next.first - a[idx]),min(ret.second,next.second - a[idx])}; 
        if(i==2)ret = {max(ret.first,next.first * a[idx]),min(ret.second,next.second * a[idx])};
        if(i==3 && a[idx])ret = {max(ret.first,next.first / a[idx]),min(ret.second,next.second / a[idx])};
        op[i]++;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<4;i++)cin >> op[i];
    auto ret = foo(n-1);
    cout << ret.first << '\n' << ret.second << '\n';
}