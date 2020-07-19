#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int>&a, pair<int,int>&b){
    if((a.second - a.first) == (b.second - b.first))return a.first < b.first;
    return (a.second - a.first) < (b.second - b.first);
}

vector<int> solution(vector<string> gems) {
    map<string,int> m;
    for(auto & g: gems)m[g]=0;

    int size = m.size();
    int n = gems.size();
    int l=0,r=0;
    vector<pair<int,int>>ret;

    int cnt = 0;
    
    while(1){
        if(cnt == size) cnt -= (--m[gems[l++]] == 0);   
        else if(r==n) break;   
        else cnt += (m[gems[r++]]++ == 0);  
        
        if(cnt == size)ret.push_back({l+1,r});  
    }

    sort(ret.begin(),ret.end(),cmp);
    vector<int> answer = {ret[0].first,ret[0].second};
    return answer;
}