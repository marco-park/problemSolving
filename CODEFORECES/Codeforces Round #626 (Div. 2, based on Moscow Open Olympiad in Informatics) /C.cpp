#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>

using namespace std;

int a[2];

int foo(string s){
    stack<char>st;
    for(auto c:s){
        if(st.empty()){
            if(c==')')return s.size();
            st.push(c);
        }else{
            auto top = st.top();
            if(top==c){
                st.push(c);
            }else st.pop();
        }
    }
    if(st.empty())return 0;
    else return s.size();
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    int n;
    cin >> n;
    vector<int>p;
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
        if(s[i]=='(')a[0]++;
        else a[1]++;
        if(a[0] == a[1]){
            p.push_back(i);
        }
    }
    if(p.size()==0||s.size()%2 || a[0]!=a[1]){
        cout << -1 << '\n';
        return 0;
    }
    int last = 0;
    int ret = 0;
    for(auto x:p){
        if(!last)ret+=foo(s.substr(last,x+1));
        else ret+=foo(s.substr(last+1,x-last));
        last = x;
    }
    cout << ret << '\n';
}