#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int a[100001][3];
int cnt[100006];
vector<int>p[100006];
bool visited[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    int n;
    cin >> n;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
            cnt[a[i][j]]++;
            p[a[i][j]].push_back(i);
        }
    } 
    int first,second;
    for(int i=1;i<=n;i++)if(cnt[i]==1){first = i;break;}
    int g = p[first][0];
    for(int i=0;i<3;i++)if(cnt[a[g][i]]==2){second = a[g][i];break;}
    vector<int>ret;
    ret.push_back(first);
    ret.push_back(second);
    while(ret.size()<n){
        int sum = 0;
        for(int i=0;i<3;i++)sum+=a[g][i];
        int third = sum - (first+second);
        ret.push_back(third);
        visited[g] = true;
        first = second;
        second = third;
        for(auto t:p[first])
            if(!visited[t])g=t;
    }
    for(auto x:ret)cout << x << ' ';
    cout << '\n';
}