#include <string>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> map, vector<int> moves) {
    int n = map.size();
    int ret = 0;
    stack<int>st;

    for(int x:moves){
        int i = 0, j = x-1;
        while(!map[i][j] && i<n-1)i++;
        int next = map[i][j];
        if(!next)continue;
        map[i][j] = 0;
        if(st.empty())st.push(next);
        else if(next == st.top()){
            ret+=2;
            st.pop();
        }else st.push(next);
    }
    return ret;
}   