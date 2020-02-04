#include <iostream>
#include <cstring>

using namespace std;
int map[9][9];
bool foo(int n){
    if(n==81)return true;
    int x = n/9;
    int y = n%9;
    if(map[x][y]) return foo(n+1);
    bool check[10];
    memset(check,0,sizeof(check));

    for(int i=0;i<9;i++){
        check[map[x][i]] = true;
        check[map[i][y]] = true;
        check[map[(x/3)*3+i/3][(y/3)*3+i%3]] = true;
    }
    for(int i=1;i<=9;i++){
        if(!check[i]){
            map[x][y] = i;
            if(foo(n+1))return true;
            map[x][y] = 0;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cin >> map[i][j];
    foo(0);
     for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}