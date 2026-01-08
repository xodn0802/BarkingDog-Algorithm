#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int max = 0;
    int idx;
    for(int i = 0; i < 9; i++){
        cin >> n;
        if(n > max){
            max = n;
            idx = i;
        }
    }
    cout << max << '\n' << idx + 1;
    return 0;
}