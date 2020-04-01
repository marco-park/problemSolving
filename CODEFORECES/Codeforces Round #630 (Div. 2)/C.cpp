#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int cnt[200001][26];
int ret[200001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   

    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        for(int i=0;i<n;i++)for(int j=0;j<26;j++)cnt[i][j] = 0;
        for(int i=0;i<n;i++)ret[i] = -1;
        string s;
        cin >> s;
        for(int i=0;s[i];i++)cnt[i%k][s[i]-'a']++;
      
        for(int i=0;i<=k/2;i++){
            int tmp = -1;
            for(int j=0;j<26;j++){
                if(cnt[i][j] + cnt[k-1-i][j] > tmp){
                    ret[i] = ret[k-1-i] = j;
                    tmp = cnt[i][j] + cnt[k-1-i][j];
                }
            }    
        }
        int rret = 0;
        for(int i=0;s[i];i++)if(s[i]-'a'!=ret[i%k])rret++;
        cout << rret << '\n';
    }
}