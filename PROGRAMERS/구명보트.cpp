#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end());
    int j = people.size()-1;
    int answer = 0;

    for(int i=0;i<=j;i++){
        int x = j;
        while(x > i && people[x] > (limit - people[i]))x--;  //탈 수 있을 때까지
        answer += (j - x)+1;
        j = x-1;
    }
    return answer;
}