#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n;
int a[101];
int d[101][101][101][2];
bool check[101];

int foo(int pos,int e,int o,int flag){  //flag : 이전 인덱스 parity
    if(pos==n)return 0;
    int &ret = d[pos][e][o][flag];
    if(ret!=-1)return ret;
    
    ret = 0x3f3f3f3f;
    if(a[pos]) ret = foo(pos+1,e,o,a[pos]%2)+(a[pos]%2 != flag);
    else {
        if(e)ret = min(ret,foo(pos+1,e-1,o,0)+flag);
        if(o){
            if(!pos)ret = min(ret,foo(pos+1,e,o-1,1)+flag); 
            else ret = min(ret,foo(pos+1,e,o-1,1)+1-flag);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i])check[a[i]] = true;
    }
    int e=0,o=0;
    for(int i=1;i<=n;i++){
        if(!check[i]){
            if(i%2)o++;
            else e++;
        }
    }
    memset(d,-1,sizeof(d));
    cout << foo(0,e,o,a[0]%2) << '\n';
}