#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string s;
        cin >> s;
        stack<char> st;
        bool isBalance = true;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '('){
                st.push(s[j]);
            }else if(s[j] == ')'){
                if(st.empty()){
                    isBalance = false;
                    break;
                }
                st.pop();
            }
        }
        if(st.empty() && isBalance == true){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}