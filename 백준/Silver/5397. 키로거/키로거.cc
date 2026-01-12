#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;

    string s;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        list<char> L;
        list<char>::iterator it = L.end();
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '<'){
                if(it != L.begin()) it--;
            }else if(s[j] == '>'){
                if(it != L.end()) it++;
            }else if(s[j] == '-'){
                if(it != L.begin()){
                    it--;
                    it = L.erase(it);
                }
            }else{
                L.insert(it,s[j]);
            }
        }
        for(auto s : L){
            cout << s;
        }
        cout << '\n';
    }


    return 0;
}