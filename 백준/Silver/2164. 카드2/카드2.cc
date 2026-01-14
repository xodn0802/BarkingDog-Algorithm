#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> Q;

    for(int i = 1; i <= n; i++){
        Q.push(i);
    }
    while(1){
        if(Q.size() == 1){
            break;
        }
        Q.pop();
        int first = Q.front();
        Q.push(first);
        Q.pop();
    }
    cout << Q.front();

    return 0;
}