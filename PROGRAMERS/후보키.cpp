#include <string>
#include <vector>
#include <set>

using namespace std;

bool check[512];
int N;

bool foo(int idx,vector<vector<string>> relation){
    for(int i=1;i<idx;i++){
        if(!check[i])continue;
        if((i & idx) == i)return false;
    }

    vector<string>t;
    vector<int>p(N,0);
    set<string>st;
    int i = 0;
    while(idx){
        p[i++] = idx%2;
        idx/=2;
    }

    for(int i=0;i<relation.size();i++){
        string tmp = "";
        for(int j=0;j<N;j++)if(p[j])tmp+=relation[i][j];
        t.push_back(tmp);
        st.insert(tmp);
    }
    return t.size()==st.size();
}

int solution(vector<vector<string>> relation) {
    N = relation[0].size();
    int answer = 0;
    for(int i=1;i<(1<<N);i++)answer += check[i] = foo(i,relation);
    return answer;
}