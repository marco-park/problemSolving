#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int d[1000001][11];
string s;
int k;

int foo(int depth){
    int n = stoi(s);

    if(depth == k)return n;

    int &ret = d[n][depth];
    if(ret!=-1)return ret;

    for(int i=0;i<s.size()-1;i++){
        for(int j=i+1;j<s.size();j++){
            if(!i && s[j]=='0')continue;
            swap(s[i],s[j]);
            ret = max(ret,foo(depth+1));
            swap(s[i],s[j]);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(d,-1,sizeof(d));
    cin >> s >> k;
    cout << foo(0) << '\n';

}