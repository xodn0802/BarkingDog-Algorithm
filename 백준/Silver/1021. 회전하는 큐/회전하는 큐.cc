#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> DQ;
    int n,m,a;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        DQ.push_back(i);
    }
    vector<int> v(m);
    for(int i = 0; i < m; i++){
        cin >> v[i];
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        int target = v[i];
        
        int idx = 0;
        for(int j = 0; j < DQ.size(); j++){
            if(DQ[j] == target){
                idx = j;
                break;
            }
        }
        if(idx <= DQ.size() - idx){
            while(DQ.front() != target){
                DQ.push_back(DQ.front());
                DQ.pop_front();
                ans++;
            }
        }else{
            while(DQ.front() != target){
                DQ.push_front(DQ.back());
                DQ.pop_back();
                ans++;
            }
        }
        DQ.pop_front();

    }
    cout << ans;


    return 0;
}