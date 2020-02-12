#include <iostream>
#include <algorithm>

using namespace std;

int a[100001],d[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
        d[i] = i?d[i-1]+a[i]:a[i];
    }
    int ret = 0;
    int left = 0;
    for(int i=0;i<=n-m;i++){
        ret = max(ret,d[i+m-1]-left);
        left = min(left,d[i]);
    }
    cout << ret << '\n';
}