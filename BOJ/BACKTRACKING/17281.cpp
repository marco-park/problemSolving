#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>p;
int ord[9],n,board[50][9];

using namespace std;

int play(int ord[9]){
    int hitter = 0;
    int score = 0;
    
    for(int i=0;i<n;i++){
        int out = 0;
        int runner[3] = {0,0,0};    
        while(out!=3){
            int ret = board[i][ord[(hitter++)%9]];
            if(!ret)out++;
            else if(ret==4){    
                for(int k=0;k<3;k++){
                    score+=runner[k];
                    runner[k] = 0;
                }
                score++;
            }else{
                for(int k=2;k>=0;k--){
                    if(!runner[k])continue;
                    runner[k] = 0;
                    if(k+ret >=3)score++;
                    else runner[k+ret] = 1;
                }
                runner[ret-1] = 1;
            }
        }
    }
    return score;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=1;i<9;i++)p.push_back(i);
    
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<9;j++)
            cin >> board[i][j];

    int ret = 0;

    do{
        for(int i=0;i<3;i++)ord[i] = p[i];
        ord[3] = 0;
        for(int i=3;i<8;i++)ord[i+1] = p[i];
        ret = max(ret,play(ord));
    }while(next_permutation(p.begin(),p.end()));

    cout << ret << '\n';
}