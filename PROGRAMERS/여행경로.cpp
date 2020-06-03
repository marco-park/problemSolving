#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<pair<string,string>,int>visited;
vector<string> answer;
int ticketSize;

bool foo(string now,map<string,vector<string>>&p){
    if(answer.size() == ticketSize+1)return true;
    for(auto next:p[now]){
        if(!visited[{now,next}])continue;
        visited[{now,next}]--;
        answer.push_back(next);
        if(foo(next,p))return true;
        visited[{now,next}]++;
        answer.pop_back();
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    ticketSize = tickets.size();
    map<string,vector<string>>p;
    for(auto x:tickets){
        p[x[0]].push_back(x[1]);
        visited[{x[0],x[1]}]++;
    }
    for(auto x:p)sort(p[x.first].begin(),p[x.first].end());
    string start = "ICN";
    answer.push_back(start);
    foo(start,p);
    return answer;
}