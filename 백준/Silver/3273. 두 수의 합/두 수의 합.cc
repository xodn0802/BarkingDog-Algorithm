#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int occur[2000001] = {};
    int n, x, a;
    int cnt = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> a;
        arr[i] = a;
    }
    cin >> x;

    for(int i = 0; i < n; i++){
        
        if((x - arr[i]) > 0 && occur[x - arr[i]]){
            cnt++;
        }
        occur[arr[i]]++;
    }

    cout << cnt;


    return 0;
}