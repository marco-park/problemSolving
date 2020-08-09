#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    void foo(vector<int>& candidates, int idx, int sum, int target, vector<int> &p){
        if(sum==target){
            ret.push_back(p);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(sum+candidates[i] <= target){
                p.push_back(candidates[i]);
                foo(candidates, i, sum+candidates[i],target,p);
                p.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> p;
        foo(candidates,0,0,target,p);
        return ret;
    }
};