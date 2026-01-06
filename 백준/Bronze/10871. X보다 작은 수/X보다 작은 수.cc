#include <iostream>
using namespace std;

int main(){
    int N, X;
    cin >> N >> X;
    for(int i = 0; i < N; i++){
        int k;
        cin >> k;
        if(k < X){
            cout << k << " ";
        } 
    }
    return 0;
}