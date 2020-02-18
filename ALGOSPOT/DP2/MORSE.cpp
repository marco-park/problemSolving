#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

ll d[201][201];

void foo(int n,int m,int k){
    if(!n && !m)return;
    if(k>d[n+m-1][m]){
        cout << "o";
        foo(n,m-1,k-d[n+m-1][m]);
    }else{
        cout << "-";
        foo(n-1,m,k);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    d[0][0]=1;
    for(int i=1;i<=200;i++){
        d[i][0] = 1;
        for(int j=1;j<=200;j++){
            d[i][j] = d[i-1][j-1] + d[i-1][j];
            d[i][j] = min(d[i][j],(ll)0x3f3f3f3f);
        }
    }
    
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        foo(n,m,k);
        cout << '\n';
    }
}
