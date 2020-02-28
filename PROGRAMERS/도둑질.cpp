#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int d[1000000][2];

int foo(int idx,int flag,vector<int> &money,int size){
    if(idx+1 == size)return 0;
    int &ret = d[idx][flag];
    if(ret!=-1)return ret;
    if(flag) ret = foo(idx+1,false,money,size);
    else ret = max(foo(idx+1,0,money,size),foo(idx+1,1,money,size)+money[idx+1]);
    return ret;
}

int solution(vector<int> money) {
    int answer = 0;
    memset(d,-1,sizeof(d));
    int size = money.size();
    answer = foo(0,0,money,money.size());
    memset(d,-1,sizeof(d));
    answer = max(answer,foo(0,1,money,money.size()-1)+money[0]);

    return answer;
}