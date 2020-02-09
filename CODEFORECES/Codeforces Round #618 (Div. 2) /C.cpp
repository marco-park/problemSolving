#include <iostream>

using namespace std;

int a[100001],d[32];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*  (x | y) - y => x & ~y   */

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        for(int j=31;j>=0;j--){
            if((1<<j)&a[i])d[j]++;
        }
    }
    int ret = -1;
    for(int j=31;j>=0;j--){
        if(d[j]==1){
            for(int i=0;i<n;i++){
                if((1<<j)&a[i]){
                    cout << a[i] << ' ';
                    ret = i;
                    break;
                }
            }
        }
        if(ret!=-1)break;
    }
    for(int i=0;i<n;i++){
        if(ret==i)continue;
        cout << a[i] << ' ';
    }
}