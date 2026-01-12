#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int M;
    char o, a;
    list<char> L;
    for(int i = 0; i < s.size(); i++){
        L.push_back(s[i]);
    }
    list<char>::iterator c = L.end();
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> o;
        if(o == 'L'){
            if(c == L.begin()) continue;
            c--;
        }else if(o == 'D'){
            if(c == L.end()) continue;
            c++;
        }else if(o == 'B'){
            if(c == L.begin()) continue;
            c--;
            c = L.erase(c);
        }else if(o == 'P'){
            cin >> a;
            L.insert(c,a);
        }
    }

    for(auto i : L){
        cout << i;
    }


    return 0;
}