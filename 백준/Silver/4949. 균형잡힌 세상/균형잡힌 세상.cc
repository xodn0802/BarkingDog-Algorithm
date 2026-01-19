#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(1){
        getline(cin,s);
        if(s == "."){
            break;
        }
        stack<char> st;
        bool isBalance = true;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                if(st.empty() || st.top() != '('){
                    isBalance = false;
                    break;
                }
                st.pop();
            }else if(s[i] == ']'){
                if(st.empty() || st.top() != '['){
                    isBalance = false;
                    break;
                }
                st.pop();
            }
        }
        if(isBalance && st.empty()){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }

    return 0;
}