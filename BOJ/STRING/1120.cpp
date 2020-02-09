#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a,b;
    cin >> a >> b;
    int ret = 51;
    for(int start=0;start<=b.size()-a.size();start++){
        int tmp =0;
        for(int i=0;i<a.size();i++){
            if(i>=start)tmp+=(a[i]!=b[i+start]);
        }
        ret = min(tmp,ret);
    }
    cout << ret << '\n';
}