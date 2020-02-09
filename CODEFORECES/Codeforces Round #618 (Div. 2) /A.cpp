#include <iostream>
 
using namespace std;
 
int a[101];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        int ret = 0;
        cin >> n;
        int sum=0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(!a[i]){
                sum++;
                ret++;
            }
            sum+=a[i];
        }
        if(!sum){
            ret++;
        }
        cout << ret << '\n';
    }
}