#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;

bool cmp(pair<int,int>&a, pair<int,int>&b){
    if(a.first==b.first)return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    int size = genres.size();
    map<string,int>m_genre;
    set<string>s_genre;
    for(int i=0;i<size;i++)m_genre[genres[i]]+=plays[i];
    for(auto x:genres)s_genre.insert(x);
    vector<int>genres_i;
    for(auto x:s_genre)genres_i.push_back(m_genre[x]);
    sort(genres_i.begin(),genres_i.end());
    reverse(genres_i.begin(),genres_i.end());
    vector<string>sorted_g;

    for(int i=0;i<genres_i.size();i++){
        for(auto x:s_genre){
            if(m_genre[x]==genres_i[i])sorted_g.push_back(x);
        }
    }
    map<string,vector<pair<int,int>>>m;
    for(int i=0;i<size;i++){
        m[genres[i]].push_back({plays[i],i});
    }
    for(auto x:s_genre)sort(m[x].begin(),m[x].end(),cmp);
    vector<int> answer;

    for(auto x:sorted_g){
        int cnt = 0;
        for(auto y:m[x]){
            answer.push_back(y.second);
            if(++cnt==2)break;
        }
    }
    return answer;
}