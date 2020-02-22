#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int d[1001][3],a[1001];

int foo(int idx,int k){
    if(idx==n)return 0;
    int &ret = d[idx][k];
    if(d[idx][k]!=-1)return ret;
    if(a[idx]==k) ret = foo(idx+1,(k+1)%3)+1;
    else ret = foo(idx+1,k);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   

    memset(d,-1,sizeof(d));
    cin >> n;
    for(int i=0;i<n;i++)cin >>a[i];
    cout << foo(0,0) << '\n';
}