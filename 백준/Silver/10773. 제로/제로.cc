#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K, n;
    cin >> K;
    stack<int> s;
    int sum = 0;

    for(int i = 0; i < K; i++){
        cin >> n;
        if(n == 0){
            s.pop();
        }
        else{
            s.push(n);
        }
    }
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }

    cout << sum;

    return 0;
}