#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>p;

int _count(int x){
    int ret=0;
    while(x){
        ret+=(x%2);
        x/=2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;

    cin >> n >> k;
    p.resize(n);

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(auto c:s) p[i]|=(1<<(c-'a'));
    }
    
   int base = 0;
   base |= (1<<('a'-'a'));
   base |= (1<<('n'-'a'));
   base |= (1<<('t'-'a'));
   base |= (1<<('c'-'a'));
   base |= (1<<('i'-'a'));

   int ret = 0;

   for(int i=base; i<(1<<26); i++){
       if((i&base)!=base)continue;
       if(_count(i)>k)continue;
       int cnt = 0;
       for(auto x:p)cnt += ((x&i) == x);
       ret = max(ret,cnt);
   }
   cout << ret << '\n';
}