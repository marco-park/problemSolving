#include <iostream>
#include <string>
#include <vector>
#include <cstring>
 
using namespace std;
 
int uf[26];
bool check[26][26];
bool visited[26];
vector<int>p[26];
 
int find(int x){
    if(uf[x]==-1)return x;
    return uf[x] = find(uf[x]);
}
 
void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        uf[b] = a;
    }
}
 
void dfs(int now){
    visited[now] = true;
    printf("%c",now+'a');
    for(auto next : p[now]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next);
        }
    }
}
 
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(check,0,sizeof(check));
        memset(uf,-1,sizeof(uf));
        memset(visited,0,sizeof(visited));
        for(int i=0;i<26;i++)p[i].clear();
        string s;
        cin >> s;
        bool flag = false;
        string ret = "";
        for(int i=0;i<s.size()-1;i++){
            int a = (s[i]-'a');
            int b = (s[i+1]-'a');
            if(check[a][b] || check[b][a])continue;
            check[a][b] = check[b][a] = 1;
 
            if(find(a)!=find(b)){
                merge(a,b);
                p[a].push_back(b);
                p[b].push_back(a);
                if(p[b].size()>=3 || p[a].size()>=3){
                     cout << "NO\n";
                    flag = true;
                    break;
                }
            }else{
                cout << "NO\n";
                flag = true;
                break;
            }
        }
      
        if(!flag){
            cout << "YES\n";
            for(int i=0;i<26;i++){
                if(!visited[i] && p[i].size()<=1){
                    dfs(i);
                }
            }
            cout << '\n';
        }
    }
}