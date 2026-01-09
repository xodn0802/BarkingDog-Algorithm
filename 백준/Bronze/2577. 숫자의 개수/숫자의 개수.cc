#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10] = {};
    string N;
    int a,b,c;
    cin >> a >> b >> c;
    N = to_string(a * b * c);
    for(int i = 0; i < N.size(); i++){
        arr[N[i] - '0']++;
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << '\n';
    }

    return 0;
}