#include <bits/stdc++.h>
using namespace std;

map<string,string> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    string s1,s2,c;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s1 >> s2;
        mp[s1] = s2;
    }
    for(int i = 0; i < M; i++){
        cin >> c;
        cout << mp[c] << '\n';
    }
    return 0;
}