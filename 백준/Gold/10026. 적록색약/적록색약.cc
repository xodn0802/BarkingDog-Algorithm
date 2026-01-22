#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[102];
int vis[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, r_cnt, g_cnt, b_cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'R' && vis[i][j] == 0){
                queue<pair<int,int>> RQ;
                vis[i][j] = 1;
                RQ.push({i,j});
                while(!RQ.empty()){
                    auto cur = RQ.front(); RQ.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(board[nx][ny] != 'R' || vis[nx][ny] != 0) continue;
                        RQ.push({nx,ny});
                        vis[nx][ny] = 1;
                        
                    }
                }
                r_cnt++;
            }
            else if(board[i][j] == 'G' && vis[i][j] == 0){
                queue<pair<int,int>> GQ;
                vis[i][j] = 1;
                GQ.push({i,j});
                while(!GQ.empty()){
                    auto cur = GQ.front(); GQ.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(board[nx][ny] != 'G' || vis[nx][ny] != 0) continue;
                        GQ.push({nx,ny});
                        vis[nx][ny] = 1;
                        
                    }
                }
                g_cnt++;
            }
            else if(board[i][j] == 'B' && vis[i][j] == 0){
                queue<pair<int,int>> BQ;
                vis[i][j] = 1;
                BQ.push({i,j});
                while(!BQ.empty()){
                    auto cur = BQ.front(); BQ.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(board[nx][ny] != 'B' || vis[nx][ny] != 0) continue;
                        BQ.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
                b_cnt++;
            }
        }
    }
    int ans = r_cnt + b_cnt + g_cnt;
    cout << ans << '\n';
    int cnt = 0;
    for(int i = 0; i < n; i++) fill(vis[i],vis[i]+n,0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            if((board[i][j] == 'R' || board[i][j] == 'G') && vis[i][j] == 0){
                queue<pair<int,int>> Q;
                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(board[nx][ny] == 'B') continue;
                        if(vis[nx][ny] == 1) continue;
                        Q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
                cnt++;
            }
            
        }
    }
    int ans2 = b_cnt + cnt;
    cout << ans2;

    
        
    return 0;
}