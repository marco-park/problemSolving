#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

string a[1501];
map<string,int>m;

int d[31];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,kk;
    cin >> n >> kk;
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]] = i;
    }

    int can = 'S'+'E'+'T';
    int ret = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            string tmp="";
            for(int k=0;k<kk;k++){
                if(a[i][k]==a[j][k])tmp+=a[i][k];
                else tmp+=char((can-(a[i][k]+a[j][k])));
            }
            if(!m.count(tmp))continue;
            if(m[tmp] <= i || m[tmp] <=j)continue;
            if(m.count(tmp))ret++;
        }
    }
    cout << ret << '\n';
}