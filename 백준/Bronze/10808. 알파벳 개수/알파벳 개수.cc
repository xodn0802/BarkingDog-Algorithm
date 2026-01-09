#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[26];
    fill(arr,arr+26,0);
    string N;
    cin >> N;
    for(int i = 0; i < N.size(); i++){
        if(N[i] >= 'a' && N[i] <= 'z'){
            arr[N[i] - 'a']++;
        }
    }
    for(int i = 0; i < 26; i++){
        cout << arr[i] << " ";
    }

    return 0;
}