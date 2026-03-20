#include <bits/stdc++.h>
using namespace std;

set<string> st;
string s;
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        string cur;
        for(int j = i; j < s.size(); j++){
            cur += s[j];
            st.insert(cur);
        }
    }
    cout << st.size();
    return 0;
}