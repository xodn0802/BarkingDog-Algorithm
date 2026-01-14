#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n;
    int arr[n];
    stack<int> s;
    vector<char> result;
    for(int i = 0; i < n; i++){
        cin >> m;
        arr[i] = m;
    }
    
    int a = 1;
    for(int i = 0; i < n; i++){
        while(true){
            if(!s.empty() && s.top() == arr[i]){
                result.push_back('-');
                s.pop();
                break;
            }
            else{
                if(a > n){
                    cout << "NO";
                    return 0;
                }
                result.push_back('+');
                s.push(a);
                a++;
            }
        }
        
    }

    for(auto c : result){
        cout << c << '\n';
    }



    return 0;
}