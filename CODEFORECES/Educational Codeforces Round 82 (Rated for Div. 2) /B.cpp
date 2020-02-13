#include <iostream>
#include <algorithm>
#define ll long long
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--){
        ll n,g,b;
        cin >> n >> g >> b;
        ll target;
        if(n%2)target = n/2+1;
        else target = n/2;
        ll r = target/g;
        ll c = target%g;
        if(!c){
            r--;
            c+=g;
        }
        ll x = r*(g+b);
        cout << max(n,x+c)<< '\n';
    }
}