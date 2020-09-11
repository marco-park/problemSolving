#include <string>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

bool cmp(pair<int,int>a, pair<int,int>b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    vector<pair<int,int>> p;
    for(int i=0;i<food_times.size();i++)
        p.push_back({food_times[i],i+1});
    
    sort(p.begin(),p.end());
    int n = p.size();
    for(int i=0;i<p.size();i++){
        ll x = (ll)(p[i].first-(i?p[i-1].first:0)) * (n-i);
        if(k-x<0){
            sort(p.begin()+i,p.end(),cmp);
            return p[i+(k % (n-i))].second;
        }else k-=x;
    }
    return -1;
}