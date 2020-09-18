#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct P{
    string head,number,ori;
    int idx;
};

int headcmp(string a, string b){
    for(auto &c:a)if(c>='A' && c<='Z') c += ('a'-'A');
    for(auto &c:b)if(c>='A' && c<='Z') c += ('a'-'A');
    for(int i=0;i<min(a.size(),b.size());i++){
        if(a[i]!=b[i])return a[i]<b[i];
    }
    if(a.size()==b.size())return -1;
    return a.size() < b.size();
}

int numbercmp(string a, string b){
    int na=0,nb=0;
    for(auto c:a){
        na*=10;
        na+=(c-'0');
    }
    for(auto c:b){
        nb*=10;
        nb+=(c-'0');
    }
    if(na==nb)return -1;
    return na < nb;
}

bool cmp(const P &a, const P &b){
    int headFlag = headcmp(a.head,b.head);
    if(headFlag != -1)return (bool)headFlag;
    int numberFlag = numbercmp(a.number,b.number);
    if(numberFlag != -1)return (bool)numberFlag;
    return a.idx < b.idx;
}

vector<string> solution(vector<string> files){
    vector<P> p;
    for(int i=0;i<files.size();i++){
        string head = "", number = "";
        bool hf = false, nf = false;
        for(auto c:files[i]){
            if(c>='0' && c<='9'){
                if(!nf)number+=c;
                hf = true;
            }else{
                if(!hf)head+=c;
                else nf = true;
            } 
        }
        p.push_back({head,number.substr(0,min((int)number.size(),5)),files[i],i});
    }
    sort(p.begin(),p.end(),cmp);
    vector<string>ret;
    for(auto x:p)ret.push_back(x.ori);
    return ret;
}

int main(){
    vector<string> f =  {"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};
    solution(f);
}