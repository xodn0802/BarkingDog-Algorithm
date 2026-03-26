#include <bits/stdc++.h>
using namespace std;

int N;
int paper[2200][2200];
int result[3];


void solv(int r, int c, int n){
    //현재 영역이 전부 같은 숫자인지 판별해라.
    bool same = true;
    int initial = paper[r][c];
    for(int i = r; i < r + n; i++){
        for(int j = c; j < n + c; j++){
            if(initial == paper[i][j]) continue;
            else{
                same = false;
                break;
            }
        }
        if(!same) break;
    }
    if(same){
        result[initial + 1]++;
        return;
    }
    int m = n/3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            solv(r + i * m, c + j * m, m);
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> paper[i][j];
        }
    }
    solv(0,0,N);

    cout << result[0] << "\n" << result[1] << '\n' << result[2];

    return 0;
}