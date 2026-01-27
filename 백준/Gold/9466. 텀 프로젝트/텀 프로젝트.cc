#include <bits/stdc++.h>
using namespace std;
#define X first

int pick[100002];
int cnt[100002];
int t,n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        fill(cnt,cnt + n + 1, 0);
        int ans = 0;
        queue<int> Q;
        for(int i = 1; i <= n; i++){
            cin >> m;
            pick[i] = m;
            cnt[m]++;
        }
        for(int i = 1; i <= n; i++){
            if(cnt[i] == 0) Q.push(i);
        }
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            int nxt = pick[cur];
            cnt[nxt]--;
            if(cnt[nxt] == 0){
                Q.push(nxt);
            }
        }
        for(int i = 1; i <= n; i++){
            if(cnt[i] == 0) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}