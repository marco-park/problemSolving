#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int>tree[200001],p[200001];
bool visited[200001];
bool cycle[200001];

void dfs(int now){
    visited[now] = true;
    for(auto next:tree[now]){
        if(!visited[next]){
            p[now].push_back(next);
            dfs(next);
        }
    }
}

bool foo(int now){
    visited[now] = true;
    cycle[now] = true;
    for(auto next:p[now]){
        if(!visited[next] && foo(next))return true;
        else if(cycle[next])return true;
    }
    cycle[now] = false;
    return false;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    for(auto &x:path){
        int u = x[0];
        int v = x[1];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0);
    memset(visited,0,sizeof(visited));
    for(auto &x:order){
        int u = x[0];
        int v = x[1];
        p[u].push_back(v);
    }
    return !foo(0);
}