#include <bits/stdc++.h>
using namespace std;

int paper[200][200];
int N;
int result[2];

void sol(int r, int c, int n){
    bool state = true;
    int initial = paper[r][c];
    for(int i = r; i < r + n; i++){
        for(int j = c; j < c + n; j++){
            if(initial != paper[i][j]){
                state = false;
                break;
            }
        }
        if(!state){
            break;
        }
    }
    if(state){
        result[initial]++;
        return;
    }
    int m = n / 2;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            sol(r + i*m, c + j*m,m);
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
    sol(0,0,N);

    cout << result[0] << '\n' << result[1];




    return 0;
}