#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int dist[1002][1002][2];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int m,n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int p = 0;
    int q = 0;
    int ans = 0;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    queue<tuple<int,int,int>> Q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dist[i][j][0] = dist[i][j][1] = -1;
        }
    }
    dist[0][0][0] = dist[0][0][1] = 0;
    Q.push({0,0,0});
    while(!Q.empty()){
        auto [x,y,broken] = Q.front(); Q.pop();
        if(x == n-1 && y == m-1){
            cout << dist[x][y][broken] + 1;
            return 0;
        }
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1){
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                Q.push({nx,ny,broken});
            }
            if(board[nx][ny] == '1' && broken == 0 && dist[nx][ny][1] == -1){
                dist[nx][ny][1] = dist[x][y][broken] + 1;
                Q.push({nx,ny,1});
            }
        }
    }
    cout << -1;

    return 0;
}