#include <iostream>
#include <cstring>
#define ld long double

using namespace std;

int n,m;
ld d[1001][1001*2+1]; 

ld foo(int days,int climbed) { //모든 조합 길이,크기 고정되면 유일한 상태 표현 가능
    //days일(수열 길이)에 climed(수열 크기)까지 올라왔을 때 m일 안에 n이상 올라갈 수 있는 확률
    if(days==m)return (climbed>=n)?1.0:0.0;
    ld &ret = d[days][climbed];
    if(ret!=-1)return ret;
    return ret = 0.25*foo(days+1,climbed+1)+0.75*foo(days+1,climbed+2);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(d,0,sizeof(d));
        for(int i=0;i<=m;i++)for(int j=0;j<=m*2;j++)d[i][j] = -1;
        //double에 memset 안먹는다.
        printf("%.10Lf\n",foo(0,0));
    }
}