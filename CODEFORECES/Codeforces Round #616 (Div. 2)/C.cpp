#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[3501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        for(int i=0;i<n;i++)cin>>a[i];
        int ret = 0;
        k = min(k,m-1);
        for(int x=0;x<=k;x++){
            int tmp = 1e9;
            for(int y=0;y<=m-1-k;y++){
                tmp = min(tmp,max(a[x+y],a[n-(m-x-y)]));
            }
            ret = max(ret,tmp);
        }
        cout << ret << '\n';
    }
}
