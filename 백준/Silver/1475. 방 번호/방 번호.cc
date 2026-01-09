#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int arr[10] = {};
    while(N > 0){
        arr[N % 10]++;
        N /= 10;
    }
    int mix = (arr[6] + arr[9] + 1) / 2;
    arr[6] = 0;
    arr[9] = mix;
    int max = -1;
    for(int i = 0; i < 10; i++){
        
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout << max;

    return 0;
}