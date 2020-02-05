#include <iostream>
 
using namespace std;
 
double foo(int x){
    int tmp = x;
    double ret =1;
    double m =1;
    while(x){
        ret = ret*10 +1;
        m*=10;
        x/=10;
    }
    double tt = ret/m;
    return tmp*tt;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << (int)foo(n) << '\n';
    }
}