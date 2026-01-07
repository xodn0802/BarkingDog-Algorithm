#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    int sum = 0;
    int arr[9];
    for(int i = 0; i < 9; i++){
        cin >> x;
        sum += x;
        arr[i] = x;
    }
    for(int i = 0; i < 8; i++){
        for(int j = i + 1; j < 9; j++){
            if(arr[i] + arr[j] == (sum - 100)){
                arr[i] = 0;
                arr[j] = 0;
                sort(arr,arr+9);
                for(int i = 2; i < 9; i++){
                    cout << arr[i] << '\n';
                }
                return 0;
            }
        }
    }
    return 0;
}