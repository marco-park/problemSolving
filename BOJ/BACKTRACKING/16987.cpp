#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
int ret;

struct E{
    int h,w;
};
vector<E>p;

void foo(int idx){
    int tmp = 0;
    for(auto x:p)tmp+=(x.h <= 0);
    ret = max(ret,tmp); 
    if(idx==N)return;
    
    if(p[idx].h <= 0){
        foo(idx+1);
        return;
    }

    for(int i=0;i<N;i++){
        if(p[i].h <= 0 || i==idx)continue;
        p[idx].h -= p[i].w;
        p[i].h -= p[idx].w;
        foo(idx+1);
        p[idx].h += p[i].w;
        p[i].h += p[idx].w;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        int h,w;
        cin >> h >> w;
        p.push_back({h,w});
    }
    foo(0);
    cout << ret << '\n';
}