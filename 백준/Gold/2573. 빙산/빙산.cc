#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[303][303];
int vis[303][303];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;
int year = 0;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    while(true){
        int cnt = 0;
        queue<pair<int,int>> Q;
        for(int i = 0; i < 303; i++){
            fill(vis[i],vis[i] + 303, 0);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] > 0 && vis[i][j] == 0){
                    cnt++;
                    vis[i][j] = 1;
                    Q.push({i,j});
                    while(!Q.empty()){
                        auto cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if(vis[nx][ny] == 1) continue;
                            if(board[nx][ny] == 0) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
        if(cnt >= 2){
            cout << year << '\n';
            break;
        }
        if(cnt == 0){
            cout << 0 << '\n';
            break;
        }
        year++;
        int melting_cnt[303][303] = {0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0) continue;
                for(int dir = 0; dir < 4; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] != 0) continue;
                    melting_cnt[i][j]++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] > 0){
                    board[i][j] = max(0,board[i][j] - melting_cnt[i][j]);
                }
            }
        }


    }
    
    return 0;
}