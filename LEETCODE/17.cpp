#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string num[10];
    vector<string> ret;
    Solution(){
        char c = 'a';
        for(int i=2;i<10;i++){
            num[i] = "";
            for(int j=0;j<(i==7||i==9)?4:3;j++)num[i]+=string(1,c++);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")return ret;
        foo(0,"",digits);
        return ret;
    }

    void foo(int idx,string s,string digits){
        if(idx==digits.size()){
            ret.push_back(s);
            return;
        }
        int x = digits[idx] - '0';
        for(int i=0;i<x==7||x==9?4:3;i++){
            foo(idx+1,s+num[x][i],digits);
        }
    }
};
