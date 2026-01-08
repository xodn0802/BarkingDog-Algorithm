#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n - (i+1); k++){
            cout << " ";
        }
        for(int j = 0; j < (2*i) + 1; j++){
            cout << "*";
        }
        cout << '\n';
    }
    for(int i = 1; i < n; i++){
        for(int k = 0; k < i; k++){
            cout << " ";
        }
        for(int j = 2*n - 1; j > 2*i; j--){
            cout << "*";
        }
        cout << '\n';
    }
    return 0;
}
