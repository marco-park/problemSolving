#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int N,L;
long long I; // I가 2^31 이 들어올 수 있음..

int d[32][32];
string ret;

int foo(int n,int l){
    if(!n||!l)return 1;
    int &ret = d[n][l];
    if(ret!=-1)return ret;
    ret = foo(n-1,l);
    if(l>=1)ret+=foo(n-1,l-1);
    return ret;
}

void kth(int n,int l,long long k){
    if(!n || !l)return;
    if(k < foo(n-1,l)){
        ret+="0";
        kth(n-1,l,k);
    }else{
        ret+="1";
        kth(n-1,l-1,k-foo(n-1,l));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> I;
    memset(d,-1,sizeof(d));
    kth(N,L,I-1);
    cout << ret;
    for(int i=0;i<N-ret.size();i++)cout << "0";
}