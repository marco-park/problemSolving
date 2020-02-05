#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        map<pair<int,int>,int>m;    // 처음부터 현재까지 나온 상태 중 가장 최신 인덱스+1
        pair<int,int>cur = {0,0};   // 처음부터 현재까지 상태
        m[cur] = 0;
        cin >> n >> s;
        int l = 0, r = n-1;
        bool flag = false;
        for(int i=0;i<n;i++){
            if(s[i]=='L')cur.first--;
            if(s[i]=='R')cur.first++;
            if(s[i]=='U')cur.second++;
            if(s[i]=='D')cur.second--;
            if(m.count(cur)){   // 같은 상태가 나왔다면(없애도 된다) *연관 배열의 find 비용은 logn, 총 O(nlogn)*
                if(i-m[cur]+1 <= r-l+1){ // 범위 차가 최소인 경우
                    flag = true;
                    l = m[cur]; // 현재 상태 가장 마지막 인덱스 + 1 ~ 현재 상태 인덱스 까지는 필요 없음(같은 상태이기 때문에) 
                    r = i;
                }
            }
            m[cur] = i+1;   // 현재 상태 가장 최신 인덱스 갱신(최소치 찾는 것이므로)
        }
        if(!flag)cout << -1 << '\n';
        else cout << l+1 << ' ' << r+1 << '\n';
    }
}