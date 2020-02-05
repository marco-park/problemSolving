#include <iostream>
 
using namespace std;
int a[2001];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int sum=0;
        int even=0;
        int odd=0;
 
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum+=a[i];
            if(a[i]%2==0)even++;
            else odd++;
        }
        if(sum%2){
            cout << "YES\n";
        }else{
            if(even && odd &&odd%2==0){
                cout << "YES\n";
            }else cout << "NO\n";
        }   
    }
}
