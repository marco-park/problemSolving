#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> snum;
stack<char> sop;

bool isNum(char c){
    return c>='0' && c<='9';
}

int bar(string);
void cal();
int ret = -0x3f3f3f3f;

void foo(string s, int idx){
    for(int i=idx;i<s.size()-2;i++){
        if(isNum(s[i])) 
            foo(s.substr(0,i)+"("+s.substr(i,3)+")"+s.substr(i+3),i+5);
    }
    ret = max(ret,bar(s));
}

int bar(string s){
    for(auto c:s){
        if(isNum(c))snum.push(c-'0');
        else if(c=='('){
            sop.push('(');
        }else if(c==')'){
            while(sop.top()!='(')cal();
            sop.pop();
        }else{
            while(!sop.empty() && sop.top()!='(')cal();
            sop.push(c);
        }
    } 
    while(!sop.empty())cal();
    int ret = snum.top();
    snum.pop();
    return ret;
}

void cal(){
    int a = snum.top();
    snum.pop();
    int b = snum.top();
    snum.pop();
    char op = sop.top();
    sop.pop();
    switch (op){
        case '+' : snum.push(b+a); break;
        case '-' : snum.push(b-a); break;
        case '*' : snum.push(b*a); break;
        default : break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    cin >> n >> s;
    if(n==1){
        cout << s << '\n';
        return 0;
    }
    foo(s,0);
    cout << ret << '\n';
}
