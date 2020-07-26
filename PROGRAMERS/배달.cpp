#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct P{
    int dest, cost;
    bool operator < (const P &p) const {return cost > p.cost;}
};


int dijkstra(vector<vector<P>> &p, int N, int K){
    priority_queue<P>pq;
    int ret = 0;
    int d[51];
    for(int i=0;i<N;i++)d[i]=0x3f3f3f3f;
    d[0] = 0;
    pq.push({0,0});
    while(!pq.empty()){
        int now = pq.top().dest;
        int cost = pq.top().cost;
        pq.pop();
        if(d[now] < cost)continue;
        for(auto x:p[now]){
            int next = x.dest;
            int cost = x.cost;
            if(d[now] + cost < d[next]){
                d[next] = d[now] + cost;
                pq.push({d[next],next});
            }
        }
    }
    for(int i=0;i<N;i++)ret+=(d[i]<=K);
    return ret;
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<P>>p;
    p.resize(N);

    for(auto x:road){
        int s = x[0]-1;
        int e = x[1]-1;
        int c = x[2];
        p[s].push_back({e,c});
        p[e].push_back({s,c});
    }

    answer=dijkstra(p,N,K);

    return answer;
}