#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Pack{
    string name;
    int w,v;
};
int d[1001][100];
int cnt;
struct Pack a[101];
vector<string>p;

int w,n;
int foo(int weight,int idx){
    if(idx==n)return 0;
    int &ret = d[weight][idx];
    if(ret!=-1)return ret;
    ret = foo(weight,idx+1);
    if(weight >= a[idx].w)ret = max(ret,foo(weight-a[idx].w,idx+1)+a[idx].v);
    return ret;
}

void bar(int weight,int idx){
    if(idx==n)return;
    if(foo(weight,idx)==foo(weight,idx+1))bar(weight,idx+1);
    else {
        p.push_back(a[idx].name);
        bar(weight-a[idx].w,idx+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> w;
        memset(d,-1,sizeof(d));
        p.clear();
        for(int i=0;i<n;i++)cin >> a[i].name >> a[i].w >> a[i].v;
        cout << foo(w,0) << ' ';
        bar(w,0);
        cout << p.size() << '\n';
        for(auto s:p)cout << s << '\n';
    }
}