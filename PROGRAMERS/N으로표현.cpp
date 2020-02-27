#include <iostream>
#include <algorithm>

using namespace std;

int ret=9;

void dfs(int n,int Number,int idx,int N){
    if(idx > 8) return;
    if(n==Number){
        ret = min(ret,idx);
        return;
    }
    int tmp = 0;
    for(int i=1;i<=8-idx;i++){
        tmp = tmp*10+N;
        dfs(n+tmp,Number,idx+i,N);
        dfs(n-tmp,Number,idx+i,N);
        dfs(n*tmp,Number,idx+i,N);
        dfs(n/tmp,Number,idx+i,N);
    }
}

int solution(int n,int Number){
    dfs(0,Number,0,n);
    if(ret==9)ret=-1;
    return ret;
}