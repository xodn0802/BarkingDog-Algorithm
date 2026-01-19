#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        stack<char> st;
        
        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'A'){
                if(st.empty()){
                    st.push(s[j]);
                }else if(st.top() == 'B'){
                    st.push(s[j]);
                }else{
                    st.pop();
                }
            }else if(s[j] == 'B'){
                if(st.empty()){
                    st.push(s[j]);
                }else if(st.top() == 'A'){
                    st.push(s[j]);
                }else{
                    st.pop();
                }
            }
        }
        if(st.empty()) cnt++;
    }
    cout << cnt;

    return 0;
}