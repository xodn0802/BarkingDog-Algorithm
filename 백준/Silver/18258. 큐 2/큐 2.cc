#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;

    cin >> n;
    queue<int> Q;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "push"){
            int k;
            cin >> k;
            Q.push(k);
        }else if(s == "pop"){
            if(Q.empty()){
                cout << -1 << '\n';
            }else{
                cout << Q.front() << '\n';
                Q.pop();
            }
        }else if(s == "size"){
            cout << Q.size() << '\n';
        }else if(s == "empty"){
            if(Q.empty()){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
        }else if(s == "front"){
            if(Q.empty()){
                cout << -1 << '\n';
            }else{
                cout << Q.front() << '\n';
            }
        }else{
            if(Q.empty()){
                cout << -1 << '\n';
            }else{
                cout << Q.back() << '\n';
            }
        }
    }

    return 0;
}