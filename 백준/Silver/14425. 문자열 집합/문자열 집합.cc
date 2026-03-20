#include <iostream>
#include <set>
#include <string>
using namespace std;
set<string> st;


int main(){
    int N,M;
    string s;
    int ans = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s;
        st.insert(s);
    }
    for(int i = 0; i < M; i++){
        cin >> s;
        if(st.find(s) != st.end()){
            ans++;
        }
    }
    cout << ans;
    return 0;
}