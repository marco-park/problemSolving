#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

struct Page{
    string html = "", origin = "";
    double baseScore=0,externLink=0,totalScore=0;
    int idx;
};

bool cmpPage(Page &a, Page &b){
    if(a.totalScore == b.totalScore) return a.idx < b.idx;
    return a.totalScore > b.totalScore;
}

map<string,vector<string>> m;
map<string,int>ridx;

bool cmp(string a, string b){
    if(a.size()!=b.size())return false;
    
    for(int i=0;i<a.size();i++){
        if(!(
            (a[i]>='a' && a[i]<='z') ||
            (a[i]>='A' && a[i]<='Z')
        ))return false;
        
        if(!(
            (abs('a' - 'A') == abs(a[i]-b[i])) || 
            (a[i] == b[i])
        ))return false;
    }
    return true;
}

int solution(string word, vector<string> pages) {
    Page p[20];
    int idx = 0, size = pages.size();
    string meta = "<meta property=";
    string https = "https://";
    string href = "a href=\"";

    for(int i=0;i<size;i++){
        p[i].idx = i;

        //match word
        for(int j=0;j<pages[i].size()-word.size();j++){
            if(
                j &&
                !(
                    (pages[i][j-1] >= 'a' && pages[i][j-1] <= 'z') ||
                    (pages[i][j-1] >= 'A' && pages[i][j-1] <= 'Z')
                   
                ) &&
                j+word.size() < pages[i].size() &&
                !(
                    (pages[i][j+word.size()] >= 'a' && pages[i][j+word.size()] <= 'z') ||
                    (pages[i][j+word.size()] >= 'A' && pages[i][j+word.size()] <= 'Z') 
                ) &&
                cmp(pages[i].substr(j,word.size()),word)
                ){
                    p[i].baseScore+=1.0;
                } 
        }
            
        for(int j=0;j<pages[i].size();j++){

            //origin url
            if(pages[i].substr(j,meta.size()) == meta) {
                string origin = "";
                bool flag = false;
                for(int k=j+meta.size();;k++){
                    if(pages[i].substr(k,https.size())==https)flag = true;
                    if(flag && pages[i][k] == '\"') break;
                    if(flag)origin += pages[i][k];
                }
                p[i].origin = origin;
                ridx[origin] = i;
            }

            //external url
            if(pages[i].substr(j,href.size()) == href) {
                p[i].externLink+=1.0;
                string link = "";
                for(int k=j+href.size();;k++){
                    if(pages[i][k] == '\"')break;
                    link += pages[i][k];
                }
                m[link].push_back(p[i].origin);
            }
        }
    }

    for(int i=0;i<size;i++){
        p[i].totalScore += p[i].baseScore;
        for(auto x:m[p[i].origin]){
            auto y = ridx[x];
            p[i].totalScore += (p[y].baseScore / max(p[y].externLink,1.0));
        }
    }

    sort(p,p+size,cmpPage);
    int answer = p[0].idx;
    return answer;
}