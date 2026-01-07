#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[7];
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < 7; i++){
        int x;
        cin >> x;
        if(x % 2 != 0){
            sum += x;
            arr[cnt] = x;
            cnt++;
        }
    }
    if(cnt == 0){
        cout << -1;
    }else{
        sort(arr, arr+cnt);
        cout << sum << '\n';
        cout << arr[0];
    }
    return 0;
}