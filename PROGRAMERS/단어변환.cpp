#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

bool cmp(string a,string b){
    int ret = 0;
    for(int i=0;a[i];i++)
        if(a[i]!=b[i])ret++;
    return ret==1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    map<string,int>m;
    queue<string>q;
    q.push(begin);
    m[begin] = 0;
    while(!q.empty()){
        string now = q.front();
        if(now==target)break;
        q.pop();
        for(auto next:words){
            if(!m.count(next) && cmp(now,next)){
                q.push(next);
                m[next] = m[now]+1;
            }
        }
    }
    answer = m[target];
    return answer;
}