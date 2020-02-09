#include <iostream>
#include <algorithm>
 
using namespace std;
 
int a[200001];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0;i<n*2;i++){
            cin >> a[i];
        }
        sort(a,a+2*n);
        int a1 = a[n];
        int a2 = a[n-1];
        cout << a1-a2 << '\n';
    }
}