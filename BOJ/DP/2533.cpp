#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int>p[1000001],tree[1000001];
bool visited[1000001];
int d[1000001][2],track[1000001][2];

void makeTree(int now){
    visited[now]=true;
    for(auto next:p[now]){
        if(!visited[next]){
            tree[now].push_back(next);
            makeTree(next);
        }
    }
}

int foo(int now,bool isParentEarlyAdapter){
    int &ret = d[now][isParentEarlyAdapter];
    if(ret!=-1)return ret;
    ret = 1;
    int tmp = 0;
    for(auto next:tree[now])ret += foo(next,true);
    if(isParentEarlyAdapter){
        for(auto next:tree[now])tmp+=foo(next,false);
        ret = min(ret,tmp);
    }
    return ret;
}

void bar(int now,bool isParentEarlyAdapter){
    int notPick = 0x3f3f3f3f;
    int pick = 1;
    for(auto next:tree[now])
        pick += foo(next,true);
    if(isParentEarlyAdapter){
        notPick = 0;
        for(auto next:tree[now])
            notPick += foo(next,false);
    }
    if(pick >= notPick){
        for(auto next : tree[now]){
            bar(next,false);
        }
    }else{
        cout << now << "!\n";
        for(auto next:tree[now]){
            bar(next,true);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    memset(d,-1,sizeof(d));
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    makeTree(1);
    cout << foo(1,true) << '\n';
    //bar(1,true);
}