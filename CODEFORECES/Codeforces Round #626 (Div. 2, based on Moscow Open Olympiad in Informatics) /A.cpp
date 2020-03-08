#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int a[101],d[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
    bool flag = false;
        memset(a,0,sizeof(a));
        int cnt = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]%2==0 && !flag){
                cout << 1 << '\n' <<  i+1 << '\n';
                flag = true;
            }else cnt++;
        }
        if(flag){
            continue;
        }
        if(cnt<=1)cout << -1 << '\n';
        else {
            cnt = 0;
            cout << 2 << '\n';
            for(int i=0;i<n;i++){
                if(a[i]%2){
                    cout << i+1 << ' ';
                    cnt++;
                    if(cnt==2)break;
                }
            }
        }
    }
}