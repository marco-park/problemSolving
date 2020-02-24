#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;
int uf[10001];
int cost[10001];

int find(int a){
    if(uf[a]==-1)return a;
    return uf[a] = find(uf[a]);
}

void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a==b)
        return;
    if(cost[a]<cost[b])
        uf[b] = a;
    else
        uf[a] = b;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   

    set<int> st;
    int n,m,k;
    memset(uf,-1,sizeof(uf));
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)cin >> cost[i];
    int ret = 0;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        merge(u,v);
    }
    for(int i=1;i<=n;i++)
        st.insert(find(i));
    
    for(auto x:st)ret+=cost[x];
    if(ret > k)cout << "Oh no\n";
    else cout << ret << '\n';
}