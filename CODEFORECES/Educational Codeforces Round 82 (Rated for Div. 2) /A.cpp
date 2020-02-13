#include <iostream>
 
using namespace std;
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
    while(n--){
        int ret = 0;
        string s;
        cin >> s;
        bool flag = false;
        int first=-1,last=-1;
        for(int i=0;s[i];i++){
            if(s[i]=='1'){
                first = i;
                break;
            }
        }
        
        if(first==-1){
            cout << 0 << '\n';
            continue;
        }
 
        for(int i=0;s[i];i++){
            if(s[i]=='1')last = i;
        }
        for(int i=first+1;i<last;i++){
            if(s[i]=='0')ret++;
        }
        cout << ret << '\n';
    }
}