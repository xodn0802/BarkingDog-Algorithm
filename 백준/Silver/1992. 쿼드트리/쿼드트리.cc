#include <bits/stdc++.h>
using namespace std;

int N;
int paper[128][128];

void func(int r, int c, int n){
    int initail = paper[r][c];
    bool same = true;
    for(int i = r; i < r + n; i++){
        for(int j = c; j < c + n; j++){
            if(initail != paper[i][j]){
                same = false;
                break;
            }
        }
        if(!same) break;
    }
    if(same){
        cout << initail;
        return;
    }
    int m = n / 2;
    cout << '(';
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            func(r + i*m, c + j*m, m);
        }
    }
    cout << ')';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++){
            paper[i][j] = s[j] - '0';
        }
    }
    func(0,0,N);

    
    return 0;
}