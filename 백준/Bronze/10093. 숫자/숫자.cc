#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;
    
    //long long arr[num];
    if(a > b) swap(a,b);
    if(a == b){
        cout << 0 << '\n';
        return 0;
    }

    long long num = b - a -1;
    long long x = a + 1;

    cout << num << '\n';
    for(long long i = 0; i < num; i++){
        cout << x << " ";
        x++;
    }
    

    return 0;
}