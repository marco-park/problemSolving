#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--){
        string s;
        int n;
        cin >> n >> s;
        int flag = 0;
        for(int i=0;i<n;i++){
            if((s[i]-'0')%2)flag++;
        }
        if(flag<2){
            cout << -1 << '\n';
        }else{
            int i;
            for(i=n-1;i>=0;i--){
                if((s[i]-'0')%2){
                    break;
                }
            }
            char last = s[i];
            i--;
            for(;i>=0;i--){
                if((s[i]-'0')%2){
                    cout << s[i] << last << '\n';
                    break;
                }
            }
        }
    }
}