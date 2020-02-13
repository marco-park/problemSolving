#include <iostream>
#include <string>
#include <vector>
#include <cstring>
 
using namespace std;
 
bool check[26][26];
int d[26];
vector<int>p[26];
vector<char>ret;
 
bool dfs(int now,int par){
    if(p[now].size()>=3)return true;
    ret.push_back((char)now+'a');
    for(auto next : p[now]){
        if(next!=par){
            if(!d[next]){
                d[next] = d[now]+1;
                if(dfs(next,now))return true;
            }else if(d[now] > d[next])return true;
        }
    }
    return false;
}
 
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(check,0,sizeof(check));
        memset(d,0,sizeof(d));
        for(int i=0;i<26;i++)p[i].clear();
        ret.clear();
        string s;
        cin >> s;
        for(int i=0;i<s.size()-1;i++){
            int a = (s[i]-'a');
            int b = (s[i+1]-'a');
            if(check[a][b] || check[b][a])continue;
            check[a][b] = check[b][a] = 1;
            p[a].push_back(b);
            p[b].push_back(a);
        }
        
        bool flag = false;
        for(int i=0;i<26;i++){
            if(p[i].size()==1)flag = true;
        }
        if(!flag && s.size()>=2){
            cout << "NO\n";
            continue;
        }
        flag = false;
        for(int i=0;i<26;i++){
            if(!d[i] && p[i].size()<=1)
                flag |= dfs(i,-1);
        }
 
        if(!flag){
            cout << "YES\n";
            for(auto x:ret)cout << x;
            cout << '\n';
        }else{
            cout << "NO\n";
        }
    }
}