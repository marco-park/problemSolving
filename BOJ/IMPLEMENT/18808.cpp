#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int n,m,k,r,c;
int map[41][41],a[101][41][41];
pair<int,int>s[101];

bool suit(int sx,int sy,int k){
    int r = s[k].first;
    int c = s[k].second;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int mx = i+sx;
            int my = j+sy;
            if(mx>=n || my>=m)return false;
            if(map[mx][my] && a[k][i][j])return false;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int mx = i+sx;
            int my = j+sy;
            if(a[k][i][j])map[mx][my] = 1;
        }
    }
    return true;
}

void rotate(int k){
    int r = s[k].first;
    int c = s[k].second;

    int tmp[41][41];
    for(int i=0;i<r;i++)for(int j=0;j<c;j++)tmp[i][j] = a[k][i][j];

    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            a[k][i][j] = tmp[r-1-j][i];
        }
    }
    s[k] = {c,r};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    cin >> n  >> m >> k;
    for(int t=0;t<k;t++){
        cin >> r >> c;
        s[t] = {r,c};
        for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin >> a[t][i][j];             
        
        bool flag = false;
        for(int tt=0;tt<4;tt++){
            r = s[t].first;
            c = s[t].second;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(suit(i,j,t)){
                        flag = true;
                        break;
                    }
                }
                if(flag)break;
            }
            if(flag)break;
            rotate(t);
        }
    }
    int ret = 0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)ret+=map[i][j];
    cout << ret << '\n';
}