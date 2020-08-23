#include <iostream>
#include <queue>
#include <cstring>
#define INF 200000

using namespace std;

int d[INF+1];
int c,b,p;

int bfs(){
    queue<int>q;
    q.push(b);
    d[b] = 0;
    while(!q.empty()){
        int qsize = q.size();
        while(qsize--){
            int b = q.front();
            q.pop();
            if(b==c)return d[b];
            if(b && d[b-1]==-1)d[b-1] = d[b] + 1,q.push(b-1);
            if(b+1 <= INF && d[b+1]==-1)d[b+1] = d[b] +1,q.push(b+1);
            if(2*b <= INF && d[2*b]==-1)d[2*b] = d[b] +1,q.push(2*b);
        }
        c += ++p;
    }
    return -1;
}

int main(){
    cin >> c >> b;
    memset(d,-1,sizeof(d));
    cout << bfs() << '\n';
}