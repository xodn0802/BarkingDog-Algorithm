#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second


int dist[52][52];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int m,n,k,t,x,y;
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> m >> n >> k;
        ans = 0;
        int board[52][52] = {};
        for(int j = 0; j < k; j++){
            cin >> x >> y;
            board[y][x] = 1;
        }
        for(int j = 0; j < n; j++) fill(dist[j],dist[j] + m, -1);
        for(int j = 0; j < n; j++){
            for(int l = 0; l < m; l++){
                if(board[j][l] == 1 && dist[j][l] == -1){
                    dist[j][l] = 0;
                    queue<pair<int,int>> Q;
                    Q.push({j,l});
                    int cnt = 0;
                    while(!Q.empty()){
                        auto cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if(dist[nx][ny] >= 0) continue;
                            if(board[nx][ny] != 1) continue;
                            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                            Q.push({nx,ny});
                        }
                    }
                    ans++;
                    
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}