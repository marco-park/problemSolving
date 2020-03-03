#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> key){
    vector<vector<int>> a;
    a.resize(key.size());
    for(int i=0;i<key.size();i++)
        a[i].resize(key.size());

    for(int j=key.size()-1;j>=0;j--){
        for(int i=0;i<key.size();i++){
            a[(key.size()-1)-j][i] = key[i][j];
        }
    }
    return a;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size();
    int m = key.size();
    vector<vector<int>>tmp;
    tmp.resize(n+2*(m-1));
    for(int i=0;i<tmp.size();i++)tmp[i].resize(n+2*(m-1));
    for(int i=m-1;i<=n+m-2;i++){
        for(int j=m-1;j<=n+m-2;j++){
            tmp[i][j] = lock[i-(m-1)][j-(m-1)];
        }
    }
    lock = tmp;

    for(int ii=0;ii<=tmp.size()-m;ii++){
        for(int jj=0;jj<=tmp.size()-m;jj++){
            for(int k=0;k<4;k++){
                lock = tmp;
                if(k)key = rotate(key);
                bool flag = false;
                for(int i=0;i<m;i++){
                    for(int j=0;j<m;j++){
                        int nx = i+ii;
                        int ny = j+jj;
                        if(nx>=m-1 && nx<=n+m-2 && ny>=m-1 && ny<=n+m-2){
                            if(lock[nx][ny] && key[i][j]){flag = true;break;}
                            if(!lock[nx][ny] && !key[i][j]){flag = true;break;}
                            if(key[i][j])lock[nx][ny] = 1;
                        }
                    }
                    if(flag)break;
                }
                if(flag){
                    if(k==3)key = rotate(key);
                    continue;
                }
               
                for(int i=m-1;i<=n+m-2;i++){
                    for(int j=m-1;j<=n+m-2;j++){
                        if(!lock[i][j]){flag = true;break;}
                    }
                }
                if(!flag)return true;
                if(k==3)key = rotate(key);
            }
        }
    }
    return false;
}