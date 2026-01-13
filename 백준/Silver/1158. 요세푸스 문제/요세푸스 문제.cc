#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    list<int> L;
    for(int i = 1; i <= N; i++){
        L.push_back(i);
    }
    list<int>::iterator it = L.begin();
    cout << "<";
    while(!L.empty()){
        for(int i = 0; i < K - 1; i++){
            it++;
            if(it == L.end()){
                it = L.begin();
            }
        }
        cout << *it;
        it = L.erase(it);
        if(!L.empty()){
            cout << ", ";
            if(it == L.end()){
                it = L.begin();
            }
        }
    }
    cout << ">";

    return 0;
}