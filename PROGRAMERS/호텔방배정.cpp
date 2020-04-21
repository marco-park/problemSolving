#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#define ll long long

using namespace std;

map<ll,ll>m;

ll find(ll x){
    if(!m[x])return x;
    return m[x] = find(m[x]);
}

void merge(ll a, ll b){
    a = find(a);
    b = find(b);
    if(a==b)return;
    if(a>b)m[b] = a;
    else m[a] = b;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for(auto x:room_number){
        ll target = find(x);
        answer.push_back(target);
        merge(x,target+1);
    }
    return answer;
}