#include <iostream>
#include <string>
#include <algorithm>

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

        int ret = 0;
        int sum = 0;
        bool flag = false;
        for(int i=0;s[i];i++){
            if(s[i]=='A'){
                flag = true;
                sum = 0;
            }
            else if(flag){
                sum++;
                ret = max(ret,sum);
            }
        }
        cout << ret << '\n';
    }
}
