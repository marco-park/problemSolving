#include <iostream>
#include <algorithm>

using namespace std;

int a[9],ret[9];
bool visited[9];
bool visited_depth[10001][9];

int n,m;

void foo(int depth){
    if(depth==m){
        for(int i=0;i<m;i++)cout << ret[i] << ' '; 
        cout << '\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(!visited[i] && !visited_depth[a[i]][depth]){
            visited[i] = true;
            visited_depth[a[i]][depth] = true;
            ret[depth] = a[i];
            foo(depth+1);
            visited[i] = false;
        }
    }
    for(int i=0;i<n;i++)visited_depth[a[i]][depth] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    foo(0);
}