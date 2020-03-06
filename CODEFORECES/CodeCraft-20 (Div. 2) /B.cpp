#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<string>p;
        string ret = s;
        int idx = 0;
        for(int i=0;s[i];i++){
            string tmp = s.substr(i);
            string tmp2 = s.substr(0,i);
            if((s.size()-i)%2)reverse(tmp2.begin(),tmp2.end());
            tmp+=tmp2;
            if(ret>tmp){
                ret = tmp;
                idx = i;
            }
        }
        cout << ret << '\n' << idx+1 << '\n';
    }
}