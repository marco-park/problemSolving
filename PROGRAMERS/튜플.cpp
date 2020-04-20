#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

bool check[100001];
vector<int>p[501];

vector<int> solution(string s) {
    memset(check,0,sizeof(check));
    int len = 0;
    vector<int>tmp;
    int n = 0;
    for(int i=1;i<s.size()-1;i++){
        if(s[i]=='{'){
            len = 1;
        }else if(s[i]=='}'){
            for(int i=0;i<len;i++){
                p[len].push_back(tmp[i]);
            }
            tmp.clear();
        }else {
            if(s[i]==',')len++;
            else {
                int idx = i;
                int x = 0;
                while(s[idx]!=',' && s[idx]!='}'){
                    x*=10;
                    x+=(s[idx]-'0');
                    idx++;
                }
                n = max(n,len);
                tmp.push_back(x);
                i = idx-1;
            }
        }
    }
    vector<int> answer;
    
    for(int i=1;i<=n;i++){
        for(int x:p[i]){
            if(!check[x]){
                check[x]=true;
                answer.push_back(x);
            }
        }
    }
    return answer;
}