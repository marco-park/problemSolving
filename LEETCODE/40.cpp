#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    set<vector<int>> sret;
    void foo(vector<int>& candidates, int idx, int sum, int target, vector<int> &p){
        if(sum==target){
            sret.insert(p);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(sum+candidates[i] <= target){
                p.push_back(candidates[i]);
                foo(candidates, i+1, sum+candidates[i],target,p);
                p.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> p;
        sort(candidates.begin(),candidates.end());
        foo(candidates,0,0,target,p);
        for(auto x:sret)ret.push_back(x);
        return ret;
    }
};