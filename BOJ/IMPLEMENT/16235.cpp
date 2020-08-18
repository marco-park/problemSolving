#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};

int y[10][10],A[10][10];
vector<int> p[10][10];
const int INF = 0x3f3f3f3f;
int N,M,K;

void foo(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int tmp = 0;
            if(p[i][j].size()==0)continue;
            sort(p[i][j].begin(),p[i][j].end());
            for(auto &now:p[i][j]){
                if(now==INF)break;
                if(y[i][j]>=now){
                    y[i][j] -= now;
                    now++;
                }
                else {
                    tmp+=now/2;
                    now = INF;
                }
            }
            sort(p[i][j].begin(),p[i][j].end());
            auto it = p[i][j].end();
            it--;
            while(*it==INF){
                 p[i][j].erase(it--);
            }
            y[i][j]+=tmp;
        }
    }    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(auto now:p[i][j]){
                if(now%5)continue;
                for(int k=0;k<8;k++){
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(x<0 || y<0 || x>=N || y>=N)continue;
                    p[x][y].push_back(1);
                }
            }
            y[i][j]+=A[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;

    for(int i=0;i<N;i++)for(int j=0;j<N;j++){cin >> A[i][j];y[i][j]+=5;}
    for(int i=0;i<M;i++){
        int x,y,z;
        cin >> x >> y >> z;
        p[x-1][y-1].push_back(z);
    }
    while(K--)foo();
    int ret = 0;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)ret+=p[i][j].size();
    cout << ret << '\n';
}
