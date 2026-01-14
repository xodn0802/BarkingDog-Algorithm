#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    int arr[n];
    stack<int> s;
    // [수정 1] 결과를 바로 출력하면 안 되고 모아둬야 해서 만든 배열(벡터)
    vector<char> result; 

    for(int i = 0; i < n; i++){
        cin >> m;
        arr[i] = m;
    }

    // [수정 2] 시간 초과의 원인이었던 2중 for문(O(N^2)) 삭제함
    // 스택 시뮬레이션만으로도 불가능 여부를 알 수 있음!

    int a = 1;
    for(int i = 0; i < n; i++){
        while(true){
            if(!s.empty() && s.top() == arr[i]){
                result.push_back('-'); // [수정 1] cout 대신 result에 저장
                s.pop();
                break;
            }
            else{
                // [수정 3] 핵심! 스택 top이 목표값이 아니라서 숫자를 더 넣어야 하는데,
                // 넣을 숫자(a)가 n보다 크다면? 더 이상 방법이 없음 -> 불가능(NO)
                if(a > n) {
                    cout << "NO";
                    return 0;
                }
                result.push_back('+'); // [수정 1] cout 대신 result에 저장
                s.push(a);
                a++;
            }
        }
    }

    // 모아둔 결과 한 번에 출력
    for(char c : result){
        cout << c << '\n';
    }

    return 0;
}