#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int cnt[1000];

int solution(string s) {
    int answer = s.size();
    for(int i=1;i<=s.size()/2;i++){
        memset(cnt,0,sizeof(cnt));
        int idx = 0, tmp = 0;
        string last = "";
        for(int j=0;j<s.size();j+=i){
            string now = s.substr(j,i);
            if(now==last)cnt[idx]++;
            else idx++,tmp+=now.size();
            last = now;
        }
        for(int k=0;k<=idx;k++)
            if(cnt[k])tmp+=((to_string(cnt[k]+1).size()));
        
        answer = min(answer,tmp);
    }
    return answer;
}