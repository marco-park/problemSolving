#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N,K;
int ped[10][10];
int seq[3],wins[3];
vector<int>p[3];

bool foo(){
    int p1 = 0, p2 = 1;
    while(1){
        for(int i=0;i<3;i++){
            if(wins[i]==K)return !i;
            if(seq[i]==p[i].size())return false;
        }
        
        int ret = ped[p[p1][seq[p1]++]-1][p[p2][seq[p2]++]-1];
        int tmp =  3 - (p1+p2);
        if(!ret) p1 = p2;
        else if(ret==1) p1 = (p1<p2) ? p2 : p1;
        
        wins[p1]++;
        p2 = tmp;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin >> ped[i][j];
    for(int i=1;i<=2;i++){
        p[i].resize(20);
        for(int j=0;j<20;j++)cin >> p[i][j];
    }
    for(int i=1;i<=N;i++)p[0].push_back(i);

    bool ret = false;
    do{
        memset(seq,0,sizeof(seq));
        memset(wins,0,sizeof(wins));
        ret |= foo();
    }while(next_permutation(p[0].begin(),p[0].end()));

    cout << ret << '\n';
}