#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(vector<int> stones, int target,int k){
    int ret = 0;
    int tmp = 0;
    for(auto x:stones){
        if(x-target>0)tmp = 0;
        else tmp++;
        ret = max(ret,tmp);
    }
    return ret>=k;
}

int solution(vector<int> stones, int k) {
    int l = 1;
    int r = 2*1e9;

    while(l+1<r){
        int m = (l+r)/2;
        if(cmp(stones,m,k))r = m;
        else l = m;
    }
    return r;
}