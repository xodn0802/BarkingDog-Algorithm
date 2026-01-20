#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int fire_dist[1002][1002];
int jh_dist[1002][1002];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    for(int i = 0; i < n; i++) fill(fire_dist[i],fire_dist[i] + m, -1);
    for(int i = 0; i < n; i++) fill(jh_dist[i], jh_dist[i] + m, -1);
    queue<pair<int,int>> FQ;
    queue<pair<int,int>> JQ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'F'){
                fire_dist[i][j] = 0;
                FQ.push({i,j});
            }
            if(board[i][j] == 'J'){
                jh_dist[i][j] = 0;
                JQ.push({i,j});
            }
        }
    }
    while(!FQ.empty()){
        auto cur = FQ.front(); FQ.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(fire_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            fire_dist[nx][ny] = fire_dist[cur.X][cur.Y] + 1;
            FQ.push({nx,ny});
        }
    }
    while(!JQ.empty()){
        auto cur = JQ.front(); JQ.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                cout << jh_dist[cur.X][cur.Y] + 1;
                return 0;
            }
            if(jh_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(fire_dist[nx][ny] != -1 && fire_dist[nx][ny] <= jh_dist[cur.X][cur.Y] + 1) continue;
            jh_dist[nx][ny] = jh_dist[cur.X][cur.Y] + 1;
            JQ.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";

    
    
    

    return 0;
}