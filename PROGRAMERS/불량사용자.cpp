#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,bool>m;
bool check[(1<<8)];
vector<int>p;

bool cmp(string a,string b){
    if(a.size()!=b.size())return false;
    for(int i=0;i<a.size();i++){
        if(b[i]=='*')continue;
        if(a[i]!=b[i])return false;
    }
    return true;
}

int foo(vector<string> user_id, vector<string> banned_id,int idx,int cnt){
    int ret = 0;
    if(p.size()==banned_id.size()){
        int x = 0;
        for(int i:p)x+=(1<<i);
        if(!check[x]){
            check[x] = true;
            return 1;
        }else return 0;
    }
    for(int i=idx;i<banned_id.size();i++){
        for(int j=0;j<user_id.size();j++){
            if(!cmp(user_id[j],banned_id[i]))continue;
            
            if(!m.count(user_id[j]) || !m[user_id[j]]){
                p.push_back(j);
                m[user_id[j]] = true;
                ret+=foo(user_id,banned_id,i+1,cnt+1);
                p.pop_back();
                m[user_id[j]] = false;
            }
        }
    }   
    return ret; 
}

int solution(vector<string> user_id, vector<string> banned_id) {
    return foo(user_id,banned_id,0,0);
}