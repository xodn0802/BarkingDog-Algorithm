#include <bits/stdc++.h>
using namespace std;

set<string> st;
string s,c;
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        st.insert(s);
    }
    for(int i = 0; i < N-1; i++){
        cin >> c;
        if(st.find(c) != st.end()){
            st.erase(c);
        }
    }
    cout << *st.begin();
    return 0;
}