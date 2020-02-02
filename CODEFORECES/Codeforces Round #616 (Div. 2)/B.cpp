#include <iostream>
#include <string>
 
using namespace std;
 
int a[300001],d[300001][2];
int n;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
            d[i][0] = d[i][1] = 0;
        }
 
        bool flag = false;
        for(int k=0;k<n;k++){
            d[k][0] = a[k]<k;
            if(k>=1)d[k][0] += d[k-1][0];
        }
        for(int k=n-1;k>=0;k--){
            d[k][1] = a[k]<n-k-1;
            if(k+1<n)d[k][1] += d[k+1][1];
        }
        for(int k=0;k<n;k++){
            if(!d[k][0] && !d[k][1]){
                cout << "Yes\n";
                flag = true;
                break;
            }
        }
        if(!flag)cout << "No\n";
    }
}